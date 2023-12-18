#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

// コンストラクタ
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
}

// デストラクタ
Stage::~Stage() {

}

// 初期化
void Stage::Initialize() {
	// モデルデータのロード
	std::string fn[] = {
		"Model\\TestGround.fbx",
		"Model\\TestLowerUphill.fbx", "Model\\TestUpperUphill.fbx"
		"Model\\TestUpperDownhill.fbx", "Model\\TestLowerDownhill.fbx"
	};

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

// 更新
void Stage::Update() {

}

// 描画
void Stage::Draw() {
	Transform t;
	for (int x = 0; x < stage_.size(); x++) {
		for (int y = 0; y < stage_[x].size(); y++) {
			t.position_ = { (float)x, (float)y, 0.0f };
			//Model::SetTransform(hModel_, t);
			//Model::Draw(hModel_);
		}
	}

}

// 開放
void Stage::Release() {

}