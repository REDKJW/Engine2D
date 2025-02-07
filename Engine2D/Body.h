#ifndef BODY_H
#define BODY_H

#include <windows.h>
#include <utility>//pair���� ���
#include "Elements_Initializer.h" //UI ���� �ʱ�ȭ

#include "Input_core.h" //������� ���� ���

class Body// ������ â ����� ���� ��ü �����ӿ�ũ
{
private:
	HWND hwnd = nullptr;
	HDC hDC = nullptr;
	HDC backDC = nullptr;
	HBITMAP backBitmap = nullptr;

	bool running = true;
	int width = 0, height = 0;

	SceneManager* scenemanager = nullptr; //�� �Ŵ��� Ŭ������ �ּҰ�

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	INPUT_CORE& input = INPUT_CORE::getInst(); //������� ���� ����ü


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