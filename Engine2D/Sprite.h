#ifndef SPRITE_H
#define SPRITE_H
//��������Ʈ�� ��ӹ��� ��ư Ŭ������ ������Դϴ�.
//������ sprite.cpp���� �����մϴ�.


#include <ole2.h> //stdafx�� ���������� ��� �߰�.
#include <gdiplus.h> //GDI+�� ����ϱ� ���� ���
#include <utility> //std::pair
#include <functional> //std::function
#include <vector>
#include <string>
#include <iostream> //������ ��ȯ�� ���� iostream

#pragma comment (lib, "gdiplus.lib")
using namespace Gdiplus;

//===========================================================================================================================================================================================
class easySprite//�⺻ �̹��� ��������Ʈ
{
protected:
	int x = 0; //���� ��ǥ : �»���� 0
	int y = 0; //���� ��ǥ : �»���� 0
	int width = 0;
	int height = 0;

	Image* img = nullptr;

public:
	Image* get_Image(); //�ش� ��������Ʈ�� �̹��� �ּҰ��� ��ȯ�ϴ� �Լ�
	easySprite(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei);//������
	~easySprite();//�Ҹ���


	Rect get_rect(); //rect���·� �޾ƿ�.
	std::pair<int, int> get_size(); //ũ�⸦ ��ȯ�ϴ� �Լ�
	std::pair<int, int> get_pos(); //�ش� ��������Ʈ�� x, y�� ��ȯ�ϴ� �Լ�
	
	void set_pos(int target_x, int target_y); //�ش� ��������Ʈ�� ��ǥ�� �����ϴ� �Լ�.

	bool is_clicked(int mouse_x, int mouse_y); //���콺 Ŭ����, ��ǥ�� ��������Ʈ ��ǥ�� ��
	
	bool invalid(); //�̹����� �ּҰ��� ��ȿ���� ��ȯ�ϴ� �Լ�
	
	virtual void clicked(); //����� ���� �Լ�. ������ ���, ������ ��� ������ ����.
	virtual int getType(); //��������Ʈ Ÿ�� ��
};

//===========================================================================================================================================================================================

class easyButton : public easySprite //��ӹ��� ��ư Ŭ������ ����
{
protected:
	std::vector<std::function<void()>> funcs; //�Լ� �����̳�

public:
	easyButton(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei);//������ ���
	void clicked() override; //������ ���� ������ ������ ����

	void addAction(std::function<void()> outer_func); //�ܺο��� �Լ��� �ּҰ��� �޾�, �����̳ʿ� �߰�.

	void delAction(int index); //�ش� �ε����� �ش��ϴ� �Լ��� �����̳ʿ��� ����
	
	int getType() override;
};
//===========================================================================================================================================================================================

#endif