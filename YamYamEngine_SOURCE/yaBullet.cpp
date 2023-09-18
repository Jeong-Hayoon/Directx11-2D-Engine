#include "yaBullet.h"
#include "yaResources.h"
#include "yaMeshRenderer.h"
#include "yaSceneManager.h"
#include "yaTime.h"

namespace ya
{
	GameObject* Bullet :: object = nullptr;


	Bullet::Bullet()
	{
		
	}
	Bullet::~Bullet()
	{
	}
	void Bullet::Initialize()
	{	
		GameObject::Initialize();
	}
	void Bullet::Update()
	{
		tr = GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos.y += 1.f * Time::DeltaTime();
		tr->SetPosition(pos);

		GameObject::Update();
	}
	void Bullet::FixedUpdate()
	{
		GameObject::FixedUpdate();
	}
	void Bullet::Render()
	{
		GameObject::Render();
	}
}