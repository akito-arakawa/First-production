#include "DxLib.h"



void DarkenScreen();

/* -------------------------------------------------------------------------- */
/* �֐����FDog_Push_ans                                                       */
/* �@  �\�F�����N���b�N���ꂽ�Ƃ��ɉ摜��傫�����Ėi����                     */
/* �߂�l�F�Ȃ�                                                               */
/* ��  ���F�Ȃ�                                                               */
/* -------------------------------------------------------------------------- */
void Dog_Push_ans(int n, int *p)
{
    int Cr1 = GetColor(255, 255, 255);//��
    int Cr2 = GetColor(255, 0, 0);//��

    int dog;///�摜�i�[�p
    dog = LoadGraph("dog.png");//���̉摜
    int cat;///�摜�i�[�p
    cat = LoadGraph("cat.png");//���̉摜
    int chicken;//�摜�i�[�p
    chicken = LoadGraph("chicken.png"); //�j���g���̉摜
    int elephant;//�摜�i�[�p
    elephant = LoadGraph("elephant.png");//�ۂ̉摜
    int scoreicon;//�摜�i�[�p
    scoreicon = LoadGraph("score.png");//�w�i�̉摜
    int zuu;//�摜�i�[�p
    zuu = LoadGraph("zuu.png");//�w�i�̉摜
    int DogSound;
    DogSound = LoadSoundMem("���̖���.mp3");

    // �`����ʂ𗠂ɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    ClearDrawScreen();//��ʃN���A�A��ʂ̍폜

    SetBackgroundColor(110, 113, 101);//�w�i�̐F�ύX


   

    DrawRotaGraph(960, 540, 1.0, 0.0, zuu, TRUE); // �w�i�̉摜


    //---------------- - �~-------------------------- /
    DrawCircle(1260, 250, 200, Cr1);     //�E��̉~
    DrawCircle(660, 250, 200, Cr2);      //����̉~
    DrawCircle(1260, 830, 200, Cr1);     //�E���̉~
    DrawCircle(660, 830, 200, Cr1);      //�����̉~

    DrawRotaGraph(1260, 250, 1.5, 0.0, cat, TRUE); // �L�̉摜
    DrawRotaGraph(660, 830, 1.5, 0.0, chicken, TRUE); // �{�̉摜
    DrawRotaGraph(1260, 830, 1.2, 0.0, elephant, TRUE); // ���̉摜




    DrawRotaGraph(660, 250, 2.5, 0.0, dog, TRUE); // ���̉摜

    

    if (*p == 0) {
        ChangeVolumeSoundMem(80, DogSound);
        PlaySoundFile("���̖���.mp3", DX_PLAYTYPE_BACK);     //���̉���
      
    }
    else if (*p == 1) {
        ChangeVolumeSoundMem(0, DogSound);
    }

    DarkenScreen();



    DrawBox(45, 8, 230, 95, Cr1, TRUE);//�v���C���̂�����
    DrawCircle(45, 51.5, 43.5, Cr1);     //�E��̉~
    DrawCircle(230, 51.5, 43.5, Cr1);     //�E��̉~
    SetFontSize(70);//�����̃T�C�Y�̐ݒ�
    DrawFormatString(175, 20, (0, 0, 0), "%d", n - 1);

    DrawRotaGraph(95, 50, 1.2, 0.0, scoreicon, TRUE); // icon�̉摜

    // ����ʂ̓��e��\��ʂɔ��f���܂�
    ScreenFlip();

    WaitTimer(300);//������300�~���b�~�߂�
}