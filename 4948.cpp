//4948 베르트랑 공준
#include <cstdio>

int arr[300000];
int main(void)
{
	int input, cnt=0;
	arr[1] = 1;
	for(int i=2; i<=123456*2; i++){
		for(int j=2; i*j<=123456*2; j++){
			if(arr[i*j] == 0)
				arr[i*j] = 1;
		}
	}

	while(1){
		cnt = 0;
		scanf("%d", &input);
		if(input == 0)
			break;

		for(int i=input+1; i<=input*2; i++){
			if(arr[i] == 0){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}
