#pragma once
#include "ShapeModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class Sprite;

		class SpriteModule final : public ShapeModule
		{
		private:
			using base = ShapeModule;
			using SpritePtr = std::shared_ptr<Sprite>;
		private:
			SpritePtr m_sprite;

		public:
			// 
			SpriteModule();
			// 
			virtual ~SpriteModule();

			// �X�v���C�g�ݒ�
			void SetSprite(SpritePtr sprite);

			SpritePtr GetSprite() const;

		};
	}
}
