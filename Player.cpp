#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

// コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1)
{
}

// デストラクタ
Player::~Player()
{
}

// 初期化
void Player::Initialize() {
	// モデルデータのロード
	hModel_ = Model::Load("Model\\TestPlayer.fbx");
	assert(hModel_ >= 0);

	// 足元に極小の当たり判定を設定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.5f, 0.5f, 0.5f), 0.2f);
	AddCollider(collision);
}

// 更新
void Player::Update() {
	Camera::SetTarget(transform_.position_);
}

// 描画
void Player::Draw() {
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

// 開放
void Player::Release() {

}

// 何かに当たった
void Player::OnCollision(GameObject* pTarget) {

}

