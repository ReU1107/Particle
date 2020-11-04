#pragma once
#include <memory>
#include <cstdint>

namespace Engine
{
	namespace GraphicsSystem
	{
		// パーティクルを構成する部品
		class ParticleModule
		{
		private:

		public:
			// コンストラクタ
			ParticleModule();
			// デストラクタ
			virtual ~ParticleModule();
		};
	}
}
