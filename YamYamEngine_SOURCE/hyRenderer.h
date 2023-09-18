#pragma once
#include "hyEnums.h"
#include "CommonInclude.h"
#include "Directx11_2D_Engine.h"
#include "hyMath.h"
#include "hyGraphicsDevice_DX11.h"
		  
#include "hyMesh.h"
#include "hyShader.h"
#include "hyConstantBuffer.h"

using namespace hy::graphics;
using namespace hy::enums;
using namespace hy::math;

namespace hy::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Mesh* mesh;
	extern Shader* shader;
	extern ConstantBuffer* constantBuffers[];

	// Initialize the renderer
	void Initialize();
	void Release();
}
