#pragma once
#include "yaGraphicsDevice_DX11.h"
#include <Windows.h>

namespace ya
{
	class Application
	{
	public:
		virtual ~Application();

		//  Runs the main engine loop
		void Run();

		//  This is where the critical initializations happen (before any rendering or anything else)
		virtual void Initialize();

		//  This is where application-wide updates get executed once per frame. 
		//  RenderPath::Update is also called from here for the active component
		virtual void Update();

		//  This is where application-wide updates get executed in a fixed timestep based manner. 
		//  RenderPath::FixedUpdate is also called from here for the active component
		virtual void FixedUpdate();

		//  This is where application-wide rendering happens to offscreen buffers. 
		//  RenderPath::Render is also called from here for the active component
		virtual void Render();

		// You need to call this before calling Run() or Initialize() if you want to render
		void SetWindow(HWND hwnd, UINT width, UINT height);

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHegith; }
		HWND GetHwnd() { return mHwnd; }

	private:
		bool initialized = false;
		// unique_ptr- 메모리 해제를 따로 해주지 않아도 메모리 해제가 자동으로 일어남
		// unique의 의미대로 객체는 한 개 밖에 만들지 못함
		std::unique_ptr<ya::graphics::GraphicsDevice_DX11> graphicsDevice;

		HWND mHwnd;
		UINT mWidth;
		UINT mHegith;
	};
}
