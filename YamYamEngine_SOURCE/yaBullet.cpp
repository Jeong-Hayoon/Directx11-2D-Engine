#include "yaBullet.h"
#include "yaResources.h"
#include "yaMeshRenderer.h"
#include "yaSceneManager.h"



namespace ya
{
	Bullet::Bullet()
	{
	}
	Bullet::~Bullet()
	{
	}
	void Bullet::Initialize()
	{
		object = new GameObject();
		tr = new Transform();
		tr->SetPosition(Vector3(0.f, -0.5f, 0.0f));
		object->AddComponent(tr);

		MeshRenderer* meshRenderer = new MeshRenderer();
		meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
		meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
		object->AddComponent(meshRenderer);

		SceneManager::GetAciveScene()->AddGameObject(object, LAYER::NONE);
	}
	void Bullet::Update()
	{
	}
	void Bullet::FixedUpdate()
	{
	}
	void Bullet::Render()
	{
	}
}