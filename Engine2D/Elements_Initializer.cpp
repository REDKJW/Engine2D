#include "Elements_Initializer.h"

//���鿡 ���� ���� ����Դϴ�.

void start_scene(SceneManager* scenemanager, int x, int y);
void select_mode(SceneManager* scenemanager, int x, int y);
void solo_playing(SceneManager* scenemanager, int x, int y);



//====================================





bool UI_Initializer(SceneManager* manager, HDC hdc, int x, int y)//���� ��ҵ��� ��ü ������Ʈ�� �ʱ�ȭ�մϴ�.
{
	manager->cover_handle(hdc);//�ڵ��� ���� ����ϴ�.
	manager->cover_size(x, y);//�� ũ�⸦ ���� ����ϴ�.

	//���ϴ� ���� �������� �̴ϼȶ�����
	//================================================================================================================================================================================


	start_scene(manager, x, y); //����ȭ�鿡 ���� �̴ϼȶ�����
	
	select_mode(manager, x, y); //����ȭ�鿡 ���� �̴ϼȶ�����

	solo_playing(manager, x, y); //�ַ��÷��� ���ýÿ� ���� �̴ϼȶ�����

	//=================================================================================================================================================================================

	return true;//�ʱ�ȭ�� �����Ͽ����ϴ�.
}


void start_scene(SceneManager* manager, int x, int y) //�Լ� �̸��� ����ڰ� ���� �ۼ�
{
	//1�� �� : ����ȭ�鿡 ���� �ۼ��Դϴ�.
	manager->addScene();//���� �����մϴ�.

	//�̹�����, ���� �Ʒ��� �ִ� �̹�������, �������� ����

	Scene* temp = manager->getScene(0);//�̴ϼȶ����� ���ο��� �ӽ÷� ����� �ּҰ�

	temp->add_sprite(RES_DIR + L"s1\\background.png", 0, 0, 0, x, y);//���ȭ�� ����
	temp->add_sprite(RES_DIR + L"s1\\start_button.png", 1, x / 2 - 150, y / 2, 300, 100);//���۹�ư


	//��ư�� ������ �Ҵ�
	temp->addFunc(1, std::bind(&SceneManager::sceneSwitcher, manager, 1));//0�� ��ư�� ��1 : ����ȭ������ �̵��϶�� �Լ��� �Ҵ�
}

void select_mode(SceneManager* manager, int x, int y) //��� ����Ʈ ȭ�鿡���� �̴ϼȶ�����
{

	//2�� �� : ���� ����ȭ���Դϴ�.
	manager->addScene();//���� �����մϴ�.
	Scene* temp = manager->getScene(0);//�̴ϼȶ����� ���ο��� �ӽ÷� ����� �ּҰ�

	//�̹�����, ���� �Ʒ��� �ִ� �̹�������, �������� ����


	temp = manager->getScene(1);//�̴ϼȶ����� ���ο��� �ӽ÷� ����� �ּҰ�.
	temp->add_sprite(RES_DIR + L"s2\\background.png", 0, 0, 0, x, y);//���ȭ�� ���� : ������Ʈ 0

	//4���� ��ư, �� ������ 50
	temp->add_sprite(RES_DIR + L"s2\\button1.png", 1, x / 2 - 150, 100, 300, 100);//��ư1 : ������Ʈ 1
	temp->add_sprite(RES_DIR + L"s2\\button2.png", 1, x / 2 - 150, 250, 300, 100);//��ư2 : ������Ʈ 2
	temp->add_sprite(RES_DIR + L"s2\\button3.png", 1, x / 2 - 150, 400, 300, 100);//��ư3 : ������Ʈ 3
	temp->add_sprite(RES_DIR + L"s2\\button4.png", 1, x / 2 - 150, 550, 300, 100);//��ư4 : ������Ʈ 4

	//�ش� ��ư�� ������ �Ҵ�
	temp->addFunc(1, std::bind(&SceneManager::sceneSwitcher, manager, 2));//1�� ��ư�� ��2 : �ַ� �÷��̷� �̵��϶�� �Լ��� �Ҵ�
	temp->addFunc(2, std::bind(&SceneManager::sceneSwitcher, manager, 3));//2�� ��ư�� ��3 : p2p �÷��̷� �̵��϶�� �Լ��� �Ҵ�
	temp->addFunc(3, std::bind(&SceneManager::sceneSwitcher, manager, 4));//3�� ��ư�� ��4 : ���� �÷��̷� �̵��϶�� �Լ��� �Ҵ�
	temp->addFunc(4, std::bind(&SceneManager::sceneSwitcher, manager, 0));//4�� ��ư�� ��0 : Ÿ��Ʋ�� ���ư���� �Լ��� �Ҵ�
}

void solo_playing(SceneManager*manager, int x, int y) //�ַ� �÷��̿� ���� ��
{

	//3�� �� : �ַ� �÷��� ȭ���Դϴ�.
	manager->addScene();//���� �����մϴ�.
	Scene* temp = manager->getScene(0);//�̴ϼȶ����� ���ο��� �ӽ÷� ����� �ּҰ�
	//�̹�����, ���� �Ʒ��� �ִ� �̹�������, �������� ����

	temp = manager->getScene(2);//�̴ϼȶ����� ���ο��� �ӽ÷� ����� �ּҰ�.
	temp->add_sprite(RES_DIR + L"s2\\background.png", 0, 0, 0, x, y);//���ȭ�� ����
}