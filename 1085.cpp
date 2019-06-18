//1085 직사각형에서 탈출
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int x, y, w, h;
	int num1=0, num2=0, result=0;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	num1 = min(w-x, h-y);
	num2 = min(x-0, y-0);

	result = min(num1, num2);

	printf("%d\n", result);
}
