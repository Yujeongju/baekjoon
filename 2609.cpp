//2609 최대공약수와 최소공배수
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int LCM, GCD; //LCM : 최소공배수, GCD : 최대공약수
	int num1, num2, a, b, temp;
	scanf("%d %d", &num1, &num2);

	a = max(num1, num2);
	b = min(num1, num2);

	//유클리드 호제법
	while(1){
		temp = a % b;
		a = b;
		b = temp;
		if(b == 0){
			break;
		}
	}

	GCD = a;
	LCM = num1 * num2 / GCD;

	printf("%d %d\n", GCD, LCM);

}
