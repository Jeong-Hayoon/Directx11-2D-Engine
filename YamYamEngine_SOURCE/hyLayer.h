#pragma once
#include "hyEntity.h"
#include "hyGameObject.h"

namespace hy
{
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render();

		void AddGameObject(GameObject*  gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
