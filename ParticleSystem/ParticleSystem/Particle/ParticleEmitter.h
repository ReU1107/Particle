#pragma once
#include "../../Object.h"
#include <vector>
#include "../../Math/Vector3.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		struct Particle;
		class ParticleModule;
		class ShapeModule;
		class ParticleComputeModule;
		class StructuredBuffer;

		class ParticleEmitter : public Object
		{
		private:
			using base = Object;
			using ParticleEmitterPtr = std::shared_ptr<ParticleEmitter>;
			using ParticleModulePtr = std::shared_ptr<ParticleModule>;
			using ShapeModulePtr = std::shared_ptr<ShapeModule>;
			using ParticleComputeModulePtr = std::unique_ptr<ParticleComputeModule>;
			using ParticleComputeModules = std::vector<ParticleComputeModulePtr>;
			using Particles = std::vector<Particle>;
			using StructuredBufferPtr = StructuredBuffer*;
		private:
			StructuredBufferPtr m_buffer;
			float m_time;						// ����
			float m_duration;					// �������������
			int32_t m_emitCount;				// ��x�̕��o��
			int32_t m_emitCountRange;			// ���o�ʃ����_����
			float m_emitInterval;				// �p�[�e�B�N�������Ԋu
			float m_emitIntervalRange;			// �p�[�e�B�N�������Ԋu�����_����
			float m_lifeTime;					// �p�[�e�B�N���c������
			float m_lifeTimeRange;				// �c�����ԃ����_����
			Vector3 m_position;					// 
			uint32_t m_particleCount;			// 

			uint32_t m_maxCount;				// �ő吶����
			Particles m_particles;				// �p�[�e�B�N���z��
			ParticleComputeModules m_computes;
			ShapeModulePtr m_shape;				// ���o����`��
			bool m_active;

		public:
			// �R���X�g���N�^
			ParticleEmitter(const String& name, uint32_t maxCount);
			// �f�X�g���N�^
			virtual ~ParticleEmitter();

			static ParticleEmitterPtr Create(const String& name, uint32_t maxCount = 512);

			// �C���X�^���XID
			static const InstanceID ID() { return InstanceID::ParticleEmitter; }
			// �C���X�^���XID�擾
			virtual InstanceID GetInstanceID() const { return InstanceID::ParticleEmitter; }

		public:
			// ���Ԑݒ�
			void SetDuration(float duration);

			// 
			void SetEmitCount(int32_t count);
			// 
			void SetEmitCountRange(int32_t range);

			// �p�[�e�B�N�������p�x�ݒ�
			void SetEmitInterval(float emitInterval);
			// �p�[�e�B�N�������p�x�z�l�ݒ�
			void SetEmitIntervalRange(float range);

			// ���C�t�^�C���ݒ�
			void SetLifeTime(float lifeTime);
			// ���C�t�^�C�������_�����l�ݒ�
			void SetLifeTimeRange(float range);
			// �R���s���[�g���W���[���ǉ�
			void AddComputeModule(ParticleComputeModulePtr compute);

			// �`�󃂃W���[���ݒ�
			void SetShapeModule(ShapeModulePtr shape);

			// �ʒu�ݒ�
			void SetPosition(const Vector3& position);

			// �J�n
			void Start();

			// �X�V
			void Update(float deltaTime);

			bool IsActive() const;

			ShapeModulePtr GetShapeModule() const;

			uint32_t GetParticleCount() const;

			StructuredBufferPtr GetParticleBuffer() const;

		private:
			// 
			void Emit(float deltaTime);
			// �\�[�g
			void Sort();

		};
	}
}

using ParticleEmitterPtr = std::shared_ptr<Engine::GraphicsSystem::ParticleEmitter>;