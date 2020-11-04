#pragma once
#include "ParticleComputeModule.h"
#include "../../../Math/Vector3.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class ScaleModule final : public ParticleComputeModule
		{
		private:
			using base = ParticleComputeModule;
		private:
			Vector3 m_scale;
			Vector3 m_scaleDistribution;

		public:
			// コンストラクタ
			ScaleModule();
			// デストラクタ
			virtual ~ScaleModule();
			// 
			virtual void Update(Particle& particle, float deltaTime) override;

			virtual uint32_t GetSize() override;
		};

	}
}