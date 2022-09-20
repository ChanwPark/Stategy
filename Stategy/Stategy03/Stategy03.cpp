// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

/*
해결책 : Duck 클래스의 각 메소드에 virtual을 추가함

RubberDuck 클래스에 quack(), fly() 재정의 해서 기능을 구현한다.


*/

class Duck {
public:
	Duck() {
	}

	virtual void display() = 0;

	virtual void quack() {
		cout << "꽥꽥거리다~~~~" << endl;
	}

	virtual void swim() {
		cout << "헤엄치다~~~~" << endl;
	}

	virtual void fly() {
		cout << "날다~~~~" << endl;
	}
};


class MallardDuck : public Duck {
public:
	virtual void display() override {
		cout << "\n=====================" << endl;
		cout << "나는 진짜 청동오리야~~" << endl;
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
		cout << "난 진짜 빨간머리 오리야~~~~" << endl;
		quack();
		swim();
		fly();
		cout << "=======================\n" << endl;
	}
};

class RubberDuck : public Duck {
public:
	virtual void quack() override {
		cout << "빽빽 소리를 내다~~~~" << endl;
	}

	virtual void fly() override {

	}

	virtual void display() override {
		cout << "\n=====================" << endl;
		cout << "난 고무 오리야~~~~" << endl;
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

	//데모 시연을 하는 중 망함

	unique_ptr<Duck> pRubberDuck = make_unique<RubberDuck>();
	pRubberDuck->display();

	return 0;
}

