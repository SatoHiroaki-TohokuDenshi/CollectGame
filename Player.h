#pragma once
#include "Engine/GameObject.h"

// Playerを管理するクラス
class Player : public GameObject {
private:
	enum class ACTION_STATE {
		IDLE,		// 0:操作無し、待機
		WALK,		// 1:歩く
		DASH,		// 2:走る
		AIR,		// 3:空中（ジャンプ、落下等）
		LANDING,	// 4:着地
		MAX			// 5:番兵
	} state_;

	int hModel_;		//モデル番号

	void Move();			// 移動処理
	XMFLOAT3 velocity_;		// 移動量
	bool isOnFloor_;		// 床の上にいるか

	//State：状態による処理
	void UpdateIdle();
	void UpdateWalk();
	void UpdateDash();
	void UpdateAir();
	void UpdateLanding();

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