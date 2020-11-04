#pragma once
#include "ParticleModule.h"
#include <cstdint>

namespace Engine
{
	namespace GraphicsSystem
	{
		/*
		VelocityModule,ScaleAnimation等
		初期実装はCPUで更新を行う
		GPU処理に変更する

		パーティクルシステムを一度も作ったことがない為
		試しで作成する

		*/
		/*
		priority一応入れている
		*/

		struct Particle;

		// 計算処理を行うパーティクルモジュール
		class ParticleComputeModule : public ParticleModule
		{
		private:
			using base = ParticleModule;
		private:
			uint32_t m_priority;	// 優先順位

		public:
			// 
			ParticleComputeModule();
			// 
			virtual ~ParticleComputeModule();

			// 優先順位設定
			void SetPriority(uint32_t priority);

			uint32_t GetPriority() const;

			virtual void Start(uint32_t particleMaxCount) {}

			virtual void Update(Particle& particle, float deltaTime) = 0;

			virtual uint32_t GetSize() = 0;
		};
	}
}