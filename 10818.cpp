//10818 최소, 최대
#include <cstdio>
#include <algorithm>

#define INF 2<<28
using namespace std;

int arr[1000100];
int main(void)
{
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr+N);

	printf("%d %d\n", arr[0], arr[N-1]);


}

