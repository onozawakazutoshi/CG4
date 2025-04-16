#include <Windows.h>
#include <KamataEngine.h>

using namespace KamataEngine;

DirectXCommon* dxcommon = DirectXCommon::GetInstance();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) { 

	KamataEngine::Initialize();
	
	while (true) {
		if (KamataEngine::Update()) {
			
			break;
		}
		dxcommon->PreDraw();
		dxcommon->PostDraw();
	}

	

	KamataEngine::Finalize();
	return 0;
}
