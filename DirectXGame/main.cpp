#include <Windows.h>
#include <KamataEngine.h>
#include "GameScene.h"
#include "Title.h"

using namespace KamataEngine;

GameScene* gameScene = new GameScene;
Title* title = new Title;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) { 

	KamataEngine::Initialize();
	gameScene->Initialize();
	title->Initialize();

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	while (true) {
		if (KamataEngine::Update()) {
			
			break;
		}

		gameScene->Update();

		dxCommon->PreDraw();
		//title->Draw(dxCommon->GetCommandList());

		gameScene->Draw();
		dxCommon->PostDraw();

		
	}

	

	KamataEngine::Finalize();
	return 0;
}
