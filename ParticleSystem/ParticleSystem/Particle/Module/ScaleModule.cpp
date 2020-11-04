#include "ScaleModule.h"
#include "../../../Utility/Random.h"
#include "../Particle.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		ScaleModule::ScaleModule()
			: base()
		{
		}
		
		ScaleModule::~ScaleModule()
		{
		}
		
		void ScaleModule::Update(Particle& particle, float deltaTime)
		{
			Random random;
			Vector3 scale = m_scale;
			scale.x = random.GetRandom(-m_scaleDistribution.x, m_scaleDistribution.x);
			scale.y = random.GetRandom(-m_scaleDistribution.y, m_scaleDistribution.y);
			scale.z = random.GetRandom(-m_scaleDistribution.z, m_scaleDistribution.z);

			
		}

		uint32_t ScaleModule::GetSize()
		{
			return uint32_t();
		}
	}

}