#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

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
	// ���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\TestGround.fbx");
	assert(hModel_ >= 0);

	CsvReader csv;
	csv.Load("TestMap.csv");

	stage_.resize(csv.GetWidth());
	for (int x = 0; x < stage_.size(); x++) {
		stage_[x].resize(csv.GetWidth());
		for (int y = 0; y < stage_[x].size(); y++) {
			stage_[x][y] = csv.GetValue(x, y);
		}
	}
}

// �X�V
void Stage::Update() {

}

// �`��
void Stage::Draw() {
	Transform t;
	for (int x = 0; x < stage_.size(); x++) {
		for (int y = 0; y < stage_[x].size(); y++) {
			t.position_ = { (float)x, (float)y, 0.0f };
			Model::SetTransform(hModel_, t);
			Model::Draw(hModel_);
		}
	}

}

// �J��
void Stage::Release() {

}