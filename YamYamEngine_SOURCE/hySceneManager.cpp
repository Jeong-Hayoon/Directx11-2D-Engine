#include "hySceneManager.h"
#include "hyResources.h"
#include "hyTime.h"
#include "hyGameObject.h"
#include "hyTransform.h"
#include "hyMeshRenderer.h"
#include "hyInput.h"
#include "hyBullet.h"


namespace hy
{
	Player* SceneManager::player = nullptr;
	Transform* SceneManager::tr = nullptr;
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		mPlayScene = new Scene();
		mActiveScene = mPlayScene;
		{
			player = new Player();
			tr = new Transform();
			tr->SetPosition(Vector3(0.f, -0.5f, 0.0f));
			player->AddComponent(tr);

			MeshRenderer* meshRenderer = new MeshRenderer();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
			player->AddComponent(meshRenderer);

			mPlayScene->AddGameObject(player, LAYER::NONE);
		}

		/*{
			GameObject* object = new GameObject();
			Transform* tr = new Transform();
			tr->SetPosition(Vector3(-0.5f, -0.2f, 0.0f));
			object->AddComponent(tr);

			MeshRenderer* meshRenderer = new MeshRenderer();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
			object->AddComponent(meshRenderer);

			mPlayScene->AddGameObject(object, LAYER::NONE);
		}*/
	}

	void SceneManager::Update()
	{
		mPlayScene->Update();

		Vector3 pos = tr->GetPosition();

		if (Input::GetKeyDown(KEY_CODE::UP) || Input::GetKey(KEY_CODE::UP))
		{
			pos.y += 0.8f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(KEY_CODE::LEFT) || Input::GetKey(KEY_CODE::LEFT))
		{
			pos.x -= 0.8f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(KEY_CODE::RIGHT) || Input::GetKey(KEY_CODE::RIGHT))
		{
			pos.x += 0.8f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(KEY_CODE::DOWN) || Input::GetKey(KEY_CODE::DOWN))
		{
			pos.y -= 0.8f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(KEY_CODE::SPACE) || Input::GetKey(KEY_CODE::SPACE))
		{
			Bullet* bullet = new Bullet();
			Transform* bullettr = new Transform();
			Vector3 playerpos = player->GetComponent<Transform>()->GetPosition();
			bullettr->SetPosition(Vector3(playerpos));
			bullet->AddComponent(bullettr);

			MeshRenderer* meshRenderer = new MeshRenderer();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
			bullet->AddComponent(meshRenderer);

			SceneManager::GetAciveScene()->AddGameObject(bullet, LAYER::NONE);
		}
		
		tr->SetPosition(pos);

	}

	void SceneManager::FixedUpdate()
	{
		mPlayScene->FixedUpdate();
	}

	void SceneManager::Render()
	{
		mPlayScene->Render();
	}
}
