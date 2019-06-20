//9020 골드바흐의 추측
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10100];

int main(void)
{
	int T, n;
	scanf("%d", &T);

	arr[1] = 1;
	for(int i=2; i<=10000; i++){
		for(int j=2; i*j<=10000; j++){
			arr[i*j] = 1;
		}
	}

	int cnt=0, temp, check=0;
	int num1, num2;
	for(int i=0; i<T; i++){
		scanf("%d", &n);
		temp = n/2;
		
		for(num1=num2=temp; num1>0; num1--, num2++){
			if(arr[num1]==0 && arr[num2]==0){
				printf("%d %d\n", num1, num2);
				break;
			}
		}


	}
}
