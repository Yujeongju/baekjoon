//2750 수 정렬하기 수학

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int input;
	int *arr;

	scanf("%d", &input);

	arr = new int[input];

	for(int i=0; i<input; i++)
		scanf("%d", &arr[i]);

	sort(arr,arr+input);

	for(int i=0; i<input; i++)
		printf("%d\n", arr[i]);

	return 0;
	

}
