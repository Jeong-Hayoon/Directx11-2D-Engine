#pragma once
#include "hyScene.h"
#include "hyGameObject.h"
#include "hySceneManager.h"
#include "hyTransform.h"

namespace hy::object
{
	template <typename T>
	static __forceinline T* Instantiate(LAYERTYPE type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObject, type);
		gameObject->Initialize();
		gameObject->SetLayerType(type);

		return gameObject;
	}


	template <typename T>
	static __forceinline T* Instantiate(LAYERTYPE type, Vector2 position)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObject, type);
		gameObject->Initialize();
		gameObject->SetLayerType(type);
		gameObject->GetComponent<Transform>()->SetPosition(position);

		return gameObject;
	}

}

