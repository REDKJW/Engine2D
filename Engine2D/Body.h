#ifndef BODY_H
#define BODY_H

#include <windows.h>
#include <utility>//pair포함 헤더
#include "Elements_Initializer.h" //UI 관련 초기화

#include "Input_core.h" //입출력을 위한 헤더

class Body// 윈도우 창 출력을 위한 몸체 프레임워크
{
private:
	HWND hwnd = nullptr;
	HDC hDC = nullptr;
	HDC backDC = nullptr;
	HBITMAP backBitmap = nullptr;

	bool running = true;
	int width = 0, height = 0;

	SceneManager* scenemanager = nullptr; //씬 매니저 클래스의 주소값

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	INPUT_CORE& input = INPUT_CORE::getInst(); //입출력을 위한 구조체


public:
	Body();
	~Body();

	bool Initialize(HINSTANCE hInstance, int nCmdShow, int w, int h, LPCWSTR title);
	void messageLoop();
	void clean();


	HWND getHWND() const { return hwnd; }
	std::pair<HDC, HDC> getDCs() const { return std::make_pair(hDC, backDC); }

	void Draw();
};


#endif