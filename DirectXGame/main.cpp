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
	int Scene = 1;
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	while (true) {
		if (KamataEngine::Update()) {
			
			break;
		}

		switch (Scene) {

		case 0:
			dxCommon->PreDraw();
			title->Draw(dxCommon->GetCommandList());
			dxCommon->PostDraw();
			break;
		case 1:
			gameScene->Update();

			dxCommon->PreDraw();

			gameScene->Draw();
			dxCommon->PostDraw();
		}
		
	}

	

	KamataEngine::Finalize();
	return 0;
}
