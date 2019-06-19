//2751 수정렬하기2

#include <cstdio>
#include <algorithm>

using namespace std;
int main(void)
{
	int input;
	int arr[1000001];
	scanf("%d", &input);
	for(int i=0; i<input; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr+input);

	for(int i=0; i<input; i++)
		printf("%d\n", arr[i]);
}
