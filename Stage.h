#pragma once
#include "Engine/GameObject.h"
#include <vector>

// マップのタイプ
enum MAP_TYPE {
	T_PLAYER = -1,      // プレイヤーの初期位置
	T_AIR = 0,          // 何もない空間
	T_GROUND = 1,       // 普通の床 : 1
	T_LUPHILL,          // 下付き上り坂 : 2
	T_UUPHILL,          // 上付き上り坂 : 3
	T_UDOWNHILL,		// 上付き下り坂 : 4
	T_LDOWNHILL,		// 下付き下り坂 : 5
	T_MAX,				// 管理用番兵
};

// Stageを管理するクラス
class Stage : public GameObject {
private:
	std::vector<std::vector<int>> stage_;
	std::vector<int> hModel_;        // モデル管理番号

public:
	// コンストラクタ
	Stage(GameObject* parent);

	// デストラクタ
	~Stage();

	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 開放
	void Release() override;
};