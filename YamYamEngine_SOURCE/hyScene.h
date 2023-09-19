#pragma once
#include "hyEnums.h"
#include "hyEntity.h"
#include "hyLayer.h"

namespace hy
{
	using namespace hy::enums;

	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render();

		Layer* GetLayer(UINT index) { return& mLayers[index]; }
		void AddGameObject(GameObject* gameObject, UINT layerIndex);

	private:
		Layer mLayers[LAYERTYPE::MAX];
	};
}
