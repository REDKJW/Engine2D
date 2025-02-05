#include "Sprite.h"


//easySprite구현부 시작

Image* easySprite::get_Image()//이미지 주소값을 반환
{
	return img;
}

easySprite::easySprite(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei) //생성자
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



easySprite::~easySprite()//소멸자
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

std::pair<int, int> easySprite::get_pos()//좌표 반환
{
	return std::make_pair(x, y);
}




void easySprite::set_pos(int target_x, int target_y)//좌표 이동
{
	x = target_x;
	y = target_y;
	return;
}




bool easySprite::is_clicked(int mouse_x, int mouse_y) //마우스가 눌렸는지 확인
{
	return (mouse_x >= x && mouse_x <= x + width && mouse_y >= y && mouse_y <= y + height);
}

bool easySprite::invalid() //이미지의 유효성 확인
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

//easyButton구현부 시작 

easyButton::easyButton(const std::wstring& filename, int target_x, int target_y, int target_wid, int target_hei)
	: easySprite(filename, target_x, target_y, target_wid, target_hei)//생성자
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


void easyButton::clicked() //클릭시 이하의 행동을 진행
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
				std::cerr << "버튼에 대하여, 빈 함수 발동" << std::endl;
			}
		}
	}
	return;
}

void easyButton::addAction(std::function<void()> outer_func) //동작할 함수를 추가하는 함수
{
	funcs.push_back(outer_func);
	return;
}

void easyButton::delAction(int index) //해당 인덱스에 해당하는 함수를 제거하는 함수
{
	if (index < funcs.size()) funcs.erase(funcs.begin() + index);
	return;
}


int easyButton::getType()
{
	return 0;
}

//==============================================================================================================================================================================