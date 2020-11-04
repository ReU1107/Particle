#pragma once
#include "ShapeModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class StripeModule final : public ShapeModule
		{
		private:
			using base = ShapeModule;

		public:
			// 
			StripeModule();
			// 
			virtual ~StripeModule();
		};

	}
}