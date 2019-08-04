//1145 적어도 대부분 배수
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[5], result;
int main(void)
{
	for(int i=0; i<5; i++)
		scanf("%d", &arr[i]);

	int cnt = 0;
	while(1){
		cnt = 0;
		result++;
		for(int i=0; i<5; i++){
			if(result % arr[i] == 0)
				cnt++;
		}

		if(cnt >= 3)
			break;
	}

	printf("%d\n", result);
}
