#ifndef INPUT_CORE_H
#define INPUT_CORE_H

#include <vector>
#include <variant>
#include <Windows.h>

//키보드 및 마우스 입력을 확인

struct MOUSE
{
	POINT pos = { 0, 0 };
	bool Lclicked = false;
};


class INPUT_CORE
{
private:
	INPUT_CORE();
	~INPUT_CORE();
	INPUT_CORE(const INPUT_CORE&) = delete;
	INPUT_CORE& operator=(const INPUT_CORE&) = delete;

	HWND hwnd = nullptr; //메인 윈도우 핸들. 상대좌표를 위해 핸들이 필요


	MOUSE mouse;//마우스 구조체

	std::vector<bool> key_state;//키들의 눌린 상태를 저장하는 벡터

	bool init = false;

public:

	void initializer(HWND outer_hwnd); //이니셜라이저. 해당 함수는, 사용할 입력에 따라 별도로 구현.

	static INPUT_CORE& getInst() //싱글톤 패턴을 위한 인스턴스 전달
	{
		static INPUT_CORE instance;
		return instance;
	}

	void check_input(); //메시지 루프 내에서 입력을 확인할 함수.

	MOUSE& getMouse()
	{
		return mouse;
	}

	std::vector<bool>* getKey() //위의 벡터를 반환할 함수
	{
		if (!init) return nullptr; //초기화 이전이라면 거절
		return &key_state;
	}
};


#endif