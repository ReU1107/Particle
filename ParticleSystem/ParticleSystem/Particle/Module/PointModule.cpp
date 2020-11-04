#include "PointModule.h"
#include "../../HardwareBuffer/VertexBuffer.h"
#include "../../../Math/Vector3.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		PointModule::PointModule()
			: base(ParticleShape::Point)
			, m_vertexBuffer(nullptr)
		{
		}

		PointModule::~PointModule()
		{
			delete m_vertexBuffer;
		}

		PointModule::PointModulePtr PointModule::Create()
		{
			return std::make_shared<PointModule>();
		}

		void PointModule::SetColor(const Color4& color)
		{
			m_color = color;
		}

		void PointModule::SetColorDistribution(const Color4& distribution)
		{
			m_colorDistribution = distribution;
		}

		PointModule::VertexBufferPtr PointModule::GetVertexBuffer() const
		{
			return m_vertexBuffer;
		}

		void PointModule::Start(uint32_t particleMaxCount)
		{
			if (m_vertexBuffer)
				return;
			Vector3 pos(0.0f, 0.0f, 0.0f);
			m_vertexBuffer = new VertexBuffer();
			m_vertexBuffer->SetStride(sizeof(Vector3));
			m_vertexBuffer->SetCount(1);
			m_vertexBuffer->Create();
		}

		void PointModule::Update()
		{
			//m_vertexBuffer->Update();
		}
	}
}