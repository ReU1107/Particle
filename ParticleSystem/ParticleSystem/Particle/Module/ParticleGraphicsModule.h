#pragma once
#include "ParticleModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class ParticleGraphicsModule : public ParticleModule
		{
		private:
			using base = ParticleModule;

		public:
			// 
			ParticleGraphicsModule();
			// 
			virtual ~ParticleGraphicsModule();
		};
	}
}