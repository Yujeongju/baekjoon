//15596 정수 N개의 합
#include <cstdio>

using namespace std;

long long sum(int *a, int n){
	int result=0;
	for(int i=0; i<n; i++)
		result += a[i];

	return result;
}

int main(void)
{
	int a[1000100];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	long long result = sum(a, n);

	printf("%lld\n", result);
}
