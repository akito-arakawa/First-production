#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include "kioku_1.h"


//---------- グローバル変数---------------------------//
// 
//マウスについての変数
int MouseX = 0;                     //マウスのX座標
int MouseY = 0;                     //マウスのY座標


//-------------ゲーム内で使う色----------------------//
int Cr1 = GetColor(255, 255, 255);          //白
int Cr2 = GetColor(255, 0, 0);              //赤
int Cr3 = GetColor(125, 153, 104);          //緑
int Cr4 = GetColor(173, 212, 144);          //薄緑
int Cr5 = GetColor(0, 0, 0);                //黒
//---------------------------------------------------//
int max;                //マックススコア
int p = 0;              //サウンド切り替え


//-----------------------------------------------------//

// 仮のウィンドウハンドルとしてNULLを使用
HWND hwnd = GetForegroundWindow();

//プロトタイプ宣言
void kioku_start(int* p);             //スタート画面
void Kioku(int* p);                   //メインゲーム
void DarkenScreen();                  //ダークスクリーン
void Print_Score(int n, int* p);      //スコア画面
void Game_Rule(void);                 //ルール説明


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    SetBackgroundColor(221, 229, 205);                  //背景の色変更


    SetGraphMode(1920, 1080, 32);                       //画面解像度1920×1080
    SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);



    if (DxLib_Init() == -1)     // ＤＸライブラリ初期化処理
    {
        return -1;              // エラーが起きたら直ちに終了
    }


    //ゲーム開始画面
    kioku_start(&p);


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {//エスケープキーが押されるまで

        //メイン画面
        Kioku(&p);

    }

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;           // ソフトの終了
}

