#include <iostream>

using namespace std;

class Base {
	public:
		Base() { cout << "Base constructor" << endl; }
		~Base() { cout << "Base destructor" << endl; }
		virtual void foo() { cout << "Base foo" << endl; }
		void bar() { cout << "Base bar" << endl; }
};

class Derived : public Base {
	public:
		Derived() { cout << "Derived constructor" << endl; }
		~Derived() { cout << "Derived destructor" << endl; }
		void foo() { cout << "Derived foo" << endl; }
};

int main() {
	Base x;
	Derived y;
	Base *z = new Derived;
	// Derived *u = new Base; //이건 불가 
	x.foo();
	x.bar();
	y.foo();
	y.bar();
	z->foo();
	z->bar();
}