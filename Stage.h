#pragma once
#include "Engine/GameObject.h"
#include <vector>

// マップのタイプ
enum MAP_TYPE {
    T_PLAYER = -1,      // プレイヤーの初期位置
    T_AIR = 0,          // 何もない空間
    T_GROUND = 1,       // 普通の床
};

// Stageを管理するクラス
class Stage : public GameObject {
private:
    std::vector<std::vector<int>> stage_;
    int hModel_;        // モデル管理番号

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