#include <iostream>
#include <typeinfo>

using namespace std;

/*
	simple usage
*/
void TestA()
{
	int i;
	decltype(i) j = 0;
	cout << typeid(j).name() << endl;	// int

	float a;
	double b;
	decltype(a + b) c;
	cout << typeid(c).name() << endl;	// double
}

/*
	decltype with templete
*/
template <typename T1, typename T2>
void Sum(T1 & t1, T2 & t2, decltype(t1 + t2) & s)
{
	s = t1 + t2;
}
void TestB()
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;

	long e;
	float f;
	Sum(a, b, e);
	Sum(c, d, f);

	cout << e << endl;	// long: 8
	cout << f << endl;	// float: 3.3f 

}

/*
	same example may cause confused
	about decltype(e) 4 rules can make result
	1 ���e��һ��û�д����ŵı�Ƿ����ʽ�������Ա���ʱ��ʽ����ô
	  decltype(e)����e��������ʵ������͡����⣬���e��һ�������صĺ�����
	  ��ᵼ�±������
	2 ���򣬼���e��������T,���e��һ������ֵ����ôdecltype(e)ΪT&&
	3 ���򣬼���e��������T,���e��һ����ֵ����decltype(e)ΪT&
	4 ���򣬼���e��������T,��decltype��e)ΪT
*/
void TestC()
{
	int i = 4;
	int arr[5] = { 0 };
	int *ptr = arr;

	struct S { double d; }s;

	void Overloaded(int);
	void Overloaded(char);

	int && RvalRef();

	const bool Func(int);

	// Rule 1
	decltype(arr) var1;						// int[5]
	decltype(ptr) var2;						// int*
	decltype(s.d) var4;						// double
	//decltype(Overloaded);					// error!!

	// Rule 2
	decltype(RvalRef()) var6 = 1;			// int&&

	// Rule 3
	decltype(true ? i : i) var7 = i;		// int&
	decltype((i)) var8 = i;					// int&
	decltype(++i) var9 = i;					// int&
	decltype(arr[3]) var10 = i;				// int&
	decltype(*ptr) var11 = i;				// int&
	decltype("lval") var12 = "lval";		// conat char(&) [5]
	
	// Rule 4
	decltype(1) var13;						// int
	decltype(i++) var14;					// int
	decltype((Func(1))) var15;				// const bool
}
int main()
{
	//TestB();
	TestC();
	return 0;
}