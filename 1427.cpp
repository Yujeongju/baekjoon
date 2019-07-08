//1427 소트인사이드
#include <cstdio>
#include <algorithm>

using namespace std;

long long num;
int arr[30];

bool comp(int a, int b){
	return a>b;
}
int main(void)
{
	int cnt=0;
	scanf("%lld", &num);

	while(1){
		if(num == 0)
			break;
		arr[cnt++] = num%10;
		num /= 10;
	}

	sort(arr, arr+cnt, comp);

	for(int i=0; i<cnt; i++)
		printf("%d", arr[i]);
	printf("\n");

}
