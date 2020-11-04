#pragma once
#include "ParticleComputeModule.h"
#include "../../../Math/Vector4.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class RotateModule final : public ParticleComputeModule
		{
		private:
			using base = ParticleComputeModule;
		private:
			Vector4 m_rotation;
			Vector4 m_rotationDistribution;
		public:
			// �R���X�g���N�^
			RotateModule();
			// �f�X�g���N�^
			virtual ~RotateModule();

			virtual void Update(Particle& particle, float deltaTime) override;

			virtual uint32_t GetSize() override;
		};
		
	}
}