#include "MeshModule.h"
namespace Engine
{
	namespace GraphicsSystem
	{
		MeshModule::MeshModule()
			: base(ParticleShape::Mesh)
			, m_mesh(nullptr)
		{
		}

		MeshModule::~MeshModule()
		{
		}

		MeshModule::MeshModulePtr MeshModule::Create()
		{
			return std::make_shared<MeshModule>();
		}

		void MeshModule::SetMesh(MeshPtr mesh)
		{
			m_mesh = mesh;
		}

		MeshModule::MeshPtr MeshModule::GetMesh() const
		{
			return m_mesh;
		}
		
		void MeshModule::Start(uint32_t maxCount)
		{
		}

		void MeshModule::Update()
		{
		}
	}

}