#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include "Button.h"
#include "Engine/Camera.h"

// コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

// 初期化
void PlayScene::Initialize() {
	Instantiate<Stage>(this);
	//Button* b = (Button*)Instantiate<Button>(this);
	//b->LoadFile("Image\\TestButton");
	//b->SetButtonPosition(50, 20);
	//b->SetText("Test");
	Instantiate<Player>(this);

	Camera::SetPosition({ 0.0f, 3.0f, -10.0f });
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
