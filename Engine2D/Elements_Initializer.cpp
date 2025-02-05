#include "Elements_Initializer.h"


bool initializer(SceneManager* manager, HDC hdc, int x, int y)//구성 요소들의 전체 프로젝트를 초기화합니다.
{
	manager->cover_handle(hdc);//핸들을 덮어 씌웁니다.
	manager->cover_size(x, y);//씬 크기를 덮어 씌웁니다.

	//================================================================================================================================================================================
	//1번 씬 : 메인화면에 대한 작성입니다.
	manager->addScene();//씬을 생성합니다.

	//이미지는, 가장 아래에 있는 이미지부터, 역순으로 선언

	Scene* temp = manager->getScene(0);//이니셜라이저 내부에서 임시로 사용할 주소값

    temp->add_sprite(RES_DIR + L"s1\\background.png", 0, 0, 0, x, y);//배경화면 선언
	temp->add_sprite(RES_DIR + L"s1\\start_button.png", 1, x/2 - 150, y / 2, 300, 100);//시작버튼
	

	//버튼의 역할을 할당
	temp->addFunc(0, std::bind(&SceneManager::sceneSwitcher, manager, 1));//0번 버튼에 씬1 : 선택화면으로 이동하라는 함수를 할당


	//=================================================================================================================================================================================
	//2번 씬 : 게임 선택화면입니다.
	manager->addScene();//씬을 생성합니다.

	//이미지는, 가장 아래에 있는 이미지부터, 역순으로 선언
	

	temp = manager->getScene(1);//이니셜라이저 내부에서 임시로 사용할 주소값.
	temp->add_sprite(RES_DIR + L"s2\\background.png", 0, 0, 0, x, y);//배경화면 선언

	//4개의 버튼, 각 간격은 50
	temp->add_sprite(RES_DIR + L"s1\\button1.png", 1, x - 150, 100, 300, 100);//버튼1
	temp->add_sprite(RES_DIR + L"s1\\button2.png", 1, x - 150, 250, 300, 100);//버튼2
	temp->add_sprite(RES_DIR + L"s1\\button3.png", 1, x - 150, 400, 300, 100);//버튼3
	temp->add_sprite(RES_DIR + L"s1\\button4.png", 1, x - 150, 550, 300, 100);//버튼4

	//해당 버튼의 역할을 할당
	temp->addFunc(0, std::bind(&SceneManager::sceneSwitcher, manager, 2));//0번 버튼에 씬2 : 솔로 플레이로 이동하라는 함수를 할당
	temp->addFunc(1, std::bind(&SceneManager::sceneSwitcher, manager, 3));//1번 버튼에 씬3 : p2p 플레이로 이동하라는 함수를 할당
	temp->addFunc(2, std::bind(&SceneManager::sceneSwitcher, manager, 4));//2번 버튼에 씬4 : 서버 플레이로 이동하라는 함수를 할당
	temp->addFunc(3, std::bind(&SceneManager::sceneSwitcher, manager, 0));//3번 버튼에 씬0 : 타이틀로 돌아가라는 함수를 할당
	//=================================================================================================================================================================================
	//3번 씬 : 솔로 플레잉 화면입니다.
	manager->addScene();//씬을 생성합니다.

	//이미지는, 가장 아래에 있는 이미지부터, 역순으로 선언

	temp = manager->getScene(2);//이니셜라이저 내부에서 임시로 사용할 주소값.
	temp->add_sprite(RES_DIR + L"s2\\background.png", 0, 0, 0, x, y);//배경화면 선언


	//=================================================================================================================================================================================

	return true;//초기화에 성공하였습니다.
}