#include "yaMeshRenderer.h"
#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{
	// SpriteRenderer와 같지만 Mesh를 가지고 Render
	MeshRenderer::MeshRenderer()
		: Component(COMPONENTTYPE::MESH)
	{
	}

	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::Initialize()
	{
	}

	void MeshRenderer::Update()
	{
	}

	void MeshRenderer::FixedUpdate()
	{
	}

	void MeshRenderer::Render()
	{
		GetOwner()->GetComponent<Transform>()->SetConstantBuffer();

		mShader->Update();
		mMesh->Render();
	}
}

