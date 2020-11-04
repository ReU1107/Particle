#pragma once
#include "ParticleModule.h"
#include <cstdint>

namespace Engine
{
	namespace GraphicsSystem
	{
		/*
		VelocityModule,ScaleAnimation��
		����������CPU�ōX�V���s��
		GPU�����ɕύX����

		�p�[�e�B�N���V�X�e������x����������Ƃ��Ȃ���
		�����ō쐬����

		*/
		/*
		priority�ꉞ����Ă���
		*/

		struct Particle;

		// �v�Z�������s���p�[�e�B�N�����W���[��
		class ParticleComputeModule : public ParticleModule
		{
		private:
			using base = ParticleModule;
		private:
			uint32_t m_priority;	// �D�揇��

		public:
			// 
			ParticleComputeModule();
			// 
			virtual ~ParticleComputeModule();

			// �D�揇�ʐݒ�
			void SetPriority(uint32_t priority);

			uint32_t GetPriority() const;

			virtual void Start(uint32_t particleMaxCount) {}

			virtual void Update(Particle& particle, float deltaTime) = 0;

			virtual uint32_t GetSize() = 0;
		};
	}
}