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
		ConstantBuffer* cb = renderer::constantBuffers[(UINT)graphics::eCBType::Transform];

		Vector4 Scalepos = Vector4(mPosition.x, mPosition.y, mPosition.z, mScale.x);
		cb->SetData(&Scalepos);
		cb->Bind(graphics::eShaderStage::VS);

		/*renderer::TransformCB data = {};
		data.pos = mPosition;
		data.scale = mScale;
		cb->SetData(&data);

		cb->Bind(graphics::eShaderStage::VS);*/
	}

}