#include "Input_core.h"

//���⿡ input core�� �����մϴ�.
//����� �Է¿� ���� ���� �ʱ�ȭ�ؾ��մϴ�.

INPUT_CORE::INPUT_CORE()
{

}

INPUT_CORE::~INPUT_CORE()
{

}

void INPUT_CORE::initializer(HWND outer_hwnd)
{
	hwnd = outer_hwnd;
	if (init)return; //�ʱ�ȭ�� �� ����
	init = true;

	//���콺 �Է¸��� ����ϵ��� ����


}



void INPUT_CORE::check_input()
{
	//���콺
	//�׳� ����ϸ� GDI+ ��ǥ�� �ٸ��� ����

	GetCursorPos(&mouse.pos);
	ScreenToClient(hwnd, &mouse.pos);

	//���콺 Ŭ��
	mouse.Lclicked = ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0); //����


	return;
}

