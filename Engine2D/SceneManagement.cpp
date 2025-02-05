#include "SceneManagement.h"


//씬 클래스 구현부

Scene::Scene(HDC extern_hdc, HDC extern_backdc, HBITMAP external_bitmap, int sW, int sH)
{
	hdc = extern_hdc;
	backdc = extern_backdc;
	backBitmap = external_bitmap;
	sceneWidth = sW;
	sceneHeight = sH;


	SelectObject(backdc, backBitmap);

	//if (!hdc)MessageBox(NULL, L"hdc null", NULL, MB_OK); null아님
	//if (!backdc)MessageBox(NULL, L"hdc null", NULL, MB_OK); null아님

	graphics = new Graphics(backdc);
	if(!graphics) MessageBox(NULL, L"graphics null", NULL, MB_OK);

}

Scene::~Scene()
{
	delete graphics;
	DeleteObject(backBitmap);
	DeleteDC(backdc);
}

void Scene::print_sprite(size_t start, size_t count)//스프라이트를 출력한다. 정해진 개수까지
{
	if (count == -1) count = all_sprite.size();
	SolidBrush whiteBrush(Color(255, 255, 255)); //백그라운드 덮어쓰기
	graphics->FillRectangle(&whiteBrush, 0, 0, sceneWidth, sceneHeight);

	if (start + count > all_sprite.size())return;//범위 초과

	for (size_t i = 0; i < count; i++)
	{
		if (all_sprite[start + i].second)//true의 경우만 출력
		{
			Rect rect = all_sprite[start + i].first->get_rect();
			graphics->DrawImage(all_sprite[start + i].first->get_Image(), rect);
		}
	}
	return;
}


bool Scene::switching(int index)
{
	if (all_sprite.size() <= index)return false;
	else all_sprite[index].second != all_sprite[index].second;

	return true;
}

bool Scene::delete_sprite(size_t start, size_t count)//특정 위치의 스프라이트를 삭제 : 스프라이트 시작 위치, 개수 / 시작 위치는 0부터 시작함
{
	if (start >= all_sprite.size() || start + count > all_sprite.size()) return false; //범위 초과

	all_sprite.erase(all_sprite.begin() + start, all_sprite.begin() + start + count);//구간 삭제

	return true;
}

bool Scene::add_sprite(const std::wstring& filename, int type, int x, int y, int wid, int hei)//새로운 스프라이트를 생성 : 파일명, 클래스 종류, 시작 좌표 x, y, 너비, 높이
{
	if (type == 0)//기본 스프라이트
	{
		all_sprite.push_back(std::make_pair(std::make_shared<easySprite>(filename, x, y, wid, hei), true));
	}
	else if (type == 1)//버튼
	{
		all_sprite.push_back(std::make_pair(std::make_shared<easyButton>(filename, x, y, wid, hei), true));
	}
	else
	{

	}

	return true;//성공적으로 끝마쳤음
}

void Scene::click(int mouse_x, int mouse_y)
{
	for (size_t i = all_sprite.size() - 1; i > -1; i--)
	{
		//클릭은 역순으로
		if (all_sprite[i].first->getType() == 1)//버튼에 대해서만
		{
			if (all_sprite[i].first->is_clicked(mouse_x, mouse_y))//클릭된 버튼 객체를 찾았음
			{
				auto child_ptr = std::dynamic_pointer_cast<easyButton>(all_sprite[i].first);
				child_ptr->clicked();
				return;
			}
		}
	}
}

void Scene::addFunc(int target_button, std::function<void()> func)//타겟 버튼과 적용할 함수
{
	if (all_sprite.size() <= target_button)return;//유효성 확인

	auto child_ptr = std::dynamic_pointer_cast<easyButton>(all_sprite[target_button].first);
	if (child_ptr) //버튼 맞나 확인
	{
		child_ptr->addAction(func);
	}
}



//==========================================================================================================================================================================

//씬 매니저 구현부



SceneManager::SceneManager(HDC external_hdc, HDC external_backdc, HBITMAP external_bitmap) //생성자
{
	hdc = external_hdc;
	backDc = external_backdc;
	BACKBIT = external_bitmap;

	GdiplusStartupInput gdiplusstartupinput;
	Status status = GdiplusStartup(&gdiplusToken, &gdiplusstartupinput, nullptr);

	if (status != Ok) exit(1);

}
int SceneManager::addScene() //씬을 추가하고, 총 씬의 개수를 반환
{
	Scene* temp = new Scene(hdc, backDc, BACKBIT, width, height);
	scenes.push_back(temp);
	return scenes.size();
}

Scene* SceneManager::getScene(int index) //인덱스에 해당하는 씬의 주소값을 반환
{
	if (index >= scenes.size())return nullptr;
	else return scenes[index];
}

void SceneManager::sceneSwitcher(int target_index) //씬을 전환하는 함수
{
	sceneNow = target_index;
	//메모리 로딩 등이 필요한 경우, 해당 함수를 수정

	return;
}

void SceneManager::cover_size(int x, int y) //씬 크기 덮어씌우기.
{
	width = x;
	height = y;
	return;
}
bool SceneManager::cover_handle(HDC temp) //핸들 덮어씌우기
{
	hdc = temp;
	return (hdc != nullptr);
}

SceneManager::~SceneManager() //소멸자
{
	if (backDc)
	{
		DeleteDC(backDc);
		backDc = nullptr;
	}
	for (auto& i : scenes)
	{
		delete(i);
	}
	scenes.clear();
	GdiplusShutdown(gdiplusToken);
}

void SceneManager::Draw() //출력함수. SCENEMANAGER->SCENE[INDEX].DRAW로 호출
{

	if (sceneNow >= scenes.size())return;//유효성 확인
	//해당 씬에 대한 그래픽함수 호출
	
	scenes[sceneNow]->print_sprite();//back DC에 출력
	return;
}







//=====================================================================================================================================================================