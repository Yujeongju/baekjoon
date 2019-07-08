//1026 보물
#include <cstdio>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
	return a>b;
}
int main(void)
{
	int num1[60], num2[60];
	int N, result=0;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &num1[i]);

	for(int i=0; i<N; i++)
		scanf("%d", &num2[i]);

	sort(num1, num1+N);

	sort(num2, num2+N, comp);

	for(int i=0; i<N; i++)
		result += (num1[i]*num2[i]);

	printf("%d\n", result);

}
