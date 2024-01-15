#pragma once
#include "Engine/GameObject.h"

// Playerを管理するクラス
class Player : public GameObject {
private:
	int hModel_;		//モデル番号

	// 移動に関係するやつ
	XMFLOAT3 velocity_;	// 移動量
	float gravity_;		// 重力加速度
	bool isJumped_;		// ジャンプしたか

	void MoveInput();	// 移動処理

public:
	// コンストラクタ
	Player(GameObject* parent);

	// デストラクタ
	~Player();

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 開放
	void Release() override;

	// 何かに当たった
	// 引数：pTarget 当たった相手
	void OnCollision(GameObject* pTarget) override;
};