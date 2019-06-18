#include <cstdio>
#include <math.h>

int main(void)
{
	int input, cnt=0, flag=1;
	int arr[110];

	scanf("%d", &input);
	for(int i=0; i<input; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i<input; i++){
		flag = 1;
		if(arr[i] == 1)
			continue;

		if(arr[i] == 2){
			cnt++;
			continue;
		}

		for(int j=2; j<arr[i]; j++){
			if(arr[i] % j == 0)
				flag=0;
		}

		if(flag){
			cnt++;
		}
	}

	printf("%d\n", cnt);

}
