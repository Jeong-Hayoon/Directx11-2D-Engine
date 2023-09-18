#include "yaSceneManager.h"

#include "yaResources.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaInput.h"
#include "yaBullet.h"


namespace ya
{
	GameObject* SceneManager::object = nullptr;
	Transform* SceneManager::tr = nullptr;
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		mPlayScene = new Scene();
		mActiveScene = mPlayScene;
		{
			object = new GameObject();
			tr = new Transform();
			tr->SetPosition(Vector3(0.f, -0.5f, 0.0f));
			object->AddComponent(tr);

			MeshRenderer* meshRenderer = new MeshRenderer();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
			object->AddComponent(meshRenderer);

			mPlayScene->AddGameObject(object, LAYER::NONE);
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
		if (Input::GetKeyDown(KEY_CODE::SPACE))
		{
			Bullet* bullet = new Bullet();
			Transform* bullettr = new Transform();
			Vector3 playerpos = object->GetComponent<Transform>()->GetPosition();
			bullettr->SetPosition(Vector3(playerpos));
			bullet->AddComponent(bullettr);

			MeshRenderer* meshRenderer = new MeshRenderer();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
			bullet->AddComponent(meshRenderer);

			SceneManager::GetAciveScene()->AddGameObject(bullet, LAYER::NONE);
		}
		
		tr->SetPosition(pos);

		Vector3 ScalePos = tr->GetScale();

		if (Input::GetKeyDown(KEY_CODE::C))
		{
			
			ScalePos.x += 1.0f * Time::DeltaTime();
			

		}

		tr->SetScale(ScalePos);

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
