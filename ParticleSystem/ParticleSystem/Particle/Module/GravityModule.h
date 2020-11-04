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
			// コンストラクタ
			GravityModule();
			// デストラクタ
			virtual ~GravityModule();

			virtual void Update(Particle& particle, float deltaTime) override;

			virtual uint32_t GetSize() override;
		};
	}
}