#pragma once
#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{
	class Bullet : public GameObject
	{
	public:
	
		Bullet();
		virtual ~Bullet();
		virtual void Initialize();
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render();

	private:
		static GameObject* object;
		static Transform* tr;
	};
}



