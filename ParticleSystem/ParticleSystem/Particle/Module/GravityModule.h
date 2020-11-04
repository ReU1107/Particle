#pragma once
#include "ParticleComputeModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class GravityModule final : public ParticleComputeModule
		{
		private:
			using base = ParticleComputeModule;

		public:
			// �R���X�g���N�^
			GravityModule();
			// �f�X�g���N�^
			virtual ~GravityModule();

			virtual void Update(Particle& particle, float deltaTime) override;

			virtual uint32_t GetSize() override;
		};
	}
}