#pragma once
#include "hyScene.h"
#include "hyGameObject.h"
#include "hyTransform.h"
#include "hyPlayer.h"


namespace hy
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
		static Player* player;
		static Transform* tr;
	};
}