/* -------------------------------------------------------------------------- */
/* 関数名：kioku_start                                                        */
/* 機  能：スタート画面　　　　　　　　　　　　　　　　　                     */
/* 戻り値：なし                                                               */
/* 引  数：int *p: ミュート切り替え                                           */
/* -------------------------------------------------------------------------- */
void kioku_start(int* p)
{

    int edgeinput;                //マウス入力を格納変数
    SetMouseDispFlag(TRUE);       //マウスを表示する



    //-------------------------ゲーム内画像--------------------------------//
    int dog;                                //犬の画像格納用
    dog = LoadGraph("dog.png");             //犬の画像

    int cat;                                //猫の画像格納用
    cat = LoadGraph("cat.png");             //猫の画像

    int chicken;                            //ニワトリの画像格納用
    chicken = LoadGraph("chicken.png");     //ニワトリの画像

    int elephant;                           //象の画像格納用
    elephant = LoadGraph("elephant.png");   //象の画像

    int zuu;                                //背景の画像格納用
    zuu = LoadGraph("zuu.png");             //背景の画像

    int PLAY;                               //Playボタン画像格納用
    PLAY = LoadGraph("PLAY.png");           //Playボタンの画像

    int PLAY_Puch;                          //Playボタン押したときの画像格納用
    PLAY_Puch = LoadGraph("PLAY_Puch.png"); //Playボタン押したときの画像

    int Speaker;                            //サウンドの画像格納用
    Speaker = LoadGraph("mugic.png");       //サウンドの画像

    int Speaker2;                           //サウンド押したとき画像格納用
    Speaker2 = LoadGraph("mug2.png");       //サウンド押したとき終了の画像

    int batu;                                   //終了ボタンの画像格納用
    batu = LoadGraph("batu.png");               //終了ボタンの画像


    int book;                                   //本ボタンの画像格納用
    book = LoadGraph("books.png");               //本ボタンの画像

    int Rule;                                   //ルールボタン1の画像格納用
    Rule = LoadGraph("Rule.png");               //ルールボタン1の画像

    //----------ゲーム内サウンド-------------//
    int SHandle;                            //ホーム内の音声格納用
    SHandle = LoadSoundMem("home.wav");     //ホーム内音声

    int PlaySound1;                         //startボタンの音声格納用
    PlaySound1 = LoadSoundMem("start.wav"); //startボタン音声


    time_t t;  //タイムがの変数 

    //ゲーム内音量調節
    ChangeVolumeSoundMem(100, SHandle);         //ホーム内音声調節                      
    ChangeVolumeSoundMem(125, PlaySound1);      //Playボタン音声調節

    PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);     //ホーム内の音声


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {       //エスケープキーが押されるまで

        edgeinput = GetMouseInput();                //マウスの入力を取得したら1を代入
        GetMousePoint(&MouseX, &MouseY);            //マウスの座標

        ClearDrawScreen();                          //画面クリア、画面の削除


        //---------------------------表示するモノ--------------------------------------//
        DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);       // 背景の画像

        DrawCircle(240, 340, 200, Cr1);                     //右上の円
        DrawCircle(720, 340, 200, Cr1);                     //左上の円
        DrawCircle(1200, 340, 200, Cr1);                    //右下の円
        DrawCircle(1680, 340, 200, Cr1);                    //左下の円

        DrawRotaGraph(240, 340, 1.8, 0.0, dog, TRUE);       // 犬の画像
        DrawRotaGraph(720, 340, 1.5, 0.0, cat, TRUE);       // 猫の画像
        DrawRotaGraph(1200, 340, 1.5, 0.0, chicken, TRUE);  // 鶏の画像
        DrawRotaGraph(1680, 340, 1.2, 0.0, elephant, TRUE); // 像の画像
        DrawRotaGraph(960, 650, 0.2, 0.0, PLAY, TRUE);      // スタートの画像

        DrawCircle(1725, 65, 40, Cr5);     //スピーカーボタンの下の円

        //スピーカーの画像がクリックされたら画像がミュートの画像になる
        if (*p == 1) {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE); //スピーカー(ON)の画像

        }
        else {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE); //スピーカー(OFF)の画像
        }

        DrawCircle(1825, 65, 40, Cr5);     //終了ボタンの下の円
        DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // 終了の画像

        DrawCircle(100, 70, 70, Cr5);                    //左下の円

        DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ルールの画像


      

        //マウスカーソルがstartボタンの範囲に入った場合(startボタンを大きくする）
        if (MouseX > 770 && MouseX < 1130 && MouseY > 600 && MouseY < 700) {

            ClearDrawScreen();        //画面クリア、画面の削除


            DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);       // 背景の画像


            DrawCircle(240, 340, 200, Cr1);      //右上の円
            DrawCircle(720, 340, 200, Cr1);      //左上の円
            DrawCircle(1200, 340, 200, Cr1);     //右下の円
            DrawCircle(1680, 340, 200, Cr1);     //左下の円


            DrawCircle(1825, 65, 40, Cr5);     //終了ボタンの下の円
            DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // 終了の画像

            DrawRotaGraph(240, 340, 1.8, 0.0, dog, TRUE);        // 犬の画像
            DrawRotaGraph(720, 340, 1.5, 0.0, cat, TRUE);        // 猫の画像
            DrawRotaGraph(1200, 340, 1.5, 0.0, chicken, TRUE);   // 鶏の画像
            DrawRotaGraph(1680, 340, 1.2, 0.0, elephant, TRUE);  // 像の画像
            DrawRotaGraph(950, 650, 0.2, 0.0, PLAY_Puch, TRUE);  // スタートの画像

            DrawCircle(100, 70, 70, Cr5);                    //左上の円
            DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ルールの画像


            DrawCircle(1725, 65, 40, Cr5);     //スピーカーボタンの下の円

            //スピーカーの画像がクリックされたら画像がミュートの画像になる
            if (*p == 1) {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE); //スピーカー(ON)の画像

            }
            else {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE); //スピーカー(OFF)の画像
            }
        }



        //右クリック判定
        if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {

            //サウンドボタンがクリック
            if (MouseX > 1685 && MouseX < 1765 && MouseY > 25 && MouseY < 100) {

                if (*p == 1) {          //サウンド(ON)
                    ChangeVolumeSoundMem(100, SHandle);     //ホーム音声
                    ChangeVolumeSoundMem(125, PlaySound1);  //Play音声
                    *p = 0;
                }
                else {                  //サウンド(OFF)
                    ChangeVolumeSoundMem(0, SHandle);       //ホーム音声
                    ChangeVolumeSoundMem(0, PlaySound1);    //Play音声
                    *p = 1;
                }
                WaitTimer(200);         //処理を200ミリ秒止める

            }


            //終了ボタンがクリック
            if (MouseX > 1785 && MouseX < 1865 && MouseY > 25 && MouseY < 100) {

                WaitTimer(300);        //処理を300ミリ秒止める

                DxLib_End();           // ＤＸライブラリ使用の終了処理（強制終了）
            }

            //PLAYボタンが押されたか判断
            if (MouseX > 770 && MouseX < 1130 && MouseY > 600 && MouseY < 700) {


                PlaySoundMem(PlaySound1, DX_PLAYTYPE_BACK);     //startの音声
                DeleteSoundMem(SHandle);                        //startの音声消去




                WaitTimer(300);         //処理を300ミリ秒止める

                SetBackgroundColor(139, 224, 210);  //背景の色変更

                //ゲームカウント
                PlayMovie("Kioku_Play.mp4", 1, DX_MOVIEPLAYTYPE_NORMAL);


                break;
            }

            if (MouseX > 30 && MouseX < 170 && MouseY > 0 && MouseY < 140) {
                Game_Rule();//ルール説明の関数

            }


        }


    }




}

