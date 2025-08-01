#include "BackScreen.h"
void BackScreen::Initialize() {
	uint32_t tex = TextureManager::Load("uvChecker.png");
	pos = {640, 360};
	sprite = Sprite::Create(tex, /*Vector2(worldtransform_.translation_.x*10+640, worldtransform_.translation_.y*10+360)*/ pos, {1, 1, 1, 1}, {0.5, 0.5});
	sprite->SetSize({2560, 720});


}

void BackScreen::Draw(ID3D12GraphicsCommandList* commandList) {

	Sprite::PreDraw(commandList);

	sprite->Draw();

	Sprite::PostDraw();
}

void BackScreen::Update() { 
	if (pos.x <= 1280) {
		pos.x++;
	} else {
		pos.x = 640;
	}
	sprite->SetPosition(pos);
	

}