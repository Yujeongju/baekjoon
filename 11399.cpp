//11399 ATM : 그리디 알고리즘

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, time=0;
	int arr[1000];
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr+N);

	for(int i=0; i<N; i++)
		time += (N-i) * arr[i];
	
	printf("%d", time);
	
}
