#include "DxLib.h"



void DarkenScreen();

/* -------------------------------------------------------------------------- */
/* 関数名：Dog_Push_ans                                                       */
/* 機  能：犬がクリックされたときに画像を大きくして吠える                     */
/* 戻り値：なし                                                               */
/* 引  数：なし                                                               */
/* -------------------------------------------------------------------------- */
void Dog_Push_ans(int n, int *p)
{
    int Cr1 = GetColor(255, 255, 255);//白
    int Cr2 = GetColor(255, 0, 0);//赤

    int dog;///画像格納用
    dog = LoadGraph("dog.png");//犬の画像
    int cat;///画像格納用
    cat = LoadGraph("cat.png");//犬の画像
    int chicken;//画像格納用
    chicken = LoadGraph("chicken.png"); //ニワトリの画像
    int elephant;//画像格納用
    elephant = LoadGraph("elephant.png");//象の画像
    int scoreicon;//画像格納用
    scoreicon = LoadGraph("score.png");//背景の画像
    int zuu;//画像格納用
    zuu = LoadGraph("zuu.png");//背景の画像
    int DogSound;
    DogSound = LoadSoundMem("犬の鳴き声.mp3");

    // 描画先画面を裏にする
    SetDrawScreen(DX_SCREEN_BACK);

    ClearDrawScreen();//画面クリア、画面の削除

    SetBackgroundColor(110, 113, 101);//背景の色変更


   

    DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE); // 背景の画像


    //---------------- - 円-------------------------- /
    DrawCircle(1260, 250, 200, Cr1);     //右上の円
    DrawCircle(660, 250, 200, Cr2);      //左上の円
    DrawCircle(1260, 830, 200, Cr1);     //右下の円
    DrawCircle(660, 830, 200, Cr1);      //左下の円

    DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE); // 猫の画像
    DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE); // 鶏の画像
    DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // 像の画像




    DrawRotaGraph(660, 250, 2.5, 0.0, dog, TRUE); // 犬の画像

    

    if (*p == 0) {
        ChangeVolumeSoundMem(80, DogSound);
        PlaySoundFile("犬の鳴き声.mp3", DX_PLAYTYPE_BACK);     //犬の音声
      
    }
    else if (*p == 1) {
        ChangeVolumeSoundMem(0, DogSound);
    }

    DarkenScreen();



    DrawBox(45, 8, 230, 95, Cr1, TRUE);//プレイ下のしかく
    DrawCircle(45, 51.5, 43.5, Cr1);     //右上の円
    DrawCircle(230, 51.5, 43.5, Cr1);     //右上の円
    SetFontSize(70);//文字のサイズの設定
    DrawFormatString(175, 20, (0, 0, 0), "%d", n - 1);

    DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE); // iconの画像

    // 裏画面の内容を表画面に反映します
    ScreenFlip();

    WaitTimer(300);//処理を300ミリ秒止める
}