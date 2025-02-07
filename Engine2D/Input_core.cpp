#include "Input_core.h"

//여기에 input core를 구현합니다.
//사용할 입력에 따라 직접 초기화해야합니다.

INPUT_CORE::INPUT_CORE()
{

}

INPUT_CORE::~INPUT_CORE()
{

}

void INPUT_CORE::initializer(HWND outer_hwnd)
{
	hwnd = outer_hwnd;
	if (init)return; //초기화는 한 번만
	init = true;

	//마우스 입력만을 사용하도록 구현


}



void INPUT_CORE::check_input()
{
	//마우스
	//그냥 사용하면 GDI+ 좌표와 다르게 나옴

	GetCursorPos(&mouse.pos);
	ScreenToClient(hwnd, &mouse.pos);

	//마우스 클릭
	mouse.Lclicked = ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0); //눌림


	return;
}

