#pragma once
#include "../../Math/Vector3.h"
#include "../../Math/Vector4.h"

namespace Engine
{
	namespace GraphicsSystem
	{
		enum class ParticleState : uint8_t
		{
			Dead = 0,	// 死んでいる
			Alive = 1,	// 生きている(前のフレームから継続的)
			Born = 2,	// 生まれたばかり
		};

		// 変数を使用して行列を作成する

		struct Particle
		{
			Vector3 position;	// 位置
			Vector4 rotation;	// 回転
			Vector3 scale;		// 大きさ
			float lifeTime;
			struct SortKey
			{
				float depth;			// カメラからの位置
				uint32_t emitterID;		// 所属エミッターの番号
				uint32_t particleIndex;	// エミッター内部での番号
				ParticleState state;	// 状態
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