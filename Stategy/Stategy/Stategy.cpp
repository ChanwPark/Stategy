// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
		cout << "꽥꽥거리다~~~~" << endl;
	}

	void swim() {
		cout << "헤엄치다~~~~" << endl;
	}
};


class MallardDuck : public Duck {
public:
	virtual void display() override {
		cout << "나는 진짜 청동오리야~~" << endl;
	}
};

class RedHeadDuck : public Duck {
public:
	virtual void display() override {
		cout << "난 진짜 빨간머리 오리야~~~~" << endl;
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

