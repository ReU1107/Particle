#pragma once
#include "../../Math/Vector3.h"
#include "../../Math/Vector4.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		enum class ParticleState : uint8_t
		{
			Dead = 0,	// ����ł���
			Alive = 1,	// �����Ă���(�O�̃t���[������p���I)
			Born = 2,	// ���܂ꂽ�΂���
		};

		// �ϐ����g�p���čs����쐬����

		struct Particle
		{
			Vector3 position;	// �ʒu
			Vector4 rotation;	// ��]
			Vector3 scale;		// �傫��
			float lifeTime;
			struct SortKey
			{
				float depth;			// �J��������̈ʒu
				uint32_t emitterID;		// �����G�~�b�^�[�̔ԍ�
				uint32_t particleIndex;	// �G�~�b�^�[�����ł̔ԍ�
				ParticleState state;	// ���
				SortKey()
					: depth(1.0f)
					, emitterID(0)
					, particleIndex(0)
					, state(ParticleState::Dead)
				{}
			}key;

			Particle()
				: position(Vector3::Zero)
				, rotation(Vector4::Identity)
				, scale(Vector3::One)
				, lifeTime(0.0f)
				, key()
			{}
		};
	}
}