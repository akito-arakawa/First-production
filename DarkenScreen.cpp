#include "DxLib.h"


void DarkenScreen()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // 半透明のブレンドモードに設定
    DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE); // 画面全体に半透明の黒い矩形を描画
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを元に戻す
}
