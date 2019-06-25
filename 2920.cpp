//2920 음계
#include <cstdio>

int main(void)
{
	int arr[10], flag=0;
	for(int i=1; i<=8; i++)
		scanf("%d", &arr[i]);

	flag = 1;
	for(int i=1; i<=8; i++){
		if(arr[i] != i){
			flag = 0;
			break;
		}
	}

	if(flag){
		printf("ascending\n");
		return 0;
	}

	flag = 1;
	for(int i=1; i<=8; i++){
		if(arr[i] != 8-i+1){
			flag = 0;
			break;
		}
	}

	if(flag){
		printf("descending\n");
		return 0;
	}

	printf("mixed\n");
}
