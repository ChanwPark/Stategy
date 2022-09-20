// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

/*
�ذ�å : Duck Ŭ������ �� �޼ҵ忡 virtual�� �߰���

RubberDuck Ŭ������ quack(), fly() ������ �ؼ� ����� �����Ѵ�.


*/

class Duck {
public:
	Duck() {
	}

	virtual void display() = 0;

	virtual void quack() {
		cout << "�ваŸ���~~~~" << endl;
	}

	virtual void swim() {
		cout << "���ġ��~~~~" << endl;
	}

	virtual void fly() {
		cout << "����~~~~" << endl;
	}
};


class MallardDuck : public Duck {
public:
	virtual void display() override {
		cout << "\n=====================" << endl;
		cout << "���� ��¥ û��������~~" << endl;
		quack();
		swim();
		fly();
		cout << "=======================\n" << endl;
	}
};

class RedHeadDuck : public Duck {
public:
	virtual void display() override {
		cout << "\n=====================" << endl;
		cout << "�� ��¥ �����Ӹ� ������~~~~" << endl;
		quack();
		swim();
		fly();
		cout << "=======================\n" << endl;
	}
};

class RubberDuck : public Duck {
public:
	virtual void quack() override {
		cout << "���� �Ҹ��� ����~~~~" << endl;
	}

	virtual void fly() override {

	}

	virtual void display() override {
		cout << "\n=====================" << endl;
		cout << "�� �� ������~~~~" << endl;
		quack();
		swim();
		fly();
		cout << "=======================\n" << endl;
	}
};

int main()
{
	unique_ptr<Duck> pMallard = make_unique<MallardDuck>();
	pMallard->display();

	unique_ptr<Duck> pRedHeadDuck = make_unique<RedHeadDuck>();
	pRedHeadDuck->display();

	//���� �ÿ��� �ϴ� �� ����

	unique_ptr<Duck> pRubberDuck = make_unique<RubberDuck>();
	pRubberDuck->display();

	return 0;
}

