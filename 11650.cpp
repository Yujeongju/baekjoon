#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main(void)
{
	pair<int, int>  arr[100000];
	int num;

	scanf("%d", &num);

	for(int i=0; i<num; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	
	sort(arr, arr+num);

	for(int i=0; i<num; i++)
	{
		printf("%d %d\n", arr[i].first, arr[i].second);
	}


	return 0;

}
