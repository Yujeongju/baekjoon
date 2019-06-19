#include <cstdio>
#include <cstring>


int arr[100001];
int main(void)
{
	int time, num;

	scanf("%d", &time);

	for(int i=0; i<time; i++){
		scanf("%d", &num);

		for(int j=2; j<=num; j++){
			while(num%j == 0){
				arr[j]++;
				num /= j;
			}
		}

		for(int j=2; j<100001; j++){
			if(arr[j] > 0){
				printf("%d %d\n", j, arr[j]);
				arr[j] = 0;
			}
		}
	}
}
