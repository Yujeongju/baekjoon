//2753 윤년
#include <cstdio>

int main(void)
{
	int input;

	scanf("%d", &input);

	if(input % 4 == 0 && (input%100 != 0 || input%400 == 0)){
		printf("1\n");
	}
	else
		printf("0\n");
}
