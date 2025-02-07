#include "Elements_Initializer.h"

//씬들에 대한 정의 목록입니다.

void start_scene(SceneManager* scenemanager, int x, int y);
void select_mode(SceneManager* scenemanager, int x, int y);
void solo_playing(SceneManager* scenemanager, int x, int y);



//====================================





bool UI_Initializer(SceneManager* manager, HDC hdc, int x, int y)//구성 요소들의 전체 프로젝트를 초기화합니다.
{
	manager->cover_handle(hdc);//핸들을 덮어 씌웁니다.
	manager->cover_size(x, y);//씬 크기를 덮어 씌웁니다.

	//이하는 개별 씬에대한 이니셜라이저
	//================================================================================================================================================================================


	start_scene(manager, x, y); //시작화면에 대한 이니셜라이저
	
	select_mode(manager, x, y); //선택화면에 대한 이니셜라이저

	solo_playing(manager, x, y); //솔로플레이 선택시에 대한 이니셜라이저

	//=================================================================================================================================================================================

	return true;//초기화에 성공하였습니다.
}


void start_scene(SceneManager* manager, int x, int y) //함수 이름은 사용자가 직접 작성
{
	//1번 씬 : 메인화면에 대한 작성입니다.
	manager->addScene();//씬을 생성합니다.

	//이미지는, 가장 아래에 있는 이미지부터, 역순으로 선언

	Scene* temp = manager->getScene(0);//이니셜라이저 내부에서 임시로 사용할 주소값

	temp->add_sprite(RES_DIR + L"s1\\background.png", 0, 0, 0, x, y);//배경화면 선언
	temp->add_sprite(RES_DIR + L"s1\\start_button.png", 1, x / 2 - 150, y / 2, 300, 100);//시작버튼


	//버튼의 역할을 할당
	temp->addFunc(1, std::bind(&SceneManager::sceneSwitcher, manager, 1));//0번 버튼에 씬1 : 선택화면으로 이동하라는 함수를 할당
}

void select_mode(SceneManager* manager, int x, int y) //모드 셀렉트 화면에대한 이니셜라이저
{

	//2번 씬 : 게임 선택화면입니다.
	manager->addScene();//씬을 생성합니다.
	Scene* temp = manager->getScene(0);//이니셜라이저 내부에서 임시로 사용할 주소값

	//이미지는, 가장 아래에 있는 이미지부터, 역순으로 선언


	temp = manager->getScene(1);//이니셜라이저 내부에서 임시로 사용할 주소값.
	temp->add_sprite(RES_DIR + L"s2\\background.png", 0, 0, 0, x, y);//배경화면 선언 : 오브젝트 0

	//4개의 버튼, 각 간격은 50
	temp->add_sprite(RES_DIR + L"s2\\button1.png", 1, x / 2 - 150, 100, 300, 100);//버튼1 : 오브젝트 1
	temp->add_sprite(RES_DIR + L"s2\\button2.png", 1, x / 2 - 150, 250, 300, 100);//버튼2 : 오브젝트 2
	temp->add_sprite(RES_DIR + L"s2\\button3.png", 1, x / 2 - 150, 400, 300, 100);//버튼3 : 오브젝트 3
	temp->add_sprite(RES_DIR + L"s2\\button4.png", 1, x / 2 - 150, 550, 300, 100);//버튼4 : 오브젝트 4

	//해당 버튼의 역할을 할당
	temp->addFunc(1, std::bind(&SceneManager::sceneSwitcher, manager, 2));//1번 버튼에 씬2 : 솔로 플레이로 이동하라는 함수를 할당
	temp->addFunc(2, std::bind(&SceneManager::sceneSwitcher, manager, 3));//2번 버튼에 씬3 : p2p 플레이로 이동하라는 함수를 할당
	temp->addFunc(3, std::bind(&SceneManager::sceneSwitcher, manager, 4));//3번 버튼에 씬4 : 서버 플레이로 이동하라는 함수를 할당
	temp->addFunc(4, std::bind(&SceneManager::sceneSwitcher, manager, 0));//4번 버튼에 씬0 : 타이틀로 돌아가라는 함수를 할당
}

void solo_playing(SceneManager*manager, int x, int y) //솔로 플레이에 대한 씬
{

	//3번 씬 : 솔로 플레잉 화면입니다.
	manager->addScene();//씬을 생성합니다.
	Scene* temp = manager->getScene(0);//이니셜라이저 내부에서 임시로 사용할 주소값
	//이미지는, 가장 아래에 있는 이미지부터, 역순으로 선언

	temp = manager->getScene(2);//이니셜라이저 내부에서 임시로 사용할 주소값.
	temp->add_sprite(RES_DIR + L"s2\\background.png", 0, 0, 0, x, y);//배경화면 선언
}