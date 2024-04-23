#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include "kioku_1.h"


//---------- �O���[�o���ϐ�---------------------------//
// 
//�}�E�X�ɂ��Ă̕ϐ�
int MouseX = 0;                     //�}�E�X��X���W
int MouseY = 0;                     //�}�E�X��Y���W


//-------------�Q�[�����Ŏg���F----------------------//
int Cr1 = GetColor(255, 255, 255);          //��
int Cr2 = GetColor(255, 0, 0);              //��
int Cr3 = GetColor(125, 153, 104);          //��
int Cr4 = GetColor(173, 212, 144);          //����
int Cr5 = GetColor(0, 0, 0);                //��
//---------------------------------------------------//
int max;                //�}�b�N�X�X�R�A
int p = 0;              //�T�E���h�؂�ւ�


//-----------------------------------------------------//

// ���̃E�B���h�E�n���h���Ƃ���NULL���g�p
HWND hwnd = GetForegroundWindow();

//�v���g�^�C�v�錾
void kioku_start(int* p);             //�X�^�[�g���
void Kioku(int* p);                   //���C���Q�[��
void DarkenScreen();                  //�_�[�N�X�N���[��
void Print_Score(int n, int* p);      //�X�R�A���
void Game_Rule(void);                 //���[������


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    SetBackgroundColor(221, 229, 205);                  //�w�i�̐F�ύX


    SetGraphMode(1920, 1080, 32);                       //��ʉ𑜓x1920�~1080
    SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);



    if (DxLib_Init() == -1)     // �c�w���C�u��������������
    {
        return -1;              // �G���[���N�����璼���ɏI��
    }


    //�Q�[���J�n���
    kioku_start(&p);


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {//�G�X�P�[�v�L�[���������܂�

        //���C�����
        Kioku(&p);

    }

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;           // �\�t�g�̏I��
}

