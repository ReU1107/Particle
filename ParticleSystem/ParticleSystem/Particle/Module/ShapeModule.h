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
		Unityは全ての要素を共用体で持ち
		形状に合わせて使用している
		拡張性はないがUnityの場合それで解決できる為そうなっているのだと思う
		*/

		class ShapeModule : public ParticleGraphicsModule, public std::enable_shared_from_this<ShapeModule>
		{
		private:
			using base = ParticleGraphicsModule;
		private:
			ParticleShape m_shape;

		public:
			// コンストラクタ
			ShapeModule(ParticleShape shape);
			// デストラクタ
			virtual ~ShapeModule();

			virtual void Start(uint32_t particleMaxCount) {}

			// バッファ内更新
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