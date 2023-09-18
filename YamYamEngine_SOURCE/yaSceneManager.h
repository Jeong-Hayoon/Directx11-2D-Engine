#pragma once
#include "yaScene.h"
#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void FixedUpdate();
		static void Render();

		static Scene* GetAciveScene() { return mActiveScene; }
		static Transform* GetPosition() { return tr; }

	private:
		static Scene* mActiveScene;
		static Scene* mPlayScene;
		static GameObject* object;
		static Transform* tr;
	};
}
