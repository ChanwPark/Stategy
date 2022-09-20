// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

/*
해결책  : 단일 책임이 원칙을 적용하여 행동의 구현하는 방법 구현

*/



class FlyBehavior {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "나는 날고 있다~~~" << endl;
	}
};

class FlyNoWay : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "나는 날 수 없다~~~~" << endl;
	}
};

class QuackBehavior {
public:
	virtual void quack() = 0;
};


class Quack : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "꽥꽥거리다~~~" << endl; 
	}
};

class Squeak : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "빽빽거리다~~~~" << endl; 
	}
};

class MuteQuack : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "아무 것도 하지 않음 ~~~~ 소리를 낼 수 없는 경우 " << endl; 
	}
};

class Duck {
private:
	unique_ptr<FlyBehavior> _pFlyBehavior; 
	unique_ptr<QuackBehavior> _pQuackBehavior; 

public:
	Duck(unique_ptr<FlyBehavior> pFlyBehavior, unique_ptr<QuackBehavior> pQuackBehavior) : 
		_pFlyBehavior(move(pFlyBehavior)), _pQuackBehavior(move(pQuackBehavior)) {
	}


	void performFly() {
		_pFlyBehavior->fly();
	
	}

	void performQuack() {
		_pQuackBehavior->quack();
	}

	virtual void display() = 0;
	virtual void swim() {
		cout << "모든 오리는 떠다닌다 심지어 미끼까지~~~" << endl;
	}
};


class MallardDuck : public Duck {
public:
	MallardDuck() : Duck(make_unique<FlyWithWings>(), make_unique<Quack>()) {

	}


	virtual void display() override {
		cout << "\n====================" << endl;
		cout << "나는 진짜 청동오리야~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "=====================\n" << endl;
	}

};

class RedHeadDuck : public Duck {
public:
	RedHeadDuck() : Duck(make_unique<FlyWithWings>(), make_unique<Quack>()) {

	}


	virtual void display() override {
		cout << "\n===============" << endl; 
		cout << "난 진짜 빨간머리 오리야~~~~" << endl; 
		performQuack();
		performFly();
		swim(); 

		cout << "==================\n" << endl; 
 	}
};

class RubberDuck : public Duck {
public:
	RubberDuck() : Duck(make_unique<FlyWithWings>(), make_unique<Squeak>())
	{

	}

	virtual void display() override {
		cout << "\n================" << endl; 
		cout << "난 고무 오리야 ~~~~" << endl; 
		performQuack();
		performFly();
		swim();
		
		cout << "=================\n" << endl; 
	}


};

//미끼오리 
class DecoyDuck : public Duck {
public:
	DecoyDuck() : Duck(make_unique<FlyNoWay>(), make_unique<MuteQuack>()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 미끼 오리야~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}

};


/*
추가 기능 : 동적으로 행동을 지정하는 방법
실행중 기능을 변경할 수 있는 기능을 추가할 수 있게 기능 개선 

*/

int main()
{
	unique_ptr<Duck> pMallard = make_unique<MallardDuck>();
	pMallard->display();

	unique_ptr<Duck> pRedHeadDuck = make_unique<RedHeadDuck>();
	pRedHeadDuck->display();

	unique_ptr<Duck> pRubberDuck = make_unique<RubberDuck>();
	pRubberDuck->display();

	unique_ptr<Duck> pDecoyDuck = make_unique<DecoyDuck>();
	pDecoyDuck->display();
	return 0;
}

