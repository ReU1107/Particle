#include "TranslateModule.h"
#include "../Particle.h"
#include "../../../Utility/Random.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		TranslateModule::TranslateModule()
			: base()
			, m_displacement()
			, m_acceleration()
			, m_displacementDistribution()
			, m_accelerationDistribution()
		{
		}

		TranslateModule::~TranslateModule()
		{
		}

		TranslateModule::TranslateModulePtr TranslateModule::Create()
		{
			return std::make_unique<TranslateModule>();
		}

		void TranslateModule::Start(uint32_t particleMaxCount)
		{
			m_displacements.resize(particleMaxCount);
			m_accelerations.resize(particleMaxCount);
		}
		
		void TranslateModule::Update(Particle& particle, float deltaTime)
		{
			Vector3 displacement = Vector3::Zero;
			Vector3 acceleration = Vector3::Zero;

			const uint32_t particleIndex = particle.key.particleIndex;
			if (particleIndex >= m_displacements.size())
				assert(!"TranslateModule配列範囲外の指定を使用としています");

			if (particle.key.state == ParticleState::Born)
			{
				displacement = m_displacement;
				acceleration = m_acceleration;
				Random random;
				displacement.x += random.GetRandom(-m_displacementDistribution.x, m_displacementDistribution.x);
				displacement.y += random.GetRandom(-m_displacementDistribution.y, m_displacementDistribution.y);
				displacement.z += random.GetRandom(-m_displacementDistribution.z, m_displacementDistribution.z);

				acceleration.x += random.GetRandom(-m_accelerationDistribution.x, m_accelerationDistribution.x);
				acceleration.y += random.GetRandom(-m_accelerationDistribution.y, m_accelerationDistribution.y);
				acceleration.z += random.GetRandom(-m_accelerationDistribution.z, m_accelerationDistribution.z);

				m_displacements[particleIndex] = displacement;
				m_accelerations[particleIndex] = acceleration;
			}
			else
			{
				displacement = m_displacements[particleIndex];
				acceleration = m_accelerations[particleIndex];
			}

			particle.position += displacement + (acceleration * deltaTime);
		}

		uint32_t TranslateModule::GetSize()
		{
			return sizeof(*this);
		}
		
		void TranslateModule::SetDisplacement(const Vector3& displacement)
		{
			m_displacement = displacement;
		}
		
		void TranslateModule::SetAccleration(const Vector3& acceleration)
		{
			m_acceleration = acceleration;
		}
		
		void TranslateModule::SetDisplacementDistribution(const Vector3& distribution)
		{
			m_displacementDistribution = distribution;
		}

		void TranslateModule::SetAccelerationDistribution(const Vector3& distribution)
		{
			m_accelerationDistribution = distribution;
		}
	}
}
