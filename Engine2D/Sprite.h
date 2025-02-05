#ifndef SPRITE_H
#define SPRITE_H
//스프라이트와 상속받은 버튼 클래스의 선언부입니다.
//구현은 sprite.cpp에서 구현합니다.


#include <ole2.h> //stdafx가 지워버리는 헤더 추가.
#include <gdiplus.h> //GDI+를 사용하기 위한 헤더
#include <utility> //std::pair
#include <functional> //std::function
#include <vector>
#include <string>
#include <iostream> //에러문 반환을 위한 iostream

#pragma comment (lib, "gdiplus.lib")
using namespace Gdiplus;

//===========================================================================================================================================================================================
class easySprite//기본 이미지 스프라이트
{
protected:
	int x = 0; //시작 좌표 : 좌상단이 0
	int y = 0; //시작 좌표 : 좌상단이 0
	int width = 0;
	int height = 0;

	Image* img = nullptr;

public:
	Image* get_Image(); //해당 스프라이트의 이미지 주소값을 반환하는 함수
	easySprite(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei);//생성자
	~easySprite();//소멸자


	Rect get_rect(); //rect형태로 받아옴.
	std::pair<int, int> get_size(); //크기를 반환하는 함수
	std::pair<int, int> get_pos(); //해당 스프라이트의 x, y를 반환하는 함수
	
	void set_pos(int target_x, int target_y); //해당 스프라이트의 좌표를 변경하는 함수.

	bool is_clicked(int mouse_x, int mouse_y); //마우스 클릭시, 좌표와 스프라이트 좌표를 비교
	
	bool invalid(); //이미지의 주소값이 유효한지 반환하는 함수
	
	virtual void clicked(); //상속을 위한 함수. 눌렸을 경우, 이하의 모든 동작을 수행.
	virtual int getType(); //스프라이트 타입 비교
};

//===========================================================================================================================================================================================

class easyButton : public easySprite //상속받은 버튼 클래스의 정의
{
protected:
	std::vector<std::function<void()>> funcs; //함수 컨테이너

public:
	easyButton(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei);//생성자 명시
	void clicked() override; //눌렀을 때에 이하의 동작을 수행

	void addAction(std::function<void()> outer_func); //외부에서 함수의 주소값을 받아, 컨테이너에 추가.

	void delAction(int index); //해당 인덱스에 해당하는 함수를 컨테이너에서 제거
	
	int getType() override;
};
//===========================================================================================================================================================================================

#endif