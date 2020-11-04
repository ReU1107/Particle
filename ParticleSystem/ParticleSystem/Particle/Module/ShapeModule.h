#pragma once
#include "ParticleGraphicsModule.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		enum class ParticleShape : uint8_t
		{
			Point,
			Mesh,
			Sprite,
			Stripe,
		};
		/*
		Unity�͑S�Ă̗v�f�����p�̂Ŏ���
		�`��ɍ��킹�Ďg�p���Ă���
		�g�����͂Ȃ���Unity�̏ꍇ����ŉ����ł���ׂ����Ȃ��Ă���̂��Ǝv��
		*/

		class ShapeModule : public ParticleGraphicsModule, public std::enable_shared_from_this<ShapeModule>
		{
		private:
			using base = ParticleGraphicsModule;
		private:
			ParticleShape m_shape;

		public:
			// �R���X�g���N�^
			ShapeModule(ParticleShape shape);
			// �f�X�g���N�^
			virtual ~ShapeModule();

			virtual void Start(uint32_t particleMaxCount) {}

			// �o�b�t�@���X�V
			virtual void Update() = 0;

			template<class T>
			std::shared_ptr<T> Convert();

		};

		template<class T>
		inline std::shared_ptr<T> ShapeModule::Convert()
		{
			return  std::dynamic_pointer_cast<T>(shared_from_this());
		}

	}
}