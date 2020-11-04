#include "SpriteModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		SpriteModule::SpriteModule()
			: base(ParticleShape::Sprite)
			, m_sprite(nullptr)
		{
		}

		SpriteModule::~SpriteModule()
		{
		}

		void SpriteModule::SetSprite(SpritePtr sprite)
		{
			m_sprite = sprite;
		}

		SpriteModule::SpritePtr SpriteModule::GetSprite() const
		{
			return m_sprite;
		}
	}
}