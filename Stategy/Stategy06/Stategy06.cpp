// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


using namespace std;

/*
�ذ�å  : ���� å���� ��Ģ�� �����Ͽ� �ൿ�� �����ϴ� ��� ����

*/



class FlyBehavior {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "���� ���� �ִ�~~~" << endl;
	}
};

class FlyNoWay : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "���� �� �� ����~~~~" << endl;
	}
};

//�߰��� ��� 
class FlyRocketPowered : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "���� �������� ���ư��ϴ�~~~" << endl;
	}
};

class QuackBehavior {
public:
	virtual void quack() = 0;
};


class Quack : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "�ваŸ���~~~" << endl;
	}
};

class Squeak : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "�����Ÿ���~~~~" << endl;
	}
};

class MuteQuack : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "�ƹ� �͵� ���� ���� ~~~~ �Ҹ��� �� �� ���� ��� " << endl;
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

	void setFlyBehavior(unique_ptr<FlyBehavior> pFlyBehavior) {
		_pFlyBehavior = move(pFlyBehavior); 
	}

	void SetQuackBehavior(unique_ptr<QuackBehavior> pQuackBehavior) {
		_pQuackBehavior = move(pQuackBehavior); 
	}

	void performFly() {
		_pFlyBehavior->fly();

	}

	void performQuack() {
		_pQuackBehavior->quack();
	}

	virtual void display() = 0;
	virtual void swim() {
		cout << "��� ������ ���ٴѴ� ������ �̳�����~~~" << endl;
	}
};


class MallardDuck : public Duck {
public:
	MallardDuck() : Duck(make_unique<FlyWithWings>(), make_unique<Quack>()) {

	}


	virtual void display() override {
		cout << "\n====================" << endl;
		cout << "���� ��¥ û��������~~" << endl;
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
		cout << "�� ��¥ �����Ӹ� ������~~~~" << endl;
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
		cout << "�� �� ������ ~~~~" << endl;
		performQuack();
		performFly();
		swim();

		cout << "=================\n" << endl;
	}


};

//�̳����� 
class DecoyDuck : public Duck {
public:
	DecoyDuck() : Duck(make_unique<FlyNoWay>(), make_unique<MuteQuack>()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "�� �̳� ������~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}

};
/*
*  Model ����
*/

class ModelDuck : public Duck {
public:
	ModelDuck() : Duck(make_unique<FlyNoWay>(), make_unique<Quack>()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "�� ���� ���ϴ� �� ������~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}

};



/*
�߰� ��� : �������� �ൿ�� �����ϴ� ���
������ ����� ������ �� �ִ� ����� �߰��� �� �ְ� ��� ����

*/

int main()
{

	unique_ptr<Duck> pMallard = make_unique<MallardDuck>();
	pMallard->display();

	//���Ӱ� �߰��� ��� �׽�Ʈ 
	unique_ptr<Duck> pModelDuck = make_unique<ModelDuck>();
	pModelDuck->display();

	//�߿��� ������ �ൿ�� ������ 
	//���� �ִ� �ൿ�� ���� ����
	pModelDuck->setFlyBehavior(make_unique<FlyRocketPowered>());
	pModelDuck->display();

}

