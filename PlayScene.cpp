#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include "Button.h"
#include "Engine/Camera.h"

// �R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

// ������
void PlayScene::Initialize() {
	Instantiate<Stage>(this);
	//Button* b = (Button*)Instantiate<Button>(this);
	//b->LoadFile("Image\\TestButton");
	//b->SetButtonPosition(50, 20);
	//b->SetText("Test");
	Instantiate<Player>(this);

	Camera::SetPosition({ 0.0f, 3.0f, -10.0f });
}

// �X�V
void PlayScene::Update() {

}

// �`��
void PlayScene::Draw() {

}

// �J��
void PlayScene::Release() {

}
