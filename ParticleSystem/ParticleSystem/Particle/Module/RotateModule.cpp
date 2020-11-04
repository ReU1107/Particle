#include "RotateModule.h"
#include "../../../Utility/Random.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		RotateModule::RotateModule()
		{
		}

		RotateModule::~RotateModule()
		{

		}

		void RotateModule::Update(Particle& particle, float deltaTime)
		{
			Random random;
			Vector4 rotation = m_rotation;
			rotation.x += random.GetRandom(-m_rotationDistribution.x, m_rotationDistribution.x);
			rotation.y += random.GetRandom(-m_rotationDistribution.y, m_rotationDistribution.y);
			rotation.z += random.GetRandom(-m_rotationDistribution.z, m_rotationDistribution.z);
			rotation.w += random.GetRandom(-m_rotationDistribution.w, m_rotationDistribution.w);

			
		}

		uint32_t RotateModule::GetSize()
		{
			return uint32_t();
		}
	}
}
