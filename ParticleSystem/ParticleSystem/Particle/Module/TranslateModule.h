#pragma once
#include "ParticleComputeModule.h"
#include "../../../Math/Vector3.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class TranslateModule final : public ParticleComputeModule
		{
		private:
			using base = ParticleComputeModule;
			using Displacements = std::vector<Vector3>;
			using Acclerations = std::vector<Vector3>;
			using TranslateModulePtr = std::unique_ptr<TranslateModule>;
		private:
			Displacements m_displacements;		// �ψʔz��
			Acclerations m_accelerations;
			Vector3 m_displacement;				// �ψ�
			Vector3 m_acceleration;				// �����x(���񂾂񑁂��Ȃ鎞�ɗL�p)
			Vector3 m_displacementDistribution;	// �ψʕ��z
			Vector3 m_accelerationDistribution;	// �����x���z
		public:
			// 
			TranslateModule();
			// 
			virtual ~TranslateModule();

			static TranslateModulePtr Create();

			virtual void Start(uint32_t particleMaxCount) override;

			virtual void Update(Particle& particle, float deltaTime) override;

			virtual uint32_t GetSize() override;

			void SetDisplacement(const Vector3& displacement);

			void SetAccleration(const Vector3& acceleration);

			void SetDisplacementDistribution(const Vector3& distribution);

			void SetAccelerationDistribution(const Vector3& distribution);
		};
	}
}

using TranslateModulePtr = std::unique_ptr<Engine::GraphicsSystem::TranslateModule>;
