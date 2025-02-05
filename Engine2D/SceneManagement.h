#ifndef SCENEMANAGEMENT_H
#define SCENEMANAGEMENT_H

//�� �Ŵ����� ���� �����Դϴ�.
//������ scene management.cpp���� �����մϴ�.

#include <windows.h> //hdc���� �����ϱ� ���� ���


#include <memory> //
#include <typeindex> //type �񱳸� ���� ���. ����ϳ�? Ȯ���ʿ�


#include "Sprite.h" //iostream, string, vector, function, utility, gdiplus�� sprite�� ���ԵǾ�����.

//���� �� �Ŵ��� Ŭ������ ����


//�� ����

class Scene //���� ��
{
private:
	std::vector<std::pair<std::shared_ptr<easySprite>, bool>> all_sprite;//��������Ʈ �Ѱ� ���� �����̳�, bool = ��� ���� ���. ��ü ���� ���� ��¸� �� �� �� �ֵ���.
	HDC hdc = nullptr;//����� �ڵ� �ּҰ�. �ڵ��� �� ��ü�� �ּҰ���.
	HDC backdc = nullptr;
	HBITMAP backBitmap = nullptr;
	Graphics* graphics;

	int sceneWidth = 0;//���� ũ��
	int sceneHeight = 0;//���� ����

public:

	Scene(HDC extern_hdc, HDC extern_backdc, HBITMAP external_bitmap, int sW, int sH); //������
	~Scene(); //�Ҹ���

	void print_sprite(size_t start = 0, size_t count = -1); //��������Ʈ�� ����Ѵ�. ������ ��������

	bool switching(int index); //�ε����� �ش��ϴ� ��������Ʈ�� on/off�� ��ȯ
	bool delete_sprite(size_t start, size_t count = 1); //Ư�� ��ġ�� ��������Ʈ�� ���� : ��������Ʈ ���� ��ġ, ���� / ���� ��ġ�� 0���� ������
	bool add_sprite(const std::wstring& filename, int type, int x, int y, int wid, int hei); //���ο� ��������Ʈ�� ���� : ���ϸ�, Ŭ���� ����, ���� ��ǥ x, y, �ʺ�, ����
	
	void click(int mouse_x, int mouse_y); //Ŭ������ ���, ��µ� ��� ��ư�� ���Ͽ� ���콺�� �浹Ȯ��

	void addFunc(int target_button, std::function<void()> func); //Ÿ�� ��ư�� ������ �Լ�. �Լ��� ��ư�� �Ҵ��ϴ� �Լ�.


};

//�� �Ŵ��� ����
class SceneManager //�Ѱ� �� ���� Ŭ����
{
private:
	HDC hdc = nullptr;
	HDC backDc = nullptr;
	HBITMAP BACKBIT = nullptr;

	ULONG_PTR gdiplusToken;

	int sceneNow = -1;//���� ��

	int width = 0;
	int height = 0;

	std::vector<Scene*> scenes;//�� ��ü�� �ٷ�� �����̳�. �뷮�� ������ �ּҰ��� �ٷ� ����. free�� ����


public:
	SceneManager(HDC external_hdc, HDC external_backdc, HBITMAP external_bitmap); //������
	int addScene(); //���� �߰��ϰ�, �� ���� ������ ��ȯ

	Scene* getScene(int index); //�ε����� �ش��ϴ� ���� �ּҰ��� ��ȯ

	void sceneSwitcher(int target_index); //���� ��ȯ�ϴ� �Լ�

	void cover_size(int x, int y); //�� ũ�� ������.
	bool cover_handle(HDC temp); //�ڵ� ������

	~SceneManager(); //�Ҹ���

	void Draw(); //����Լ�

};




#endif
