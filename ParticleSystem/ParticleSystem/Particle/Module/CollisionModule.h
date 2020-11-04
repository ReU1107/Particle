#pragma once
#include "ParticleComputeModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class CollisionModule final : public ParticleComputeModule
		{
		private:
			using base = ParticleComputeModule;

		public:
			// �R���X�g���N�^
			CollisionModule();
			// �f�X�g���N�^
			virtual ~CollisionModule();

			virtual void Update(Particle& particle, float deltaTime) override;

			virtual uint32_t GetSize() override;
		};
	}
}