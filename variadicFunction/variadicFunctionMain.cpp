#include <iostream>
#include <stdarg.h>
using namespace std;


double SumOfFlaot(int count, ...)
{
	va_list ap;
	double sum(0);
	// ��ñ䳤�б�ľ��ap
	va_start(ap, count);	

	for (int i = 0; i < count; ++i)
	{
		// ÿ�λ��һ������
		sum += va_arg(ap, double);
	}

	va_end(ap);

	return sum;
}

int main()
{
	printf("%f\n", SumOfFlaot(3, 1.2, 2.3, 4.5));
}