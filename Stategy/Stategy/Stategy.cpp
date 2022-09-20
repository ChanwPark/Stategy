// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

class Duck {
public:
	Duck() {
	}

	virtual void display() = 0;

	void quack() {
		cout << "�ваŸ���~~~~" << endl;
	}

	void swim() {
		cout << "���ġ��~~~~" << endl;
	}
};


class MallardDuck : public Duck {
public:
	virtual void display() override {
		cout << "���� ��¥ û��������~~" << endl;
	}
};

class RedHeadDuck : public Duck {
public:
	virtual void display() override {
		cout << "�� ��¥ �����Ӹ� ������~~~~" << endl;
	}
};

int main()
{
	unique_ptr<Duck> pMallard = make_unique<MallardDuck>();
	pMallard->quack();
	pMallard->swim();
	pMallard->display();

	unique_ptr<Duck> pRedHeadDuck = make_unique<RedHeadDuck>();
	pRedHeadDuck->quack();
	pRedHeadDuck->swim();
	pRedHeadDuck->display();

	return 0;
}

