#ifndef SCENEMANAGEMENT_H
#define SCENEMANAGEMENT_H

//씬 매니저와 씬의 선언입니다.
//구현은 scene management.cpp에서 구현합니다.

#include <windows.h> //hdc등을 선언하기 위한 헤더


#include <memory> //
#include <typeindex> //type 비교를 위한 헤더. 사용하나? 확인필요


#include "Sprite.h" //iostream, string, vector, function, utility, gdiplus는 sprite에 포함되어있음.

//씬과 씬 매니저 클래스를 선언


//씬 선언

class Scene //개별 씬
{
private:
	std::vector<std::pair<std::shared_ptr<easySprite>, bool>> all_sprite;//스프라이트 총괄 벡터 컨테이너, bool = 출력 여부 고려. 객체 삭제 없이 출력만 안 할 수 있도록.
	HDC hdc = nullptr;//사용할 핸들 주소값. 핸들은 그 자체로 주소값임.
	HDC backdc = nullptr;
	HBITMAP backBitmap = nullptr;
	Graphics* graphics;

	int sceneWidth = 0;//씬의 크기
	int sceneHeight = 0;//씬의 높이

public:

	Scene(HDC extern_hdc, HDC extern_backdc, HBITMAP external_bitmap, int sW, int sH); //생성자
	~Scene(); //소멸자

	void print_sprite(size_t start = 0, size_t count = -1); //스프라이트를 출력한다. 정해진 개수까지

	bool switching(int index); //인덱스에 해당하는 스프라이트의 on/off를 전환
	bool delete_sprite(size_t start, size_t count = 1); //특정 위치의 스프라이트를 삭제 : 스프라이트 시작 위치, 개수 / 시작 위치는 0부터 시작함
	bool add_sprite(const std::wstring& filename, int type, int x, int y, int wid, int hei); //새로운 스프라이트를 생성 : 파일명, 클래스 종류, 시작 좌표 x, y, 너비, 높이
	
	void click(int mouse_x, int mouse_y); //클릭했을 경우, 출력된 모든 버튼에 대하여 마우스와 충돌확인

	void addFunc(int target_button, std::function<void()> func); //타겟 버튼과 적용할 함수. 함수를 버튼에 할당하는 함수.


};

//씬 매니저 선언
class SceneManager //총괄 씬 관리 클래스
{
private:
	HDC hdc = nullptr;
	HDC backDc = nullptr;
	HBITMAP BACKBIT = nullptr;

	ULONG_PTR gdiplusToken;

	int sceneNow = -1;//현재 씬

	int width = 0;
	int height = 0;

	std::vector<Scene*> scenes;//씬 전체를 다루는 컨테이너. 용량의 문제로 주소값만 다룰 예정. free에 주의


public:
	SceneManager(HDC external_hdc, HDC external_backdc, HBITMAP external_bitmap); //생성자
	int addScene(); //씬을 추가하고, 총 씬의 개수를 반환

	Scene* getScene(int index); //인덱스에 해당하는 씬의 주소값을 반환

	void sceneSwitcher(int target_index); //씬을 전환하는 함수

	void cover_size(int x, int y); //씬 크기 덮어씌우기.
	bool cover_handle(HDC temp); //핸들 덮어씌우기

	~SceneManager(); //소멸자

	void Draw(); //출력함수

};




#endif
