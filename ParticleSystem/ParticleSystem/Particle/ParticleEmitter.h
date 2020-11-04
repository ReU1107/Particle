#pragma once
#include "../../Object.h"
#include <vector>
#include "../../Math/Vector3.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		struct Particle;
		class ParticleModule;
		class ShapeModule;
		class ParticleComputeModule;
		class StructuredBuffer;

		class ParticleEmitter : public Object
		{
		private:
			using base = Object;
			using ParticleEmitterPtr = std::shared_ptr<ParticleEmitter>;
			using ParticleModulePtr = std::shared_ptr<ParticleModule>;
			using ShapeModulePtr = std::shared_ptr<ShapeModule>;
			using ParticleComputeModulePtr = std::unique_ptr<ParticleComputeModule>;
			using ParticleComputeModules = std::vector<ParticleComputeModulePtr>;
			using Particles = std::vector<Particle>;
			using StructuredBufferPtr = StructuredBuffer*;
		private:
			StructuredBufferPtr m_buffer;
			float m_time;						// 時間
			float m_duration;					// 発生させる期間
			int32_t m_emitCount;				// 一度の放出量
			int32_t m_emitCountRange;			// 放出量ランダム幅
			float m_emitInterval;				// パーティクル発生間隔
			float m_emitIntervalRange;			// パーティクル発生間隔ランダム幅
			float m_lifeTime;					// パーティクル残存時間
			float m_lifeTimeRange;				// 残存時間ランダム幅
			Vector3 m_position;					// 
			uint32_t m_particleCount;			// 

			uint32_t m_maxCount;				// 最大生成数
			Particles m_particles;				// パーティクル配列
			ParticleComputeModules m_computes;
			ShapeModulePtr m_shape;				// 放出する形状
			bool m_active;

		public:
			// コンストラクタ
			ParticleEmitter(const String& name, uint32_t maxCount);
			// デストラクタ
			virtual ~ParticleEmitter();

			static ParticleEmitterPtr Create(const String& name, uint32_t maxCount = 512);

			// インスタンスID
			static const InstanceID ID() { return InstanceID::ParticleEmitter; }
			// インスタンスID取得
			virtual InstanceID GetInstanceID() const { return InstanceID::ParticleEmitter; }

		public:
			// 期間設定
			void SetDuration(float duration);

			// 
			void SetEmitCount(int32_t count);
			// 
			void SetEmitCountRange(int32_t range);

			// パーティクル発生頻度設定
			void SetEmitInterval(float emitInterval);
			// パーティクル発生頻度布値設定
			void SetEmitIntervalRange(float range);

			// ライフタイム設定
			void SetLifeTime(float lifeTime);
			// ライフタイムランダム幅値設定
			void SetLifeTimeRange(float range);
			// コンピュートモジュール追加
			void AddComputeModule(ParticleComputeModulePtr compute);

			// 形状モジュール設定
			void SetShapeModule(ShapeModulePtr shape);

			// 位置設定
			void SetPosition(const Vector3& position);

			// 開始
			void Start();

			// 更新
			void Update(float deltaTime);

			bool IsActive() const;

			ShapeModulePtr GetShapeModule() const;

			uint32_t GetParticleCount() const;

			StructuredBufferPtr GetParticleBuffer() const;

		private:
			// 
			void Emit(float deltaTime);
			// ソート
			void Sort();

		};
	}
}

using ParticleEmitterPtr = std::shared_ptr<Engine::GraphicsSystem::ParticleEmitter>;