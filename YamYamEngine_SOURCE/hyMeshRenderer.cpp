#include "hyMeshRenderer.h"
#include "hyGameObject.h"
#include "hyTransform.h"

namespace hy
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

