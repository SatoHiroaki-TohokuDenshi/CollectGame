#pragma once
#include "Engine/GameObject.h"
#include <vector>

// マップのタイプ
enum MAP_TYPE {
	T_PLAYER = -1,	// プレイヤー初期位置
	T_NONE = 0,		// 何もない空間
	T_FLOOR,		// 平面の床
	T_MAX,			// 管理用番兵
};

// Stageを管理するクラス
class Stage : public GameObject {
private:
	std::vector<std::vector<int>> stage_;
	int hModel_;    //モデル番号

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