//11021 A+B - 7
#include <cstdio>

int main(void)
{
	int t;
	int num1, num2;
	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%d %d", &num1, &num2);

		printf("Case #%d: %d\n", i+1, num1+num2);
	}
}
