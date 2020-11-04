#include "ParticleComputeModule.h"
namespace Engine
{
	namespace GraphicsSystem
	{
		ParticleComputeModule::ParticleComputeModule()
			: base()
			, m_priority(0)
		{
		}

		ParticleComputeModule::~ParticleComputeModule()
		{
		}

		void ParticleComputeModule::SetPriority(uint32_t priority)
		{
			m_priority = priority;
		}
		
		uint32_t ParticleComputeModule::GetPriority() const
		{
			return m_priority;
		}
	}
}