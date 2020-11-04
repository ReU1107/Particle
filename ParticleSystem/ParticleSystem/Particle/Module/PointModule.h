#pragma once
#include "ShapeModule.h"
#include "../../../Math/Color4.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class VertexBuffer;
		class Material;

		enum class PrimitiveTopology : uint8_t;

		// 
		class PointModule final : public ShapeModule
		{
		private:
			using base = ShapeModule;
			using VertexBufferPtr = VertexBuffer*;
			using MaterialPtr = std::shared_ptr<Material>;
			using PointModulePtr = std::shared_ptr<PointModule>;
		private:
			VertexBufferPtr m_vertexBuffer;
			MaterialPtr m_material;
			Color4 m_color;
			Color4 m_colorDistribution;

			PrimitiveTopology m_toploty;

		public:
			// �R���X�g���N�^
			PointModule();
			// �f�X�g���N�^
			virtual ~PointModule();

			static PointModulePtr Create();

			// �F�ݒ�
			void SetColor(const Color4& color);
			// �F�̃����_�����z�ݒ�
			void SetColorDistribution(const Color4& distribution);

			// ���_�o�b�t�@�擾
			VertexBufferPtr GetVertexBuffer() const;

			// 
			virtual void Start(uint32_t particleMaxCount) override;

			virtual void Update() override;

		};

	}
}
