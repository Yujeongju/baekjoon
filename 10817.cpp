//10817 세수

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[10];

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	sort(arr,arr+3);

	printf("%d", arr[1]);

	return 0;

}
