#include <iostream>
#include <memory>

using namespace std;

void TestA()
{
	auto up1 = make_unique<int>(10);
	//auto up2 = up1; // error
	cout << *up1 << endl;

	auto up3( std::move(up1) );
	cout << *up3 << endl;
	//cout << *up1 << endl; // error, up1 is invalid

	up3.reset();
	up1.reset(); // is ok
	//cout << *up3 << endl; // error, up3 is invalid after reset()

	auto sp1 = make_shared<int>(20);
	auto sp2(sp1);

	cout << *sp1 << endl;
	cout << *sp2 << endl;

	sp1.reset();
	cout << *sp2 << endl;
}

void Check(weak_ptr<int>& wp)
{
	auto sp(wp.lock());

	if (sp != nullptr)
	{
		cout << "still " << *sp << endl;
	}
	else
	{
		cout << "pointer is invalid." << endl;
	}
}

void TestB()
{
	auto sp1(make_shared<int>(22));
	auto sp2(sp1);
	weak_ptr<int> wp(sp1);

	cout << *sp1 << endl;	// 22
	cout << *sp2 << endl;	// 22
	Check(wp);				// still 22

	sp1.reset();			
	cout << *sp2 << endl;	// 22
	Check(wp);				// still 22

	sp2.reset();				
	Check(wp);				// pointer is invalid
}

int main()
{
	//TestA();
	TestB();
	return 0;
}