#include "Config.h" //매크로 헤더

#include "Body.h"
#include <iostream>

//엔진의 몸체가 되는 윈도우 GUI인터페이스의 몸체입니다.


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

    if (!hwnd)//생성 실패
    {
        std::cerr << "Failed to create window!" << std::endl;
        return false;
    }

    ShowWindow(hwnd, nCmdShow);

 


    //더블 버퍼링을 위한, 핸들과 비트맵 준비
    hDC = GetDC(hwnd);
    backDC = CreateCompatibleDC(hDC);
    backBitmap = CreateCompatibleBitmap(hDC, width, height);
    SelectObject(backDC, backBitmap);


    scenemanager = new SceneManager(hDC, backDC, backBitmap);//씬 매니저 생성

    UI_Initializer(scenemanager, hDC, STANDARD_WIDTH, STANDARD_HEIGHT); //구성 원소 초기화.

    scenemanager->sceneSwitcher(ENTRY_SCENE); //기본 진입점으로 초기화. 씬이 생성된 이후에 접근해야함.


    //마우스 및 키보드 입출력을 위한 INPUT CORE 생성 및 초기화
    // 
    //생성은 이미 PRIVATE 영역에 되어있음
    input.initializer(hwnd); //윈도우 핸들 전달 및 초기화

    return true;

}

void Body::messageLoop()
{
    MSG msg = {};
    while (running)
    {
        //SLEEP필요함. FPS로 사용

        //마우스 및 키보드 입력에 대한 함수 필요.
        
        input.check_input(); //입력 자체를 확인

        //여기에 그 입력을 씬 매니저에게 전달
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
    //todo : 그릴 함수를 적용
    scenemanager->Draw(); //문제 유력

    BitBlt(hDC, 0, 0, width, height, backDC, 0, 0, SRCCOPY); //back DC를 hdc에 덮어씌움

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

//winmain은 main.cpp에서