/* -------------------------------------------------------------------------- */
/* �֐����Fkioku_start                                                        */
/* �@  �\�F�X�^�[�g��ʁ@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                     */
/* �߂�l�F�Ȃ�                                                               */
/* ��  ���Fint *p: �~���[�g�؂�ւ�                                           */
/* -------------------------------------------------------------------------- */
void kioku_start(int* p)
{

    int edgeinput;                //�}�E�X���͂��i�[�ϐ�
    SetMouseDispFlag(TRUE);       //�}�E�X��\������



    //-------------------------�Q�[�����摜--------------------------------//
    int dog;                                //���̉摜�i�[�p
    dog = LoadGraph("dog.png");             //���̉摜

    int cat;                                //�L�̉摜�i�[�p
    cat = LoadGraph("cat.png");             //�L�̉摜

    int chicken;                            //�j���g���̉摜�i�[�p
    chicken = LoadGraph("chicken.png");     //�j���g���̉摜

    int elephant;                           //�ۂ̉摜�i�[�p
    elephant = LoadGraph("elephant.png");   //�ۂ̉摜

    int zuu;                                //�w�i�̉摜�i�[�p
    zuu = LoadGraph("zuu.png");             //�w�i�̉摜

    int PLAY;                               //Play�{�^���摜�i�[�p
    PLAY = LoadGraph("PLAY.png");           //Play�{�^���̉摜

    int PLAY_Puch;                          //Play�{�^���������Ƃ��̉摜�i�[�p
    PLAY_Puch = LoadGraph("PLAY_Puch.png"); //Play�{�^���������Ƃ��̉摜

    int Speaker;                            //�T�E���h�̉摜�i�[�p
    Speaker = LoadGraph("mugic.png");       //�T�E���h�̉摜

    int Speaker2;                           //�T�E���h�������Ƃ��摜�i�[�p
    Speaker2 = LoadGraph("mug2.png");       //�T�E���h�������Ƃ��I���̉摜

    int batu;                                   //�I���{�^���̉摜�i�[�p
    batu = LoadGraph("batu.png");               //�I���{�^���̉摜


    int book;                                   //�{�{�^���̉摜�i�[�p
    book = LoadGraph("books.png");               //�{�{�^���̉摜

    int Rule;                                   //���[���{�^��1�̉摜�i�[�p
    Rule = LoadGraph("Rule.png");               //���[���{�^��1�̉摜

    //----------�Q�[�����T�E���h-------------//
    int SHandle;                            //�z�[�����̉����i�[�p
    SHandle = LoadSoundMem("home.wav");     //�z�[��������

    int PlaySound1;                         //start�{�^���̉����i�[�p
    PlaySound1 = LoadSoundMem("start.wav"); //start�{�^������


    time_t t;  //�^�C�����̕ϐ� 

    //�Q�[�������ʒ���
    ChangeVolumeSoundMem(100, SHandle);         //�z�[������������                      
    ChangeVolumeSoundMem(125, PlaySound1);      //Play�{�^����������

    PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);     //�z�[�����̉���


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {       //�G�X�P�[�v�L�[���������܂�

        edgeinput = GetMouseInput();                //�}�E�X�̓��͂��擾������1����
        GetMousePoint(&MouseX, &MouseY);            //�}�E�X�̍��W

        ClearDrawScreen();                          //��ʃN���A�A��ʂ̍폜


        //---------------------------�\�����郂�m--------------------------------------//
        DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);       // �w�i�̉摜

        DrawCircle(240, 340, 200, Cr1);                     //�E��̉~
        DrawCircle(720, 340, 200, Cr1);                     //����̉~
        DrawCircle(1200, 340, 200, Cr1);                    //�E���̉~
        DrawCircle(1680, 340, 200, Cr1);                    //�����̉~

        DrawRotaGraph(240, 340, 1.8, 0.0, dog, TRUE);       // ���̉摜
        DrawRotaGraph(720, 340, 1.5, 0.0, cat, TRUE);       // �L�̉摜
        DrawRotaGraph(1200, 340, 1.5, 0.0, chicken, TRUE);  // �{�̉摜
        DrawRotaGraph(1680, 340, 1.2, 0.0, elephant, TRUE); // ���̉摜
        DrawRotaGraph(960, 650, 0.2, 0.0, PLAY, TRUE);      // �X�^�[�g�̉摜

        DrawCircle(1725, 65, 40, Cr5);     //�X�s�[�J�[�{�^���̉��̉~

        //�X�s�[�J�[�̉摜���N���b�N���ꂽ��摜���~���[�g�̉摜�ɂȂ�
        if (*p == 1) {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE); //�X�s�[�J�[(ON)�̉摜

        }
        else {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE); //�X�s�[�J�[(OFF)�̉摜
        }

        DrawCircle(1825, 65, 40, Cr5);     //�I���{�^���̉��̉~
        DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // �I���̉摜

        DrawCircle(100, 70, 70, Cr5);                    //�����̉~

        DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ���[���̉摜


      

        //�}�E�X�J�[�\����start�{�^���͈̔͂ɓ������ꍇ(start�{�^����傫������j
        if (MouseX > 770 && MouseX < 1130 && MouseY > 600 && MouseY < 700) {

            ClearDrawScreen();        //��ʃN���A�A��ʂ̍폜


            DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);       // �w�i�̉摜


            DrawCircle(240, 340, 200, Cr1);      //�E��̉~
            DrawCircle(720, 340, 200, Cr1);      //����̉~
            DrawCircle(1200, 340, 200, Cr1);     //�E���̉~
            DrawCircle(1680, 340, 200, Cr1);     //�����̉~


            DrawCircle(1825, 65, 40, Cr5);     //�I���{�^���̉��̉~
            DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // �I���̉摜

            DrawRotaGraph(240, 340, 1.8, 0.0, dog, TRUE);        // ���̉摜
            DrawRotaGraph(720, 340, 1.5, 0.0, cat, TRUE);        // �L�̉摜
            DrawRotaGraph(1200, 340, 1.5, 0.0, chicken, TRUE);   // �{�̉摜
            DrawRotaGraph(1680, 340, 1.2, 0.0, elephant, TRUE);  // ���̉摜
            DrawRotaGraph(950, 650, 0.2, 0.0, PLAY_Puch, TRUE);  // �X�^�[�g�̉摜

            DrawCircle(100, 70, 70, Cr5);                    //����̉~
            DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ���[���̉摜


            DrawCircle(1725, 65, 40, Cr5);     //�X�s�[�J�[�{�^���̉��̉~

            //�X�s�[�J�[�̉摜���N���b�N���ꂽ��摜���~���[�g�̉摜�ɂȂ�
            if (*p == 1) {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE); //�X�s�[�J�[(ON)�̉摜

            }
            else {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE); //�X�s�[�J�[(OFF)�̉摜
            }
        }



        //�E�N���b�N����
        if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {

            //�T�E���h�{�^�����N���b�N
            if (MouseX > 1685 && MouseX < 1765 && MouseY > 25 && MouseY < 100) {

                if (*p == 1) {          //�T�E���h(ON)
                    ChangeVolumeSoundMem(100, SHandle);     //�z�[������
                    ChangeVolumeSoundMem(125, PlaySound1);  //Play����
                    *p = 0;
                }
                else {                  //�T�E���h(OFF)
                    ChangeVolumeSoundMem(0, SHandle);       //�z�[������
                    ChangeVolumeSoundMem(0, PlaySound1);    //Play����
                    *p = 1;
                }
                WaitTimer(200);         //������200�~���b�~�߂�

            }


            //�I���{�^�����N���b�N
            if (MouseX > 1785 && MouseX < 1865 && MouseY > 25 && MouseY < 100) {

                WaitTimer(300);        //������300�~���b�~�߂�

                DxLib_End();           // �c�w���C�u�����g�p�̏I�������i�����I���j
            }

            //PLAY�{�^���������ꂽ�����f
            if (MouseX > 770 && MouseX < 1130 && MouseY > 600 && MouseY < 700) {


                PlaySoundMem(PlaySound1, DX_PLAYTYPE_BACK);     //start�̉���
                DeleteSoundMem(SHandle);                        //start�̉�������




                WaitTimer(300);         //������300�~���b�~�߂�

                SetBackgroundColor(139, 224, 210);  //�w�i�̐F�ύX

                //�Q�[���J�E���g
                PlayMovie("Kioku_Play.mp4", 1, DX_MOVIEPLAYTYPE_NORMAL);


                break;
            }

            if (MouseX > 30 && MouseX < 170 && MouseY > 0 && MouseY < 140) {
                Game_Rule();//���[�������̊֐�

            }


        }


    }




}

