#include "DxLib.h"


void DarkenScreen()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // �������̃u�����h���[�h�ɐݒ�
    DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE); // ��ʑS�̂ɔ������̍�����`��`��
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h�����ɖ߂�
}
