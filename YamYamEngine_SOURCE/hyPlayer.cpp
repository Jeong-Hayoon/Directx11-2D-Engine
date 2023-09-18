#include "hyResources.h"
#include "hyMeshRenderer.h"
#include "hySceneManager.h"
#include "hyTime.h"
#include "hyPlayer.h"

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