/* -------------------------------------------------------------------------- */
/* �֐����FGame_Rule                                                          */
/* �@  �\�F���[����ʁ@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                     */
/* �߂�l�F�Ȃ�                                                               */
/* ��  ���F�Ȃ��@                                                             */
/* -------------------------------------------------------------------------- */

void Game_Rule(void)
{

    int edgeinput;                //�}�E�X���͂��i�[�ϐ�
    SetMouseDispFlag(TRUE);       //�}�E�X��\������


    int home_Name;                                           //�m�[�}�����O��ʂ̉摜�i�[�p
    home_Name = LoadGraph("home_Name.png");                  //�m�[�}�����O�摜�̉摜

    int Hito_home_Name;                                      //�m�[�}�����O��ʂ̉摜�i�[�p
    Hito_home_Name = LoadGraph("Hito_home_Name.png");        //�m�[�}�����O�摜�̉摜

    int home;                                                //�m�[�}����ʂ̉摜�i�[�p
    home = LoadGraph("home.png");                            //�m�[�}���摜�̉摜

    int home_score;                                          //�m�[�}���X�R�A��ʂ̉摜�i�[�p
    home_score = LoadGraph("Home_Score.png");                //�m�[�}���X�R�A�摜�̉摜

    int home_Red;                                            //�����ԂɂȂ�摜�̉摜�i�[�p
    home_Red = LoadGraph("home_Red.png");                    //�����ԂɂȂ�摜�̉摜

    int home_Red_Push;                                       //�����ԂɂȂ�N���b�N�摜�̉摜�i�[�p
    home_Red_Push = LoadGraph("home_Red_Push.png");          //�����ԂɂȂ�N���b�N�摜�̉摜

    int Hito_home_Ru_ru;                                     //���[���̉摜�̉摜�i�[�p
    Hito_home_Ru_ru = LoadGraph("Hito_home_Ru-ru.png");      //���[���̉摜�̉摜

    int Hito_home_Strat;                                     //�����ԂɂȂ�N���b�N�摜�̉摜�i�[�p
    Hito_home_Strat = LoadGraph("Hito_home_Strat.png");      //�����ԂɂȂ�N���b�N�摜�̉摜

    int Hito_home_Red;                                       //�����ԂɂȂ�N���b�N�摜�̉摜�i�[�p
    Hito_home_Red = LoadGraph("Hito_home_Red.png");          //�����ԂɂȂ�N���b�N�摜�̉摜

    int Hito_home_Red_Push;                                  //�����ԂɂȂ�N���b�N�摜�̉摜�i�[�p
    Hito_home_Red_Push = LoadGraph("Hito_home_Red_Push.png"); //�����ԂɂȂ�N���b�N�摜�̉摜

    int Hito_home_score;                                     //�����ԂɂȂ�N���b�N�摜�̉摜�i�[�p
    Hito_home_score = LoadGraph("Hito_home_score.png");      //�����ԂɂȂ�N���b�N�摜�̉摜

    int Next;                       //���։摜�i�[�p
    Next = LoadGraph("Next.png");   //���ւ̉摜

    int Return;                     //�O�ւ̉摜�i�[�p
    Return = LoadGraph("Return.png");//�O�ւ̉摜


    int skip;                   //�X�L�b�v�̃{�^���i�[�p
    skip = LoadGraph("Skip.png");//�X�L�b�v�̃{�^��

    int home1;//�z�[���ɖ߂�
    home1 = LoadGraph("HOME_return.png");//�z�[���ɖ߂�摜

    int i = 0;//���[�v�J�E���^

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {       //�G�X�P�[�v�L�[���������܂�

        // �`����ʂ𗠂ɂ���
       // SetDrawScreen(DX_SCREEN_BACK);

        ClearDrawScreen();      //��ʃN���A�A��ʂ̍폜

        edgeinput = GetMouseInput();                //�}�E�X�̓��͂��擾������1����
        GetMousePoint(&MouseX, &MouseY);            //�}�E�X�̍��W

        SetFontSize(60);         //�����̃T�C�Y�̐ݒ�

        switch (i) {
        case 0:


            DrawRotaGraph(768, 432, 0.8, 0.0, home_Name, TRUE);      // �m�[�}���̉摜
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Name, TRUE);      // �����S�̖��O�̂�摜

            break;

        case 1:


            DrawRotaGraph(768, 432, 0.8, 0.0, home_Red, TRUE);      // �����Ԃ̉摜
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Red, TRUE);      // �����ԃN���b�N�ЂƉ摜

            break;
        case 2:

            DrawRotaGraph(768, 432, 0.8, 0.0, home, TRUE);      // �m�[�}���̉摜
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Strat, TRUE);      // �����ԃN���b�N�ЂƉ摜

            break;
        case 3:

            DrawRotaGraph(768, 432, 0.8, 0.0, home_Red_Push, TRUE);      // �����ԃN���b�N�摜
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Red_Push, TRUE);      // �����ԃN���b�N�ЂƉ摜

            break;
        case 4:

            DrawRotaGraph(768, 432, 0.8, 0.0, home_Red_Push, TRUE);      // �����ԃN���b�N�摜
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_Ru_ru, TRUE);      // �����ԃN���b�N�ЂƉ摜

            break;
        case 5:

            DrawRotaGraph(708, 432, 1.0, 0.0, home_score, TRUE);      // �X�R�A��ʂ̉摜
            DrawRotaGraph(1500, 700, 0.8, 0.0, Hito_home_score, TRUE);      // �����ԃN���b�N�ЂƉ摜

            break;

        }

        DrawRotaGraph(1110, 950, 1.5, 0.0, Next, TRUE);      // ���ւ̉摜

        if (i >= 1) {
            DrawRotaGraph(810, 950, 1.5, 0.0, Return, TRUE);      // �O�ւ̉摜

        }

        if (i < 5) {
            DrawRotaGraph(1800, 50, 1.5, 0.0, skip, TRUE);      // �X�L�b�v�̃{�^���̉摜

        }

        if (i >= 5) {
            DrawRotaGraph(1110, 950, 1.5, 0.0, home1, TRUE);      // �O�ւ̉摜
        }

        SetFontSize(30);         //�����̃T�C�Y�̐ݒ�

        DrawFormatString(915, 1010, (0, 0, 0), "%d / 6", i + 1);   //���݃y�[�W��



        //�E�N���b�N����
        if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {

            //���փ{�^���������ꂽ�����f
            if (MouseX > 1000 && MouseX < 1210 && MouseY > 920 && MouseY < 980) {
                i++;



                WaitTimer(300);         //������300�~���b�~�߂�



            }
            //�߂�{�^���������ꂽ�Ƃ�
            if (MouseX > 700 && MouseX < 920 && MouseY > 915 && MouseY < 980) {
                i--;

                //0�ȉ��ɂȂ�Ȃ��悤��
                if (i <= 0) {
                    i = 0;
                }

                WaitTimer(300);         //������300�~���b�~�߂�

            }

            if (MouseX > 1695 && MouseX < 1900 && MouseY > 15 && MouseY < 80) {

                WaitTimer(300);         //������300�~���b�~�߂�

                break;

            }

            if (MouseX > 970 && MouseX < 1230 && MouseY > 918 && MouseY < 980 && i >= 6) {

                WaitTimer(300);         //������300�~���b�~�߂�

                break;//���[���I��

            }

        }


        // ����ʂ̓��e��\��ʂɔ��f���܂�
       // ScreenFlip();


    }
}


