#include "Config.h" //��ũ�� ���

#include "Body.h"
#include <iostream>

//������ ��ü�� �Ǵ� ������ GUI�������̽��� ��ü�Դϴ�.


LRESULT CALLBACK Body::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

Body::Body() : hwnd(nullptr), hDC(nullptr), backDC(nullptr), width(0), height(0)
{

}

Body::~Body()
{
    clean();
}

bool Body::Initialize(HINSTANCE hInstance, int nCmdShow, int w, int h, LPCWSTR title)
{
   
    width = w;
    height = h;


    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = title;

    if (!RegisterClass(&wc))
    {
        std::cerr << "Failed to register window class!" << std::endl;
        return false;
    }

    hwnd = CreateWindowEx(0, title, title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL, NULL, hInstance, NULL);

    if (!hwnd)//���� ����
    {
        std::cerr << "Failed to create window!" << std::endl;
        return false;
    }

    ShowWindow(hwnd, nCmdShow);

 


    //���� ���۸��� ����, �ڵ�� ��Ʈ�� �غ�
    hDC = GetDC(hwnd);
    backDC = CreateCompatibleDC(hDC);
    backBitmap = CreateCompatibleBitmap(hDC, width, height);
    SelectObject(backDC, backBitmap);


    scenemanager = new SceneManager(hDC, backDC, backBitmap);//�� �Ŵ��� ����

    UI_Initializer(scenemanager, hDC, STANDARD_WIDTH, STANDARD_HEIGHT); //���� ���� �ʱ�ȭ.

    scenemanager->sceneSwitcher(ENTRY_SCENE); //�⺻ ���������� �ʱ�ȭ. ���� ������ ���Ŀ� �����ؾ���.


    //���콺 �� Ű���� ������� ���� INPUT CORE ���� �� �ʱ�ȭ
    // 
    //������ �̹� PRIVATE ������ �Ǿ�����
    input.initializer(hwnd); //������ �ڵ� ���� �� �ʱ�ȭ

    return true;

}

void Body::messageLoop()
{
    MSG msg = {};
    while (running)
    {
        //SLEEP�ʿ���. FPS�� ���

        //���콺 �� Ű���� �Է¿� ���� �Լ� �ʿ�.
        
        input.check_input(); //�Է� ��ü�� Ȯ��

        //���⿡ �� �Է��� �� �Ŵ������� ����
        scenemanager->getInput(input.getMouse(), input.getKey());



        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Draw();
    }
}

void Body::Draw()
{
    //todo : �׸� �Լ��� ����
    scenemanager->Draw(); //���� ����

    BitBlt(hDC, 0, 0, width, height, backDC, 0, 0, SRCCOPY); //back DC�� hdc�� �����

}

void Body::clean() {
    if (backBitmap) {
        DeleteObject(backBitmap);
        backBitmap = nullptr;
    }
    if (backDC) {
        DeleteDC(backDC);
        backDC = nullptr;
    }
    if (hDC) {
        ReleaseDC(hwnd, hDC);
        hDC = nullptr;
    }
    hwnd = nullptr;
    return;
}

//winmain�� main.cpp����
