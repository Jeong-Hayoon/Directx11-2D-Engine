#include "hyBullet.h"
#include "hyResources.h"
#include "hyMeshRenderer.h"
#include "hySceneManager.h"
#include "hyTime.h"

namespace hy
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