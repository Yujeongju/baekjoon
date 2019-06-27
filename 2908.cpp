//2908 상수
#include <cstdio>

int main(void)
{
	int num1=0, num2=0;
	int input1, input2;
	int cnt=100;

	scanf("%d %d", &input1, &input2);

	while(1){
		num1 += (input1%10 * cnt);
		input1 /= 10;
		if(input1 == 0)
			break;
		cnt /= 10;
	}

	cnt = 100;
	while(1){
		num2 += (input2%10 * cnt);
		input2 /= 10;
		if(input2 == 0)
			break;
		cnt /= 10;
	}

	if(num1 > num2)
		printf("%d\n", num1);
	else
		printf("%d\n", num2);

}
