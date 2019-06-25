//1330 두 수 비교하기
#include <cstdio>

int main(void)
{
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	if(num1 > num2)
		printf(">\n");
	else if(num1 < num2)
		printf("<\n");
	else
		printf("==\n");

}
