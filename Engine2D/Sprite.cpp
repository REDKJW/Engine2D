#include "Sprite.h"


//easySprite������ ����

Image* easySprite::get_Image()//�̹��� �ּҰ��� ��ȯ
{
	return img;
}

easySprite::easySprite(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei) //������
{
	x = target_x;
	y = target_y;
	width = target_wid;
	height = target_hei;

	img = new Image(filename.c_str());
	if (img->GetLastStatus() != Ok)
	{
		delete img;
		img = nullptr;
	}
}



easySprite::~easySprite()//�Ҹ���
{
	delete img;
}



Rect easySprite::get_rect()
{
	return Rect(x, y, width, height);
}

std::pair<int, int> easySprite::get_size()
{
	return std::make_pair(width, height);
}

std::pair<int, int> easySprite::get_pos()//��ǥ ��ȯ
{
	return std::make_pair(x, y);
}




void easySprite::set_pos(int target_x, int target_y)//��ǥ �̵�
{
	x = target_x;
	y = target_y;
	return;
}




bool easySprite::is_clicked(int mouse_x, int mouse_y) //���콺�� ���ȴ��� Ȯ��
{
	return (mouse_x >= x && mouse_x <= x + width && mouse_y >= y && mouse_y <= y + height);
}

bool easySprite::invalid() //�̹����� ��ȿ�� Ȯ��
{
	return (img != nullptr);
}

int easySprite::getType()
{
	return 0;
}

void easySprite::clicked()
{
}

//==============================================================================================================================================================================

//easyButton������ ���� 

easyButton::easyButton(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei)
	: easySprite(filename, target_x, target_y, target_wid, target_hei)//������
{
	x = target_x;
	y = target_y;
	width = target_wid;
	height = target_hei;

	img = new Image(filename.c_str());
	if (img->GetLastStatus() != Ok)
	{
		delete img;
		img = nullptr;
	}

}


void easyButton::clicked() //Ŭ���� ������ �ൿ�� ����
{
	if (!funcs.empty())
	{
		for (auto& i : funcs)
		{
			try
			{
				i();
			}
			catch (const std::exception& e)
			{
				std::cerr << "��ư�� ���Ͽ�, �� �Լ� �ߵ�" << std::endl;
			}
		}
	}
	return;
}

void easyButton::addAction(std::function<void()> outer_func) //������ �Լ��� �߰��ϴ� �Լ�
{
	funcs.push_back(outer_func);
	return;
}

void easyButton::delAction(int index) //�ش� �ε����� �ش��ϴ� �Լ��� �����ϴ� �Լ�
{
	if (index < funcs.size()) funcs.erase(funcs.begin() + index);
	return;
}


int easyButton::getType()
{
	return 0;
}

//==============================================================================================================================================================================