#pragma once
#include "ShapeModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		class Mesh;

		class MeshModule final : public ShapeModule
		{
		private:
			using base = ShapeModule;
			using MeshPtr = std::shared_ptr<Mesh>;
			using MeshModulePtr = std::shared_ptr<MeshModule>;
		private:
			MeshPtr m_mesh;

		public:
			// �R���X�g���N�^
			MeshModule();
			// �f�X�g���N�^
			virtual ~MeshModule();

			static MeshModulePtr Create();

			// ���b�V���ݒ�
			void SetMesh(MeshPtr mesh);

			MeshPtr GetMesh() const;

			virtual void Start(uint32_t maxCount) override;

			virtual void Update() override;
		};
	}
}
