//9020 골드바흐의 추측
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct data{
	int num1;
	int num2;
	int diff;
}data;

int arr[10100];
data result[10100];

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
		for(int j=0; j<=10000; j++)
			result[j].diff = 9999;

		scanf("%d", &n);
		temp = n;

		for(int j=2; j<=n; j++){
			if(arr[j] == 0){
				temp -= j;
				for(int k=2; k<=n; k++){
					if(arr[k] == 0){
						if(temp-k == 0){
							result[cnt].num1 = min(j, k);
							result[cnt].num2 = max(j, k);
							result[cnt++].diff = max(j, k) - min(j, k);
							check = 1;
						}
					}
				}
			}
			temp = n;
		}

		temp = 9999;
		if(check){
			for(int j=0; j<cnt; j++){
				if(temp > result[j].diff){
					temp = result[j].diff;
					num1 = result[j].num1;
					num2 = result[j].num2;
				}
			}
			printf("%d %d\n", num1, num2);
			check = 0;
			temp = 0;
		}

	}
}
