#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

// コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), velocity_(0.0f, 0.0f, 0.0f),
	isJumped_(false), gravity_(0.01f)
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
	// デバッグ用リセットコード
	if (Input::IsKeyDown(DIK_R)) {
		transform_.position_ = { 0.0f, 0.0f, 0.0f };
		velocity_ = { 0.0f, 0.0f, 0.0f };
		isJumped_ = false;
		return;
	}


	MoveInput();
	transform_.position_ = transform_.position_ + velocity_;

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
	//ステージ
	if (pTarget->GetObjectName() == "Stage") {
		isJumped_ = false;
		velocity_.y = 0.0f;
	}
}

void Player::MoveInput() {
	velocity_.x = 0.0f;
	velocity_.z = 0.0f;

	// 前後移動
	if (Input::IsKey(DIK_S)) {	// 左
		velocity_.z += -0.1f;
	}
	if (Input::IsKey(DIK_W)) {	// 右
		velocity_.z += 0.1f;
	}

	// 左右移動
	if (Input::IsKey(DIK_A)) {	// 左
		velocity_.x += -0.1f;
	}
	if (Input::IsKey(DIK_D)) {	// 右
		velocity_.x += 0.1f;
	}

	// ジャンプしてたら落下処理して終わり
	if (isJumped_) {
		velocity_.y -= gravity_;
		return;
	}
	if (Input::IsKey(DIK_SPACE)) {
		velocity_.y = 0.25f;
		isJumped_ = true;
	}
}
