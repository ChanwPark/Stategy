// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

/*
��ģ �ذ�å  : ���� ��� �������� �Ұ����� 

*/
class Flyable {
	virtual void fly() = 0; 
};

class Quackable {
	virtual void quack() = 0; 
};



class Duck {
public:
	Duck() {
	}

	virtual void display() = 0;
	virtual void swim() {
		cout << "�쿰ġ��~~~~" << endl; 
	}
};




class MallardDuck : public Duck, public Flyable, public Quackable {
public:

	virtual void quack() {
		cout << "�ваŸ���~~~" << endl;
	}

	virtual void fly() {
		cout << "����~~~" << endl;
	}


	virtual void display() override {
		cout << "\n================" << endl;
		cout << "���� ��¥ û�տ�����~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

class RedHeadDuck : public Duck, public Flyable, public Quackable {
public:
	virtual void quack() {
		cout << "�ваŸ���~~~" << endl;
	}

	virtual void fly() {
		cout << "����~~~" << endl;
	}


	virtual void display() override {
		cout << "\n================" << endl;
		cout << "�� ��¥ �����Ӹ� ������~~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

class RubberDuck : public Duck, public Quackable {
public:
	virtual void quack() override {
		cout << "��� �Ҹ��� ����~~~" << endl;
	}

	//�ش� �޼ҵ� ���� �Ͽ� ȣ����� �ʰ� �� 
	//virtual void fly() override {
	//}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "�� �� ������~~~" << endl;
		quack();
		swim();
		cout << "================\n" << endl;
	}


};

class DecoyDuck : public Duck {
public:

	//�ش� �޼ҵ� ���� �Ͽ� ȣ����� �ʰ� �� 
	//virtual void fly() override {
	//}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "�� �̳� ������~~~" << endl;
		swim();
		cout << "================\n" << endl;
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

	//���� �ÿ��� �ϴ� �� ���� 
	unique_ptr<Duck> pDecoyDuck = make_unique<DecoyDuck>();
	pDecoyDuck->display();
	return 0;
}