/* -------------------------------------------------------------------------- */
/* 関数名：Game_Rule                                                          */
/* 機  能：ルール画面　　　　　　　　　　　　　　　　　　                     */
/* 戻り値：なし                                                               */
/* 引  数：なし　                                                             */
/* -------------------------------------------------------------------------- */

void Game_Rule(void)
{

    int edgeinput;                //マウス入力を格納変数
    SetMouseDispFlag(TRUE);       //マウスを表示する


    int home_Name;                                           //ノーマル名前画面の画像格納用
    home_Name = LoadGraph("home_Name.png");                  //ノーマル名前画像の画像

    int Hito_home_Name;                                      //ノーマル名前画面の画像格納用
    Hito_home_Name = LoadGraph("Hito_home_Name.png");        //ノーマル名前画像の画像

    int home;                                                //ノーマル画面の画像格納用
    home = LoadGraph("home.png");                            //ノーマル画像の画像

    int home_score;                                          //ノーマルスコア画面の画像格納用
    home_score = LoadGraph("Home_Score.png");                //ノーマルスコア画像の画像

    int home_Red;                                            //動物赤になる画像の画像格納用
    home_Red = LoadGraph("home_Red.png");                    //動物赤になる画像の画像

    int home_Red_Push;                                       //動物赤になるクリック画像の画像格納用
    home_Red_Push = LoadGraph("home_Red_Push.png");          //動物赤になるクリック画像の画像

    int Hito_home_Ru_ru;                                     //ルールの画像の画像格納用
    Hito_home_Ru_ru = LoadGraph("Hito_home_Ru-ru.png");      //ルールの画像の画像

    int Hito_home_Strat;                                     //動物赤になるクリック画像の画像格納用
    Hito_home_Strat = LoadGraph("Hito_home_Strat.png");      //動物赤になるクリック画像の画像

    int Hito_home_Red;                                       //動物赤になるクリック画像の画像格納用
    Hito_home_Red = LoadGraph("Hito_home_Red.png");          //動物赤になるクリック画像の画像

    int Hito_home_Red_Push;                                  //動物赤になるクリック画像の画像格納用
    Hito_home_Red_Push = LoadGraph("Hito_home_Red_Push.png"); //動物赤になるクリック画像の画像

    int Hito_home_score;                                     //動物赤になるクリック画像の画像格納用
    Hito_home_score = LoadGraph("Hito_home_score.png");      //動物赤になるクリック画像の画像

    int Next;                       //次へ画像格納用
    Next = LoadGraph("Next.png");   //次への画像

    int Return;                     //前への画像格納用
    Return = LoadGraph("Return.png");//前への画像


    int skip;                   //スキップのボタン格納用
    skip = LoadGraph("Skip.png");//スキップのボタン

    int home1;//ホームに戻る
    home1 = LoadGraph("HOME_return.png");//ホームに戻る画像

    int i = 0;//ループカウンタ

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {       //エスケープキーが押されるまで

        // 描画先画面を裏にする
       // SetDrawScreen(DX_SCREEN_BACK);

        ClearDrawScreen();      //画面クリア、画面の削除

        edgeinput = GetMouseInput();                //マウスの入力を取得したら1を代入
        GetMousePoint(&MouseX, &MouseY);            //マウスの座標

        SetFontSize(60);         //文字のサイズの設定

        switch (i) {
        case 0:


            DrawRotaGraph(768, 432, 0.8, 0.0, home_Name, TRUE);      // ノーマルの画像
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Name, TRUE);      // 動物４つの名前のやつ画像

            break;

        case 1:


            DrawRotaGraph(768, 432, 0.8, 0.0, home_Red, TRUE);      // 動物赤の画像
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Red, TRUE);      // 動物赤クリックひと画像

            break;
        case 2:

            DrawRotaGraph(768, 432, 0.8, 0.0, home, TRUE);      // ノーマルの画像
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Strat, TRUE);      // 動物赤クリックひと画像

            break;
        case 3:

            DrawRotaGraph(768, 432, 0.8, 0.0, home_Red_Push, TRUE);      // 動物赤クリック画像
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Red_Push, TRUE);      // 動物赤クリックひと画像

            break;
        case 4:

            DrawRotaGraph(768, 432, 0.8, 0.0, home_Red_Push, TRUE);      // 動物赤クリック画像
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Ru_ru, TRUE);      // 動物赤クリックひと画像

            break;
        case 5:

            DrawRotaGraph(708, 432, 1.0, 0.0, home_score, TRUE);      // スコア画面の画像
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_score, TRUE);      // 動物赤クリックひと画像

            break;

        }

        DrawRotaGraph(1110, 950, 1.5, 0.0, Next, TRUE);      // 次への画像

        if (i >= 1) {
            DrawRotaGraph(810, 950, 1.5, 0.0, Return, TRUE);      // 前への画像

        }

        if (i < 5) {
            DrawRotaGraph(1800, 50, 1.5, 0.0, skip, TRUE);      // スキップのボタンの画像

        }

        if (i >= 5) {
            DrawRotaGraph(1110, 950, 1.5, 0.0, home1, TRUE);      // 前への画像
        }

        SetFontSize(30);         //文字のサイズの設定

        DrawFormatString(915, 1010, (0, 0, 0), "%d / 6", i + 1);   //現在ページ数



        //右クリック判定
        if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {

            //次へボタンが押されたか判断
            if (MouseX > 1000 && MouseX < 1210 && MouseY > 920 && MouseY < 980) {
                i++;



                WaitTimer(300);         //処理を300ミリ秒止める



            }
            //戻るボタンが押されたとき
            if (MouseX > 700 && MouseX < 920 && MouseY > 915 && MouseY < 980) {
                i--;

                //0以下にならないように
                if (i <= 0) {
                    i = 0;
                }

                WaitTimer(300);         //処理を300ミリ秒止める

            }

            if (MouseX > 1695 && MouseX < 1900 && MouseY > 15 && MouseY < 80) {

                WaitTimer(300);         //処理を300ミリ秒止める

                break;

            }

            if (MouseX > 970 && MouseX < 1230 && MouseY > 918 && MouseY < 980 && i >= 6) {

                WaitTimer(300);         //処理を300ミリ秒止める

                break;//ルール終了

            }

        }


        // 裏画面の内容を表画面に反映します
       // ScreenFlip();


    }
}


