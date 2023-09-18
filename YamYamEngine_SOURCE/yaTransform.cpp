#include "yaTransform.h"
#include "yaGraphicsDevice_DX11.h"
#include "yaRenderer.h"

namespace ya
{

	Transform::Transform()
		: Component(COMPONENTTYPE::TRANSFORM)
	{

	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::FixedUpdate()
	{
	}

	void Transform::Render()
	{
	}

	void Transform::SetConstantBuffer()
	{
		ConstantBuffer* cb = renderer::constantBuffers[(UINT)graphics::CBTYPES::TRANSFORM];
		Vector4 Scalepos = Vector4(mPosition.x, mPosition.y, mPosition.z, 1 / mScale.x);
		cb->Bind(&Scalepos);
		cb->SetPipline(graphics::ShaderStage::VS);
	}

}