#include <tuple>
#include <iostream>
#include <string>
#include <functional>
#include <utility>

using namespace std;

void getTest()
{
	tuple<int, char, string> tupleA( 10, 'a', "abc" );
	auto a = get<0>(tupleA);
	auto b = get<1>(tupleA);
	auto c = get<2>(tupleA);

	cout << a << endl;	// 10
	cout << b << endl;  // a
	cout << c << endl;  // abc
}

void make_tupleTest()
{
	int n = 1;
	auto tupleA = make_tuple(std::ref(n),n);	// tupleA = [ 1,1 ]
	cout << get<0>(tupleA) << endl;		// 1
	cout << get<1>(tupleA) << endl;		// 1

	n = 10;								// tupleA = [10,1]
	cout << get<0>(tupleA) << endl;		// 10
	cout << get<1>(tupleA) << endl;		// 1
}

void tieTest()
{
	int myInt;
	char myChar;
	double myDouble;
	tuple<int, char, double> tupleA( 10, 'a', 3.14 );	// tupleA = [10,'a',3.14]
	// unpacking tuple into variables
	tie(myInt, myChar, myDouble) = tupleA;
	cout << myInt << endl;		// 10
	cout << myChar << endl;		// a
	cout << myDouble << endl;	// 3.14


	float myFloat;
	short myShort;
	tuple<string, float, short> tupleB( "xyz", 2.71, 2 );	// tupleB = ["xyz",2.71,x]
	//unpacking tuple with std::ignore
	tie(std::ignore, myFloat, myShort) = tupleB;
	cout << myFloat << endl;	// 2.71
	cout << myShort << endl;	// 2
}

void tuple_catTest()
{
	tuple<string, double> tupleA( "pi", 3.14 );
	tuple<int, char> tupleB( 10, 'a' );
	pair<double, int> pairA( 1.11, 100 );

	auto a = tuple_cat(tupleA, tupleB, pairA);

	cout << get<0>(a) << endl;
	cout << get<1>(a) << endl;
	cout << get<2>(a) << endl;
	cout << get<3>(a) << endl;
	cout << get<4>(a) << endl;
	cout << get<5>(a) << endl;

}
int main()
{
	//getTest();
	//make_tupleTest();
	//tieTest();
	tuple_catTest();
}