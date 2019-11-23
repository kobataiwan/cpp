#include <iostream>

using namespace std;

class Animals {
	public:
		virtual void voice () {
			cout << "no" << endl;
		}
};

class Cat: public Animals {
	public:
		void voice () {
			cout << "meow" << endl;
		}
};

class Dog: public Animals {
	public: 
		void voice () {
			cout << "bow-wow" << endl;
		}
};

int main()
{
	Cat cat;
	Dog dog;
	Animals* an = &cat;

	an->voice();

	an = &dog;
	an->voice();
	
	return 0;
}
