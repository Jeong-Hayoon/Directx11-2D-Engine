#include "hyResources.h"
#include "hyMeshRenderer.h"
#include "hySceneManager.h"
#include "hyTime.h"
#include "hyPlayer.h"
#include "hyInput.h"

namespace hy
{
	GameObject* Player::object = nullptr;

	Player::Player()
	{

	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		Transform* tr = this->GetComponent<Transform>();
		Vector3 ScalePos = tr->GetScale();

		if (Input::GetKey(KEY_CODE::C))
		{
			ScalePos.x += 1.0f * Time::DeltaTime();
		}
		if (Input::GetKey(KEY_CODE::V))
		{
			ScalePos.x -= 1.0f * Time::DeltaTime();
		}

		tr->SetScale(ScalePos);

		GameObject::Update();
		
	}
	void Player::FixedUpdate()
	{
		GameObject::FixedUpdate();
	}
	void Player::Render()
	{
		GameObject::Render();
	}
}