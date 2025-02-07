#ifndef INPUT_CORE_H
#define INPUT_CORE_H

#include <vector>
#include <variant>
#include <Windows.h>

//Ű���� �� ���콺 �Է��� Ȯ��

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

	HWND hwnd = nullptr; //���� ������ �ڵ�. �����ǥ�� ���� �ڵ��� �ʿ�


	MOUSE mouse;//���콺 ����ü

	std::vector<bool> key_state;//Ű���� ���� ���¸� �����ϴ� ����

	bool init = false;

public:

	void initializer(HWND outer_hwnd); //�̴ϼȶ�����. �ش� �Լ���, ����� �Է¿� ���� ������ ����.

	static INPUT_CORE& getInst() //�̱��� ������ ���� �ν��Ͻ� ����
	{
		static INPUT_CORE instance;
		return instance;
	}

	void check_input(); //�޽��� ���� ������ �Է��� Ȯ���� �Լ�.

	MOUSE& getMouse()
	{
		return mouse;
	}

	std::vector<bool>* getKey() //���� ���͸� ��ȯ�� �Լ�
	{
		if (!init) return nullptr; //�ʱ�ȭ �����̶�� ����
		return &key_state;
	}
};


#endif