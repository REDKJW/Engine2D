#include "Config.h"//��ũ�ΰ��� �����ص� ���� ���

#include "Body.h"
#include "main.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
    Body window;
    if (!window.Initialize(hInstance, nCmdShow, STANDARD_WIDTH, STANDARD_HEIGHT, STANDARD_TITLE))
    {
        return -1;
    }
    window.messageLoop();
    return 0;
}



