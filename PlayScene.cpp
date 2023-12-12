#include "PlayScene.h"
#include "Stage.h"
#include "Button.h"

// コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

// 初期化
void PlayScene::Initialize() {
	Instantiate<Stage>(this);
	Button* b = (Button*)Instantiate<Button>(this);
	b->LoadFile("Image\\TestButton");
	b->SetButtonPosition(50, 20);
}

// 更新
void PlayScene::Update() {

}

// 描画
void PlayScene::Draw() {

}

// 開放
void PlayScene::Release() {

}