/* -------------------------------------------------------------------------- */
/* �֐����FKioku                                                              */
/* �@  �\�F���C����ʁ@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                     */
/* �߂�l�F�Ȃ�                                                               */
/* ��  ���Fint *p: �~���[�g�؂�ւ�                                           */
/* -------------------------------------------------------------------------- */
void Kioku(int* p)
{
    int edgeinput;     //�}�E�X���͂��i�[�ϐ�

    int i = 0;         //���[�v�J�E���^
    int j = 0;         //���[�v�J�E���^


    //---------------------�Q�[�����摜---------------------------------//
    int dog;                                //���̉摜�i�[�p
    dog = LoadGraph("dog.png");             //���̉摜

    int cat;                                //�L�̉摜�i�[�p
    cat = LoadGraph("cat.png");             //�L�̉摜

    int chicken;                            //�j���g���̉摜�i�[�p
    chicken = LoadGraph("chicken.png");     //�j���g���̉摜

    int elephant;                           //�ۂ̉摜�i�[�p
    elephant = LoadGraph("elephant.png");   //�ۂ̉摜

    int zuu;                                //�w�i�̉摜�i�[�p
    zuu = LoadGraph("zuu.png");             //�w�i�̉摜

    int scoreicon;                          //�X�R�A�w�i�̉摜�i�[�p
    scoreicon = LoadGraph("score.png");     //�X�R�A�w�i�̉摜

    int Speaker;                            //�X�s�[�J�[(ON)�̉摜�i�[�p
    Speaker = LoadGraph("mugic.png");       //�X�s�[�J�[(ON)�̉摜

    int Speaker2;                           //�X�s�[�J�[(OFF)�̉摜�i�[�p
    Speaker2 = LoadGraph("mug2.png");       //�X�s�[�J�[(OFF)�̉摜

    int kuri;                               //�N���b�N�̉摜�i�[�p
    kuri = LoadGraph("kuri.png");           //�N���b�N�̉摜


    //--------------��Փx�ݒ�------------------------//
    int ans[10][10];                //�����h�֐��ŕԂ��ꂽ�l���i�[����
    int player[10][10];             //�v���C���[���N���b�N�����Ƃ��ɔz��Ɋi�[�����
    int count = 1;                  //��Փx�J�E���g

    bool flag = true;               //�Q�[�����[�v

    SetMouseDispFlag(TRUE);         //�}�E�X��\������

    time_t t;   //���Ԍ^�̕ϐ� 

    double r = 170;     //�~�����e����ϐ�



    //10��A���ŉ�����܂Ōp��
    for (count = 1; count <= 10; count++) {

        // �t���[�����[�g�̐���
        Sleep(16); // 60FPS��z��

        srand((unsigned int)time(NULL));         // ���ݎ����̏��ŏ�����  �����h�֐��̏�����

        //�����_������
        for (i = count - 1; i < count; i++) {
            for (j = 0; j < count; j++) {

                switch (rand() % 4 + 1) {

                case 1: //��   
                    Dog_Push_ans(count, p);      //�����N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����
                    ans[i][j] = 1;               //�����̕ϐ���count�Ԗڂ�i�ڂ�1����

                    break;
                case 2: //�L
                    Cat_Push_ans(count, p);      //�L���N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����
                    ans[i][j] = 2;               //�����̕ϐ���count�Ԗڂ�i�ڂ�2����

                    break;
                case 3: //�j���g��
                    Chicken_Push_ans(count, p);  //�{���N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����
                    ans[i][j] = 3;               //�����̕ϐ���count�Ԗڂ�i�ڂ�3����

                    break;
                case 4: //��
                    Elephant_Puch_ans(count, p); //�����N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����
                    ans[i][j] = 4;               //�����̕ϐ���count�Ԗڂ�i�ڂ�4����

                    break;
                }

                // �`����ʂ𗠂ɂ���
                SetDrawScreen(DX_SCREEN_BACK);

                SetBackgroundColor(110, 113, 101);//�w�i�̐F�ύX

                ClearDrawScreen();//��ʃN���A�A��ʂ̍폜

                DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE); // �w�i�̉摜


                //---------------- - �~-------------------------- /
                DrawCircle(1260, 250, 200, Cr1);     //�E��̉~
                DrawCircle(660, 250, 200, Cr1);      //����̉~
                DrawCircle(1260, 830, 200, Cr1);     //�E���̉~
                DrawCircle(660, 830, 200, Cr1);      //�����̉~

                DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE); // ���̉摜
                DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE); // �L�̉摜
                DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE);    // �{�̉摜
                DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // ���̉摜

                DarkenScreen();



                DrawBox(45, 8, 230, 95, Cr1, TRUE);//�v���C���̂�����
                DrawCircle(45, 51.5, 43.5, Cr1);     //�E��̉~
                DrawCircle(230, 51.5, 43.5, Cr1);     //�E��̉~
                SetFontSize(70);//�����̃T�C�Y�̐ݒ�
                DrawFormatString(175, 20, (0, 0, 0), "%d", count - 1);

                DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE); // icon�̉摜


                // ����ʂ̓��e��\��ʂɔ��f���܂�
                ScreenFlip();



                WaitTimer(300);     //������300�~���b�~�߂�

            }
        }

        SetBackgroundColor(221, 229, 205);  //�w�i�̐F�ύX



        t = time(NULL);//���݂̎��Ԃ��擾


        //���[�U�����̓��[�v
        for (i = count - 1; i < count; i++) {
            for (j = 0; j < count; ) {

                // �`����ʂ�\�ɂ���
                SetDrawScreen(DX_SCREEN_FRONT);

                edgeinput = GetMouseInput();        //�}�E�X�̓��͂��擾������1����
                GetMousePoint(&MouseX, &MouseY);    //�}�E�X�̍��W

                ClearDrawScreen();                  //��ʃN���A�A��ʂ̍폜

                //----------------------�\�������郂�m------------------------//
                DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);        // �w�i�̉摜

                DrawCircle(1260, 250, 200, Cr1);     //�E��̉~
                DrawCircle(660, 250, 200, Cr1);      //����̉~
                DrawCircle(1260, 830, 200, Cr1);     //�E���̉~
                DrawCircle(660, 830, 200, Cr1);      //�����̉~

                DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE);        // ���̉摜
                DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE);       // �L�̉摜
                DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE);    // �{�̉摜
                DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE);  // ���̉摜

                //DrawFormatString(1000, 0, (255, 255, 255), "%d", ans[i][j]);//�q���g

                DrawBox(45, 8, 230, 95, Cr1, TRUE);     //�v���C���̂�����
                DrawCircle(45, 51.5, 43.5, Cr1);        //�E��̉~
                DrawCircle(230, 51.5, 43.5, Cr1);       //�E��̉~

                SetFontSize(70);    //�����̃T�C�Y�̐ݒ�
                DrawFormatString(175, 20, (0, 0, 0), "%d", count - 1);   //���݂̉�������
                DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE);        // �X�R�A�A�C�R���̉摜



                //1��ڂ̓��͂�3�b�o�߂����牟���Ƃ���\��
                if ((time(NULL) - t) >= 3 && i == 0) {

                    r = r + 0.5;//�~��傫������

                    //1��ڂ̂Ƃ�
                    switch (ans[0][0]) {
                    case 1://��
                        DrawCircle(660, 250, r, Cr2);      //����̉~
                        DrawCircle(660, 250, 200, Cr1);    //����̉~

                        DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE);    // ���̉摜
                        DrawRotaGraph(660, 350, 2.5, 0.0, kuri, TRUE);   // �N���b�N�摜

                        break;
                    case 2://�L
                        DrawCircle(1260, 250, r, Cr2);       //�E��̉~   
                        DrawCircle(1260, 250, 200, Cr1);     //�E��̉~

                        DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE);   // �L�̉摜
                        DrawRotaGraph(1260, 350, 2.5, 0.0, kuri, TRUE);  // �N���b�N�摜

                        break;
                    case 3://�{
                        DrawCircle(660, 830, r, Cr2);        //�����̉~
                        DrawCircle(660, 830, 200, Cr1);      //�����̉~

                        DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE); // �{�̉摜
                        DrawRotaGraph(660, 930, 2.5, 0.0, kuri, TRUE);    // �N���b�N�摜

                        break;
                    case 4://��
                        DrawCircle(1260, 830, r, Cr2);       //�E���̉~
                        DrawCircle(1260, 830, 200, Cr1);     //�E���̉~

                        DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // ���̉摜
                        DrawRotaGraph(1260, 930, 2.5, 0.0, kuri, TRUE);     // �N���b�N�摜

                        break;
                    }
                }

                //�~��220�ɂȂ�����~��������
                if (r >= 220) {
                    r = 170;
                }

                //-------------------------�����̉E�N���b�N����----------------------------------//
                  //�����N���b�N���ꂽ�Ƃ�
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 460 && MouseX < 860 && MouseY > 50 && MouseY < 550) {

                        Dog_Push(count, p);     //�����N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����

                        player[i][j] = 1;       //�N���b�N���ꂽ�����̐������i�[

                        //���͌��ʔ��f
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;      //�Q�[�������鏈��
                            break;
                        }

                    }
                }
                //�L���N���b�N���ꂽ��
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 1060 && MouseX < 1460 && MouseY > 50 && MouseY < 550) {

                        Cat_Push(count, p);    //�L���N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����

                        player[i][j] = 2;      //�N���b�N���ꂽ�����̐������i�[

                        //���͌��ʔ��f
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;      //�Q�[�������鏈��
                            break;
                        }

                    }
                }

                //�{���N���b�N���ꂽ�Ƃ�
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 460 && MouseX < 860 && MouseY >  630 && MouseY < 1030) {

                        Chicken_Push(count, p); //�{���N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����

                        player[i][j] = 3;       //�N���b�N���ꂽ�����̐������i�[

                        //���͌��ʔ��f
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;      //�Q�[�������鏈��
                            break;
                        }

                    }
                }
                //�ۂ��N���b�N���ꂽ�Ƃ�
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 1060 && MouseX < 1460 && MouseY > 630 && MouseY < 1030) {

                        Elephant_Puch(count, p);//�ۂ��N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����

                        player[i][j] = 4;       //�N���b�N���ꂽ�����̐������i�[

                        //���͌��ʔ��f
                        if (ans[i][j] == player[i][j]) {
                            j++;
                        }
                        else {
                            flag = false;       //�Q�[�������鏈��
                            break;

                        }

                    }
                }

                //�~���[�g�{�^���������ꂽ�����f
                if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
                    if (MouseX > 1785 && MouseX < 1845 && MouseY > 35 && MouseY < 95) {

                        WaitTimer(200);        //������100�~���b�~�߂�

                    }

                }

            }

        }



        // �`����ʂ�\�ɂ���
        SetDrawScreen(DX_SCREEN_FRONT);

        ClearDrawScreen();                          //��ʃN���A�A��ʂ̍폜

        DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE); // �w�i�̉摜



        //---------------- - �~-------------------------- /
        DrawCircle(1260, 250, 200, Cr1);     //�E��̉~
        DrawCircle(660, 250, 200, Cr1);      //����̉~
        DrawCircle(1260, 830, 200, Cr1);     //�E���̉~
        DrawCircle(660, 830, 200, Cr1);      //�����̉~

        DrawRotaGraph(660, 250, 1.8, 0.0, dog, TRUE); // ���̉摜
        DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE); // �L�̉摜
        DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE); // �{�̉摜
        DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // ���̉摜

        DrawBox(45, 8, 230, 95, Cr1, TRUE);//�v���C���̂�����
        DrawCircle(45, 51.5, 43.5, Cr1);     //�E��̉~
        DrawCircle(230, 51.5, 43.5, Cr1);     //�E��̉~
        SetFontSize(70);//�����̃T�C�Y�̐ݒ�
        DrawFormatString(175, 20, (0, 0, 0), "%d", count - 1);

        DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE); // icon�̉摜

        //------------//


        WaitTimer(500);//������500�~���b�~�߂�



        //�Q�[���I��
        if (!flag) {
            Print_Score(count, p);      //�X�R�A��ʂ�

            break;
        }


    }
}