/* -------------------------------------------------------------------------- */
/* 関数名：Kioku                                                              */
/* 機  能：メイン画面　　　　　　　　　　　　　　　　　　                     */
/* 戻り値：なし                                                               */
/* 引  数：int *p: ミュート切り替え                                           */
/* -------------------------------------------------------------------------- */
void Kioku(int* p)
{
    int edgeinput;     //マウス入力を格納変数

    int i = 0;         //ループカウンタ
    int j = 0;         //ループカウンタ


    //---------------------ゲーム内画像---------------------------------//
    int dog;                                //犬の画像格納用
    dog = LoadGraph("dog.png");             //犬の画像

    int cat;                                //猫の画像格納用
    cat = LoadGraph("cat.png");             //猫の画像

    int chicken;                            //ニワトリの画像格納用
    chicken = LoadGraph("chicken.png");     //ニワトリの画像

    int elephant;                           //象の画像格納用
    elephant = LoadGraph("elephant.png");   //象の画像

    int zuu;                                //背景の画像格納用
    zuu = LoadGraph("zuu.png");             //背景の画像

    int scoreicon;                          //スコア背景の画像格納用
    scoreicon = LoadGraph("score.png");     //スコア背景の画像

    int Speaker;                            //スピーカー(ON)の画像格納用
    Speaker = LoadGraph("mugic.png");       //スピーカー(ON)の画像

    int Speaker2;                           //スピーカー(OFF)の画像格納用
    Speaker2 = LoadGraph("mug2.png");       //スピーカー(OFF)の画像

    int kuri;                               //クリックの画像格納用
    kuri = LoadGraph("kuri.png");           //クリックの画像


    //--------------難易度設定------------------------//
    int ans[10][10];                //ランド関数で返された値を格納する
    int player[10][10];             //プレイヤーがクリックしたときに配列に格納される
    int count = 1;                  //難易度カウント

    bool flag = true;               //ゲームループ

    SetMouseDispFlag(TRUE);         //マウスを表示する

    time_t t;   //時間型の変数 

    double r = 170;     //円をお菊する変数



    //10回連続で押せるまで継続
    for (count = 1; count <= 10; count++) {

        // フレームレートの制御
        Sleep(16); // 60FPSを想定

        srand((unsigned int)time(NULL));         // 現在時刻の情報で初期化  ランド関数の初期化

        //ランダム処理
        for (i = count - 1; i < count; i++) {
            for (j = 0; j < count; j++) {

                switch (rand() % 4 + 1) {

                case 1: //犬   
                    Dog_Push_ans(count, p);      //犬がクリックされたときに画像を大きくして吠える
                    ans[i][j] = 1;               //答えの変数のcount番目のi個目に1を代入

                    break;
                case 2: //猫
                    Cat_Push_ans(count, p);      //猫がクリックされたときに画像を大きくして吠える
                    ans[i][j] = 2;               //答えの変数のcount番目のi個目に2を代入

                    break;
                case 3: //ニワトリ
                    Chicken_Push_ans(count, p);  //鶏がクリックされたときに画像を大きくして吠える
                    ans[i][j] = 3;               //答えの変数のcount番目のi個目に3を代入

                    break;
                case 4: //象
                    Elephant_Puch_ans(count, p); //像がクリックされたときに画像を大きくして吠える
                    ans[i][j] = 4;               //答えの変数のcount番目のi個目に4を代入

                    break;
                }

                // 描画先画面を裏にする
                SetDrawScreen(DX_SCREEN_BACK);

                SetBackgroundColor(110, 113, 101);//背景の色変更

                ClearDrawScreen();//画面クリア、画面の削除

                DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE); // 背景の画像


                //---------------- - 円-------------------------- /
                DrawCircle(1260, 250, 200, Cr1);     //右上の円
                DrawCircle(660, 250, 200, Cr1);      //左上の円
                DrawCircle(1260, 830, 200, Cr1);     //右下の円
                DrawCircle(660, 830, 200, Cr1);      //左下の円

                DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE); // 犬の画像
                DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE); // 猫の画像
                DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE);    // 鶏の画像
                DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // 像の画像

                DarkenScreen();



                DrawBox(45, 8, 230, 95, Cr1, TRUE);//プレイ下のしかく
                DrawCircle(45, 51.5, 43.5, Cr1);     //右上の円
                DrawCircle(230, 51.5, 43.5, Cr1);     //右上の円
                SetFontSize(70);//文字のサイズの設定
                DrawFormatString(175, 20, (0, 0, 0), "%d", count - 1);

                DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE); // iconの画像


                // 裏画面の内容を表画面に反映します
                ScreenFlip();



                WaitTimer(300);     //処理を300ミリ秒止める

            }
        }

        SetBackgroundColor(221, 229, 205);  //背景の色変更



        t = time(NULL);//現在の時間を取得


        //ユーザ側入力ループ
        for (i = count - 1; i < count; i++) {
            for (j = 0; j < count; ) {

                // 描画先画面を表にする
                SetDrawScreen(DX_SCREEN_FRONT);

                edgeinput = GetMouseInput();        //マウスの入力を取得したら1を代入
                GetMousePoint(&MouseX, &MouseY);    //マウスの座標

                ClearDrawScreen();                  //画面クリア、画面の削除

                //----------------------表示させるモノ------------------------//
                DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);        // 背景の画像

                DrawCircle(1260, 250, 200, Cr1);     //右上の円
                DrawCircle(660, 250, 200, Cr1);      //左上の円
                DrawCircle(1260, 830, 200, Cr1);     //右下の円
                DrawCircle(660, 830, 200, Cr1);      //左下の円

                DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE);        // 犬の画像
                DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE);       // 猫の画像
                DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE);    // 鶏の画像
                DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE);  // 像の画像

                //DrawFormatString(1000, 0, (255, 255, 255), "%d", ans[i][j]);//ヒント

                DrawBox(45, 8, 230, 95, Cr1, TRUE);     //プレイ下のしかく
                DrawCircle(45, 51.5, 43.5, Cr1);        //右上の円
                DrawCircle(230, 51.5, 43.5, Cr1);       //右上の円

                SetFontSize(70);    //文字のサイズの設定
                DrawFormatString(175, 20, (0, 0, 0), "%d", count - 1);   //現在の押せた回数
                DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE);        // スコアアイコンの画像



                //1回目の入力で3秒経過したら押すところ表示
                if ((time(NULL) - t) >= 3 && i == 0) {

                    r = r + 0.5;//円を大きくする

                    //1回目のとき
                    switch (ans[0][0]) {
                    case 1://犬
                        DrawCircle(660, 250, r, Cr2);      //左上の円
                        DrawCircle(660, 250, 200, Cr1);    //左上の円

                        DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE);    // 犬の画像
                        DrawRotaGraph(660, 350, 2.5, 0.0, kuri, TRUE);   // クリック画像

                        break;
                    case 2://猫
                        DrawCircle(1260, 250, r, Cr2);       //右上の円   
                        DrawCircle(1260, 250, 200, Cr1);     //右上の円

                        DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE);   // 猫の画像
                        DrawRotaGraph(1260, 350, 2.5, 0.0, kuri, TRUE);  // クリック画像

                        break;
                    case 3://鶏
                        DrawCircle(660, 830, r, Cr2);        //左下の円
                        DrawCircle(660, 830, 200, Cr1);      //左下の円

                        DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE); // 鶏の画像
                        DrawRotaGraph(660, 930, 2.5, 0.0, kuri, TRUE);    // クリック画像

                        break;
                    case 4://象
                        DrawCircle(1260, 830, r, Cr2);       //右下の円
                        DrawCircle(1260, 830, 200, Cr1);     //右下の円

                        DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // 像の画像
                        DrawRotaGraph(1260, 930, 2.5, 0.0, kuri, TRUE);     // クリック画像

                        break;
                    }
                }

                //円が220になったら円を初期化
                if (r >= 220) {
                    r = 170;
                }

                //-------------------------動物の右クリック判定----------------------------------//
                  //犬がクリックされたとき
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 460 && MouseX < 860 && MouseY > 50 && MouseY < 550) {

                        Dog_Push(count, p);     //犬がクリックされたときに画像を大きくして吠える

                        player[i][j] = 1;       //クリックされた動物の数字を格納

                        //入力結果判断
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;      //ゲーム抜ける処理
                            break;
                        }

                    }
                }
                //猫がクリックされたか
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 1060 && MouseX < 1460 && MouseY > 50 && MouseY < 550) {

                        Cat_Push(count, p);    //猫がクリックされたときに画像を大きくして吠える

                        player[i][j] = 2;      //クリックされた動物の数字を格納

                        //入力結果判断
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;      //ゲーム抜ける処理
                            break;
                        }

                    }
                }

                //鶏がクリックされたとき
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 460 && MouseX < 860 && MouseY >  630 && MouseY < 1030) {

                        Chicken_Push(count, p); //鶏がクリックされたときに画像を大きくして吠える

                        player[i][j] = 3;       //クリックされた動物の数字を格納

                        //入力結果判断
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;      //ゲーム抜ける処理
                            break;
                        }

                    }
                }
                //象がクリックされたとき
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 1060 && MouseX < 1460 && MouseY > 630 && MouseY < 1030) {

                        Elephant_Puch(count, p);//象がクリックされたときに画像を大きくして吠える

                        player[i][j] = 4;       //クリックされた動物の数字を格納

                        //入力結果判断
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;       //ゲーム抜ける処理
                            break;

                        }

                    }
                }

                //ミュートボタンが押されたか判断
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 1785 && MouseX < 1845 && MouseY > 35 && MouseY < 95) {

                        WaitTimer(200);        //処理を100ミリ秒止める

                    }

                }

            }

        }



        // 描画先画面を表にする
        SetDrawScreen(DX_SCREEN_FRONT);

        ClearDrawScreen();                          //画面クリア、画面の削除

        DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE); // 背景の画像



        //---------------- - 円-------------------------- /
        DrawCircle(1260, 250, 200, Cr1);     //右上の円
        DrawCircle(660, 250, 200, Cr1);      //左上の円
        DrawCircle(1260, 830, 200, Cr1);     //右下の円
        DrawCircle(660, 830, 200, Cr1);      //左下の円

        DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE); // 犬の画像
        DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE); // 猫の画像
        DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE); // 鶏の画像
        DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // 像の画像

        DrawBox(45, 8, 230, 95, Cr1, TRUE);//プレイ下のしかく
        DrawCircle(45, 51.5, 43.5, Cr1);     //右上の円
        DrawCircle(230, 51.5, 43.5, Cr1);     //右上の円
        SetFontSize(70);//文字のサイズの設定
        DrawFormatString(175, 20, (0, 0, 0), "%d", count - 1);

        DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE); // iconの画像

        //------------//


        WaitTimer(500);//処理を500ミリ秒止める



        //ゲーム終了
        if (!flag) {
            Print_Score(count, p);      //スコア画面へ

            break;
        }


    }
}

