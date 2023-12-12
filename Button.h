#pragma once
#include "Engine/GameObject.h"
#include <array>

// Buttonを管理するクラス
class Button : public GameObject {
private:
    std::array<int, 2> hPict_{ -1, -1 };     // 画像管理番号
    XMFLOAT3 position_;         // 表示位置
    XMFLOAT3 pictSize_;     // 画像サイズ

public:
    // コンストラクタ
    Button(GameObject* parent);

    // デストラクタ
    ~Button();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;

    // 読み込み
    void LoadFile(std::string fileName);

    // 位置の設定
    // 引数：左上からのピクセル数
    void SetButtonPosition(int x, int y);

    // マウスがホバーしているか
    bool IsHovered();
};