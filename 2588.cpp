//2588 곱셈
#include <cstdio>

int main(void)
{
	int num1, num2, temp;

	scanf("%d %d", &num1, &num2);

	temp = num2;
	while(1){
		printf("%d\n", num1*(num2%10));
		num2 /= 10;

		if(!num2)
			break;
	}

	printf("%d\n", num1 * temp);
}
