#pragma once
#include "hyGameObject.h"
#include "hyTransform.h"
		  
namespace hy
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
		 Transform* tr;
	};
}