/* -------------------------------------------------------------------------- */
/* �֐����FPrint_Score                                                        */
/* �@  �\�F�X�R�A��ʁ@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                     */
/* �߂�l�F�Ȃ�                                                               */
/* ��  ���Fint n: �X�R�A�@�@�@�@�@�@                                          */
/* ��  ���Fint *p: �~���[�g�؂�ւ�                                           */
/* -------------------------------------------------------------------------- */
void Print_Score(int n, int* p)
{
    //-------------------------�Q�[�����摜---------------------------//
    int hai;                                     //�X�R�A�w�i�̉摜�i�[�p
    hai = LoadGraph("hai.png");                  //�X�R�A�w�i�̉摜

    int scoreicon;                              //�X�R�A�̉摜�i�[�p
    scoreicon = LoadGraph("score.png");         //�X�R�A�̉摜

    int maxscoreicon;                           //�}�b�N�X�X�R�A�摜�i�[�p
    maxscoreicon = LoadGraph("maxscore.png");   //�}�b�N�X�X�R�A�̉摜

    int rod;                                    //�摜�i�[�p
    rod = LoadGraph("rod.png");                 //������x�{�^���̉摜

    int zuu;                                    //�w�i�̉摜�i�[�p
    zuu = LoadGraph("zuu.png");                 //�w�i�̉摜

    int batu;                                   //�I���{�^���̉摜�i�[�p
    batu = LoadGraph("batu.png");               //�I���{�^���̉摜

    int Speaker;                                //�X�s�[�J�[(ON)�̉摜�i�[�p
    Speaker = LoadGraph("mugic.png");           //�X�s�[�J�[(ON)�̉摜

    int Speaker2;                               //�X�s�[�J�[(OFF)�摜�i�[�p
    Speaker2 = LoadGraph("mug2.png");           //�X�s�[�J�[(OFF)�̉摜

    //--------------�Q�[�����T�E���h------------------------//
    int SHandle;                                //�z�[�������i�[�p
    SHandle = LoadSoundMem("home.wav");         //�z�[������

    int PlaySound1;                             //Play�����i�[�p
    PlaySound1 = LoadSoundMem("start.wav");     //Play����

    int book;                                   //�{�{�^���̉摜�i�[�p
    book = LoadGraph("books.png");               //�{�{�^���̉摜

    //���ʐ؂�ւ�
    if (*p == 0) {              //�X�s�[�J�[(ON)
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);    //�z�[������

        ChangeVolumeSoundMem(125, SHandle);         //�z�[���̉���
        ChangeVolumeSoundMem(125, PlaySound1);      //Play�{�^���̉���
    }
    else if (*p == 1) {        //�X�s�[�J�[(OFF)
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);    //�z�[������

        ChangeVolumeSoundMem(0, SHandle);           //�z�[���̉���
        ChangeVolumeSoundMem(0, PlaySound1);        //Play�{�^���̉���
    }


    int edgeinput;                      //�}�E�X���͂��i�[�ϐ�
    SetMouseDispFlag(TRUE);             //�}�E�X��\������


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {//�G�X�P�[�v�L�[���������܂�


        edgeinput = GetMouseInput();            //�}�E�X�̓��͂��擾������1����
        GetMousePoint(&MouseX, &MouseY);        //�}�E�X�̍��W

        ClearDrawScreen();                      //��ʃN���A�A��ʂ̍폜

        //-------------------�Q�[�����\�������郂�m---------------------//
        DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);            // �w�i�̉摜
        DrawRotaGraph(960, 300, 1.5, 0.0, hai, TRUE);            //�X�R�A�w�i�̉摜
        DrawRotaGraph(800, 200, 1.1, 0.0, scoreicon, TRUE);      //�X�R�A�̉摜
        DrawRotaGraph(1080, 200, 1.0, 0.0, maxscoreicon, TRUE);  //�}�b�N�X�X�R�A�̉摜

        DrawCircle(1825, 65, 40, Cr5);     //�I���{�^���̉��̉~
        DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // �I���̉摜

        DrawBox(740, 670, 1155, 785, Cr3, TRUE);                 //�v���C���̂�����

        DrawCircle(100, 70, 70, Cr5);                    //����̉~
        DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ���[���̉摜



        SetFontSize(46);         //�����̃T�C�Y�̐ݒ�
        DrawString(810, 705, "������x�v���C", Cr1);

        //max�X�R�A��r
        if (max < n - 1) {
            max = n - 1;
        }
        SetFontSize(90);        //�����̃T�C�Y�̐ݒ�
        DrawFormatString(1060, 280, (0, 0, 0), "%d", max);      //�ō��X�R�A�\��


        DrawCircle(1725, 65, 40, Cr5);     //�X�s�[�J�[�{�^���̉��̉~

        //�X�s�[�J�[�̉摜���N���b�N���ꂽ��摜���~���[�g�̉摜�ɂȂ�
        if (*p == 1) {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE);   //�X�s�[�J�[(ON)�̉摜
        }
        else {
            DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE);    //�X�s�[�J�[(OFF)�̉摜
        }



        SetFontSize(90);        //�����̃T�C�Y�̐ݒ�
        DrawFormatString(780, 280, (0, 0, 0), "%d", n - 1);     //�X�R�A�\��

        DrawRotaGraph(775, 730, 0.8, 0.0, rod, TRUE);           //������x�{�^���̉摜

        //������x�{�^��HOVER�������̐F�ւ�
        if (MouseX > 740 && MouseX < 1155 && MouseY > 670 && MouseY < 785) {

            ClearDrawScreen();          //��ʃN���A�A��ʂ̍폜

            //---------------------�Q�[�����\�������郂�m--------------------//
            DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE);           // �w�i�̉摜
            DrawRotaGraph(960, 300, 1.5, 0.0, hai, TRUE);           // �w�i�̉摜
            DrawRotaGraph(800, 200, 1.1, 0.0, scoreicon, TRUE);     //�X�R�A�̉摜
            DrawRotaGraph(1080, 200, 1.0, 0.0, maxscoreicon, TRUE); //�}�b�N�X�X�R�A�̉摜


            DrawCircle(1825, 65, 40, Cr5);     //�I���{�^���̉��̉~
            DrawRotaGraph(1825, 65, 0.5, 0.0, batu, TRUE); // �I���̉摜

            DrawBox(740, 670, 1155, 785, Cr4, TRUE);       //�v���C���̂�����

            DrawCircle(100, 70, 70, Cr5);                    //����̉~
            DrawRotaGraph(100, 70, 0.5, 0.0, book, TRUE);       // ���[���̉摜


            SetFontSize(46);        //�����̃T�C�Y�̐ݒ�
            DrawString(810, 705, "������x�v���C", Cr1);

            DrawRotaGraph(775, 730, 0.8, 0.0, rod, TRUE); //������x�{�^���̉摜

            SetFontSize(90);        //�����̃T�C�Y�̐ݒ�
            DrawFormatString(1060, 280, (0, 0, 0), "%d", max);     //�}�b�N�X�X�R�A�\��


            DrawCircle(1725, 65, 40, Cr5);     //�X�s�[�J�[�{�^���̉��̉~

            //�X�s�[�J�[�̉摜���N���b�N���ꂽ��摜���~���[�g�̉摜�ɂȂ�
            if (*p == 1) {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker2, TRUE); //�X�s�[�J�[(ON)�̉摜

            }
            else {
                DrawRotaGraph(1725, 65, 0.6, 0.0, Speaker, TRUE); //�X�s�[�J�[(OFF)�̉摜
            }


            SetFontSize(90);        //�����̃T�C�Y�̐ݒ�
            DrawFormatString(780, 280, (0, 0, 0), "%d", n - 1);   //�X�R�A�\��

        }

        //�T�E���h�{�^��OR������x�{�^��OR�I���{�^���N���b�N����
        if ((edgeinput & MOUSE_INPUT_LEFT) != 0) {
            //�T�E���h�{�^�����N���b�N
            if (MouseX > 1685 && MouseX < 1765 && MouseY > 25 && MouseY < 100) {

                if (*p == 1) {          //�T�E���h(ON)
                    ChangeVolumeSoundMem(100, SHandle);     //�z�[������
                    ChangeVolumeSoundMem(125, PlaySound1);  //Play����
                    *p = 0;
                }
                else {                  //�T�E���h(OFF)
                    ChangeVolumeSoundMem(0, SHandle);       //�z�[������
                    ChangeVolumeSoundMem(0, PlaySound1);    //Play����
                    *p = 1;
                }
            }

            WaitTimer(200);         //������200�~���b�~�߂�


            //������x�v���C�{�^�����N���b�N
            if (MouseX > 740 && MouseX < 1155 && MouseY > 670 && MouseY < 785) {
                PlaySoundMem(PlaySound1, DX_PLAYTYPE_BACK);     //start�̉���

                WaitTimer(1500);        //������500�~���b�~�߂�

                DeleteSoundMem(SHandle);                        //�T�E���h����

                SetBackgroundColor(139, 224, 210);  //�w�i�̐F�ύX

                //�Q�[���J�E���g
                PlayMovie("Kioku_Play.mp4", 1, DX_MOVIEPLAYTYPE_NORMAL);

                break;                  //������x�v���C

            }
            //�I���{�^�����N���b�N
            if (MouseX > 1785 && MouseX < 1865 && MouseY > 25 && MouseY < 100) {

                WaitTimer(300);        //������300�~���b�~�߂�

                DxLib_End();           // �c�w���C�u�����g�p�̏I�������i�����I���j
            }

            ///���[���{�^��
            if (MouseX > 30 && MouseX < 170 && MouseY > 0 && MouseY < 140) {
                Game_Rule();//���[�������̊֐�

            }

        }





    }
}