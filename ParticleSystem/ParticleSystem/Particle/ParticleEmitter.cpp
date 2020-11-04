#include "ParticleEmitter.h"
#include "Particle.h"
#include "Module/ParticleComputeModule.h"
#include "../../Math/MathF.h"
#include "../../Utility/Random.h"
#include "../../Utility/EnumOperator.h"
#include "../../Utility/Utility.h"
#include "Module/ShapeModule.h"
#include "../HardwareBuffer/StructuredBuffer.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		/*		
		static float time = 0.f;
		static std::vector<Particle> particles;
		static std::vector<uint32_t> particleIndices;
		static uint32_t particleIndex;
		static std::vector<ParticleEmitterPtr> emitters;

		*/
		ParticleEmitter::ParticleEmitter(const String& name, uint32_t maxCount)
			: base(name)
			, m_time(0.0f)
			, m_duration(0.0f)
			, m_emitCount(0)
			, m_emitCountRange(0)
			, m_emitInterval(0.0f)
			, m_emitIntervalRange(0.0f)
			, m_lifeTime(0.0f)
			, m_lifeTimeRange(0.0f)
			, m_position(Vector3::Zero)
			, m_particleCount(0)
			, m_maxCount(maxCount)
			, m_shape(nullptr)
			, m_active(false)
		{
			m_particles.resize(m_maxCount);

			m_buffer = new StructuredBuffer(true, false);
			m_buffer->SetStride(sizeof(Particle));
			m_buffer->SetCount(maxCount);
			m_buffer->Create();
		}

		ParticleEmitter::~ParticleEmitter()
		{
		}

		ParticleEmitterPtr ParticleEmitter::Create(const String& name, uint32_t maxCount)
		{
			auto emitter = std::make_shared<ParticleEmitter>(name, maxCount);
			
			return emitter;
		}

		void ParticleEmitter::SetLifeTime(float lifeTime)
		{
			m_lifeTime = lifeTime;
		}

		void ParticleEmitter::SetDuration(float duration)
		{
			m_duration = duration;
		}

		void ParticleEmitter::SetEmitCount(int32_t count)
		{
			m_emitCount = count;
		}

		void ParticleEmitter::SetEmitCountRange(int32_t range)
		{
			m_emitCountRange = range;
		}

		void ParticleEmitter::SetLifeTimeRange(float range)
		{
			m_lifeTimeRange = range;
		}

		void ParticleEmitter::SetEmitInterval(float emitInterval)
		{
			m_emitInterval = emitInterval;
		}

		void ParticleEmitter::SetEmitIntervalRange(float range)
		{
			m_emitIntervalRange = range;
		}

		void ParticleEmitter::AddComputeModule(ParticleComputeModulePtr compute)
		{
			m_computes.push_back(std::move(compute));
		}

		void ParticleEmitter::SetShapeModule(ShapeModulePtr shape)
		{
			m_shape = shape;
		}

		void ParticleEmitter::SetPosition(const Vector3& position)
		{
			m_position = position;
		}

		void ParticleEmitter::Start()
		{
			if (m_active)
				return;
			m_active = true;
			m_time = 0.0f;
			for (auto& compute : m_computes)
			{
				compute->Start(m_maxCount);
			}

			m_shape->Start(m_maxCount);
		}

		void ParticleEmitter::Update(float deltaTime)
		{
			m_time += deltaTime;
			// 限界時間に達したら生成しないだけ更新はしないと生き続ける為
			if (m_time < m_duration)
			{
				Emit(deltaTime);
			}
			// 全てのパーティクルが消えたら,生成されなかったら速めのreturn(この処理をemitの前にすると生成されないから上の条件分岐は必須)
			if (m_particleCount == 0)
			{
				m_active = false;
				return;
			}

			for (uint32_t i = 0; i < m_particleCount; ++i)
			{
				auto& particle = m_particles[i];
				particle.lifeTime -= deltaTime;
				if (particle.lifeTime <= 0)
				{
					particle.key.state = ParticleState::Dead;
					DBGSTR("Particleが消えました\n");
					continue;
				}
				else
				{
					for (auto& compute : m_computes)
					{
						compute->Update(particle, deltaTime);
						DBGSTR("particlePosition(%4.4f,%4.4f,%4.4f)\n", particle.position.x, particle.position.y, particle.position.z);
					}
				}
				if (particle.key.state == ParticleState::Born)
				{
					particle.key.state = ParticleState::Alive;
				}
			}

			// ソートする
			Sort();

			m_buffer->Update(m_particles.data());
		}

		bool ParticleEmitter::IsActive() const
		{
			return m_active;
		}

		ParticleEmitter::ShapeModulePtr ParticleEmitter::GetShapeModule() const
		{
			return m_shape;
		}

		uint32_t ParticleEmitter::GetParticleCount() const
		{
			return m_particleCount;
		}

		ParticleEmitter::StructuredBufferPtr ParticleEmitter::GetParticleBuffer() const
		{
			return m_buffer;
		}

		void ParticleEmitter::Emit(float deltaTime)
		{
			Random random;

			const float interval = m_emitInterval + random.GetRandom(-m_emitIntervalRange, m_emitIntervalRange);

			if (fmodf(m_time, interval) < 1 - MathF::Epsilon)
				return;

			// インターバルになったら生成する
			const int32_t count = m_emitCount + random.GetRandom(-m_emitCountRange, m_emitCountRange);

			for (int32_t i = 0; i < count; ++i)
			{
				// 最大数より多く作らない
				if (m_particleCount >= m_maxCount)
					return;

				Particle particle;
				particle.position = m_position;
				particle.lifeTime = m_lifeTime + random.GetRandom(-m_lifeTimeRange, m_lifeTimeRange);
				particle.key.state = ParticleState::Born;
				particle.key.depth = 0.0f;
				particle.key.emitterID = 0;
				particle.key.particleIndex = m_particleCount;

				m_particles[m_particleCount++] = particle;

				DBGSTR("Particleが生まれました\n");
			}
		}

		void ParticleEmitter::Sort()
		{
			// パーティクルを生きている順番に並べ替える
			std::sort(m_particles.begin(), m_particles.begin() + m_particleCount, [&](const Particle& lhs,const Particle& rhs)->bool
				{
					// 生きているか(生まれたばかりはさらに消えづらいから)
					if (lhs.key.state > rhs.key.state)
						return true;
					// ライフタイムが大きいほど消えるまで時間がかかる
					return lhs.lifeTime > rhs.lifeTime;
				});

			// いい方法が思いつかなかったため力業
			for (uint32_t i = 0; i < m_particleCount; ++i)
			{
				// 一番前の死んだ場所を次のパーティクルの生成場所に指定する為
				if (m_particles[i].key.state == ParticleState::Dead)
				{
					DBGSTR("次回生成時の場所は%d\n", i);
					m_particleCount = i;
					break;
				}
			}

		}
	}
}