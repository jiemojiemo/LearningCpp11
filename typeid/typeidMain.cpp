#include <iostream>
#include <typeinfo>

using namespace std;

class Black{
};

class White
{
};


int main()
{
	White a;
	Black b;

	cout << typeid(a).name() << endl; // class White
	cout << typeid(b).name() << endl; // class Black

	White c;
	
	bool aAndBIsSameTypeA = (typeid(a).hash_code() == typeid(b).hash_code());

	bool aAndCIsSameType = (typeid(a).hash_code() == typeid(c).hash_code());

	cout << "Same type? " << endl;
	cout << "A and B? " << (int)aAndBIsSameTypeA << endl; // 0
	cout << "A and C? " << (int)aAndCIsSameType << endl;  // 1
}