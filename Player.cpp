#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

namespace {
	const float GRAVITY = 0.01f;
}

// コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), velocity_{},
	isOnFloor_(true)
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
	SphereCollider* collision = new SphereCollider(XMFLOAT3(1.0f, 0.5f, 0.5f), 0.1f);
	AddCollider(collision);
}

// 更新
void Player::Update() {
	if (Input::IsKeyDown(DIK_R) || transform_.position_.y <= -100.0f) {
		transform_.position_ = { 0.0f, 0.0f, 0.0f };
		velocity_ = { 0.0f, 0.0f, 0.0f };
		isOnFloor_ = true;
		return;
	}

	isOnFloor_ = false;
	Collision(FindObject("Stage"));

	Move();
	transform_.position_ = transform_.position_ + velocity_;

	//Camera::SetPosition({ transform_.position_.x, transform_.position_.y, transform_.position_.z - 5.0f });
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
	if (pTarget->GetObjectName() == "Stage") {
		if (velocity_.y <= 0.0f) {
			velocity_.y = 0.0f;
			isOnFloor_ = true;
		}
	}
}

void Player::Move() {
	// リセット
	velocity_.x = 0.0f;
	velocity_.z = 0.0f;

	// 左右移動
	if (Input::IsKey(DIK_D)) {
		velocity_.x += 0.1f;
	}
	if (Input::IsKey(DIK_A)) {
		velocity_.x -= 0.1f;
	}

	// 前後移動
	if (Input::IsKey(DIK_W)) {
		velocity_.z += 0.1f;
	}
	if (Input::IsKey(DIK_S)) {
		velocity_.z -= 0.1f;
	}

	if (!isOnFloor_) {
		velocity_.y -= GRAVITY;
		return;
	}

	// ジャンプ
	if (Input::IsKeyDown(DIK_SPACE)) {
		velocity_.y += 0.2f;
	}
}
