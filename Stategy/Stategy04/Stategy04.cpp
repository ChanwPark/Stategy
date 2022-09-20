// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

/*
미친 해결책  : 나쁜 방법 유지보수 불가능함 

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
		cout << "헤염치다~~~~" << endl; 
	}
};




class MallardDuck : public Duck, public Flyable, public Quackable {
public:

	virtual void quack() {
		cout << "꽥꽥거리다~~~" << endl;
	}

	virtual void fly() {
		cout << "날다~~~" << endl;
	}


	virtual void display() override {
		cout << "\n================" << endl;
		cout << "나는 진짜 청둥오리야~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

class RedHeadDuck : public Duck, public Flyable, public Quackable {
public:
	virtual void quack() {
		cout << "꽥꽥거리다~~~" << endl;
	}

	virtual void fly() {
		cout << "날다~~~" << endl;
	}


	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 진짜 빨간머리 오리야~~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

class RubberDuck : public Duck, public Quackable {
public:
	virtual void quack() override {
		cout << "삑삑 소리를 내다~~~" << endl;
	}

	//해당 메소드 제거 하여 호출되지 않게 함 
	//virtual void fly() override {
	//}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 고무 오리야~~~" << endl;
		quack();
		swim();
		cout << "================\n" << endl;
	}


};

class DecoyDuck : public Duck {
public:

	//해당 메소드 제거 하여 호출되지 않게 함 
	//virtual void fly() override {
	//}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 미끼 오리야~~~" << endl;
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

	//데모 시연을 하는 중 망함

	unique_ptr<Duck> pRubberDuck = make_unique<RubberDuck>();
	pRubberDuck->display();

	//데모 시연을 하는 중 망함 
	unique_ptr<Duck> pDecoyDuck = make_unique<DecoyDuck>();
	pDecoyDuck->display();
	return 0;
}

