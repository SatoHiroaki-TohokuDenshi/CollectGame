#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Engine/BoxCollider.h"

// �R���X�g���N�^
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hModel_(-1)
{
}

// �f�X�g���N�^
Stage::~Stage() {

}

// ������
void Stage::Initialize() {
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\TestGround.fbx");
	assert(hModel_ >= 0);

	CsvReader csv;
	csv.Load("TestMap.csv");

	stage_.resize(csv.GetHeight());
	for (int y = 0; y < csv.GetHeight(); y++) {
		stage_[y].resize(csv.GetWidth());
		for (int x = 0; x < csv.GetWidth(); x++) {
			stage_[y][x] = csv.GetValue(y, x);
			BoxCollider* collision = new BoxCollider(XMFLOAT3((float)x + 0.5f, -0.5f, (float)y + 0.5f), XMFLOAT3(1, 1, 1));
			AddCollider(collision);
		}
	}
}

// �X�V
void Stage::Update() {

}

// �`��
void Stage::Draw() {
	Transform t;
	for (int y = 0; y < stage_.size(); y++) {
		for (int x = 0; x < stage_[y].size(); x++) {
			t.position_ = { (float)x, 0.0f, (float)y };
			Model::SetTransform(hModel_, t);
			Model::Draw(hModel_);
		}
	}
}

// �J��
void Stage::Release() {

}