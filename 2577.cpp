//2577 숫자의 개수
#include <cstdio>

int main(void)
{
	int num1, num2, num3, mult;
	int arr[10]={0};
	scanf("%d %d %d", &num1, &num2, &num3);

	mult = num1 * num2 * num3;

	while(1){
		arr[mult%10]++;
		if(mult / 10 == 0)
			break;
		else
			mult /= 10;
	}

	for(int i=0; i<10; i++)
		printf("%d\n", arr[i]);

}
