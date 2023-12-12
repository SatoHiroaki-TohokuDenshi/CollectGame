#pragma once
#include "GameObject.h"


//-----------------------------------------------------------
//一番トップに来るオブジェクト
//すべてのオブジェクトは、これの子孫になる
//-----------------------------------------------------------
class RootObject :	public GameObject {
private:

public:
	RootObject();
	~RootObject();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

