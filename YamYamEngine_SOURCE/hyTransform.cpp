#include "hyTransform.h"
#include "hyGraphicsDevice_DX11.h"
#include "hyRenderer.h"

namespace hy
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
		Vector4 Scalepos = Vector4(mPosition.x, mPosition.y, mPosition.z, mScale.x);
		cb->Bind(&Scalepos);
		cb->SetPipline(graphics::ShaderStage::VS);
	}

}