/* -------------------------------------------------------------------------- */
/* 関数名：Print_Score                                                        */
/* 機  能：スコア画面　　　　　　　　　　　　　　　　　　                     */
/* 戻り値：なし                                                               */
/* 引  数：int n: スコア　　　　　　                                          */
/* 引  数：int *p: ミュート切り替え                                           */
/* -------------------------------------------------------------------------- */
void Print_Score(int n, int* p)
{
    //-------------------------ゲーム内画像---------------------------//
    int hai;                                     //スコア背景の画像格納用
    hai = LoadGraph("hai.png");                  //スコア背景の画像

    int scoreicon;                              //スコアの画像格納用
    scoreicon = LoadGraph("score.png");         //スコアの画像

    int maxscoreicon;                           //マックススコア画像格納用
    maxscoreicon = LoadGraph("maxscore.png");   //マックススコアの画像

    int rod;                                    //画像格納用
    rod = LoadGraph("rod.png");                 //もう一度ボタンの画像

    int zuu;                                    //背景の画像格納用
    zuu = LoadGraph("zuu.png");                 //背景の画像

    int batu;                                   //終了ボタンの画像格納用
    batu = LoadGraph("batu.png");               //終了ボタンの画像

    int Speaker;                                //スピーカー(ON)の画像格納用
    Speaker = LoadGraph("mugic.png");           //スピーカー(ON)の画像

    int Speaker2;                               //スピーカー(OFF)画像格納用
    Speaker2 = LoadGraph("mug2.png");           //スピーカー(OFF)の画像

    //--------------ゲーム内サウンド------------------------//
    int SHandle;                                //ホーム音声格納用
    SHandle = LoadSoundMem("home.wav");         //ホーム音声

    int PlaySound1;                             //Play音声格納用
    PlaySound1 = LoadSoundMem("start.wav");     //Play音声

    int book;                                   //本ボタンの画像格納用
    book = LoadGraph("books.png");               //本ボタンの画像

    //音量切り替え
    if (*p == 0) {              //スピーカー(ON)
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);    //ホーム音声

        ChangeVolumeSoundMem(125, SHandle);         //ホームの音量
        ChangeVolumeSoundMem(125, PlaySound1);      //Playボタンの音量
    }
    else if (*p == 1) {        //スピーカー(OFF)
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);    //ホーム音声

        ChangeVolumeSoundMem(0, SHandle);           //ホームの音量
        ChangeVolumeSoundMem(0, PlaySound1);        //Playボタンの音量
    }


    int edgeinput;                      //マウス入力を格納変数
    SetMouseDispFlag(TRUE);             //マウスを表示する


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {//エスケープキーが押されるまで


        edgeinput = GetMouseInput();            //マウスの入力を取得したら1を代入
        GetMousePoint(&MouseX, &MouseY);        //マウスの座標

        ClearDrawScreen();                      //画面クリア、画面の削除

        //-------------------ゲーム内表示させるモノ---------------------//
        DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);            // 背景の画像
        DrawRotaGraph(960, 300, 1.5, 0.0, hai, TRUE);            //スコア背景の画像
        DrawRotaGraph(800, 200, 1.1, 0.0, scoreicon, TRUE);      //スコアの画像
        DrawRotaGraph(1080, 200, 1.0, 0.0, maxscoreicon, TRUE);  //マックススコアの画像

        DrawCircle(1825, 65, 40, Cr5);     //終了ボタンの下の円
        DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // 終了の画像

        DrawBox(740, 670, 1155, 785, Cr3, TRUE);                 //プレイ下のしかく

        DrawCircle(100, 70, 70, Cr5);                    //左上の円
        DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ルールの画像



        SetFontSize(46);         //文字のサイズの設定
        DrawString(810, 705, "もう一度プレイ", Cr1);

        //maxスコア比較
        if (max < n - 1) {
            max = n - 1;
        }
        SetFontSize(90);        //文字のサイズの設定
        DrawFormatString(1060, 280, (0, 0, 0), "%d", max);      //最高スコア表示


        DrawCircle(1725, 65, 40, Cr5);     //スピーカーボタンの下の円

        //スピーカーの画像がクリックされたら画像がミュートの画像になる
        if (*p == 1) {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE);   //スピーカー(ON)の画像
        }
        else {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE);    //スピーカー(OFF)の画像
        }



        SetFontSize(90);        //文字のサイズの設定
        DrawFormatString(780, 280, (0, 0, 0), "%d", n - 1);     //スコア表示

        DrawRotaGraph(775, 730, 0.8, 0.0, rod, TRUE);           //もう一度ボタンの画像

        //もう一度ボタンHOVERした時の色替え
        if (MouseX > 740 && MouseX < 1155 && MouseY > 670 && MouseY < 785) {

            ClearDrawScreen();          //画面クリア、画面の削除

            //---------------------ゲーム内表示させるモノ--------------------//
            DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);           // 背景の画像
            DrawRotaGraph(960, 300, 1.5, 0.0, hai, TRUE);           // 背景の画像
            DrawRotaGraph(800, 200, 1.1, 0.0, scoreicon, TRUE);     //スコアの画像
            DrawRotaGraph(1080, 200, 1.0, 0.0, maxscoreicon, TRUE); //マックススコアの画像


            DrawCircle(1825, 65, 40, Cr5);     //終了ボタンの下の円
            DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // 終了の画像

            DrawBox(740, 670, 1155, 785, Cr4, TRUE);       //プレイ下のしかく

            DrawCircle(100, 70, 70, Cr5);                    //左上の円
            DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ルールの画像


            SetFontSize(46);        //文字のサイズの設定
            DrawString(810, 705, "もう一度プレイ", Cr1);

            DrawRotaGraph(775, 730, 0.8, 0.0, rod, TRUE); //もう一度ボタンの画像

            SetFontSize(90);        //文字のサイズの設定
            DrawFormatString(1060, 280, (0, 0, 0), "%d", max);     //マックススコア表示


            DrawCircle(1725, 65, 40, Cr5);     //スピーカーボタンの下の円

            //スピーカーの画像がクリックされたら画像がミュートの画像になる
            if (*p == 1) {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE); //スピーカー(ON)の画像

            }
            else {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE); //スピーカー(OFF)の画像
            }


            SetFontSize(90);        //文字のサイズの設定
            DrawFormatString(780, 280, (0, 0, 0), "%d", n - 1);   //スコア表示

        }

        //サウンドボタンORもう一度ボタンOR終了ボタンクリック判定
        if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
            //サウンドボタンがクリック
            if (MouseX > 1685 && MouseX < 1765 && MouseY > 25 && MouseY < 100) {

                if (*p == 1) {          //サウンド(ON)
                    ChangeVolumeSoundMem(100, SHandle);     //ホーム音声
                    ChangeVolumeSoundMem(125, PlaySound1);  //Play音声
                    *p = 0;
                }
                else {                  //サウンド(OFF)
                    ChangeVolumeSoundMem(0, SHandle);       //ホーム音声
                    ChangeVolumeSoundMem(0, PlaySound1);    //Play音声
                    *p = 1;
                }
            }

            WaitTimer(200);         //処理を200ミリ秒止める


            //もう一度プレイボタンがクリック
            if (MouseX > 740 && MouseX < 1155 && MouseY > 670 && MouseY < 785) {
                PlaySoundMem(PlaySound1, DX_PLAYTYPE_BACK);     //startの音声

                WaitTimer(1500);        //処理を500ミリ秒止める

                DeleteSoundMem(SHandle);                        //サウンド消去

                SetBackgroundColor(139, 224, 210);  //背景の色変更

                //ゲームカウント
                PlayMovie("Kioku_Play.mp4", 1, DX_MOVIEPLAYTYPE_NORMAL);

                break;                  //もう一度プレイ

            }
            //終了ボタンがクリック
            if (MouseX > 1785 && MouseX < 1865 && MouseY > 25 && MouseY < 100) {

                WaitTimer(300);        //処理を300ミリ秒止める

                DxLib_End();           // ＤＸライブラリ使用の終了処理（強制終了）
            }

            ///ルールボタン
            if (MouseX > 30 && MouseX < 170 && MouseY > 0 && MouseY < 140) {
                Game_Rule();//ルール説明の関数

            }

        }





    }
}