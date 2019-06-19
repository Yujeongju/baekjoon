//1475 방번호
//0도 처리해줘야함.
#include <cstdio>

int main(void)
{
	int num, check;
	int arr[11]={0};
	scanf("%d", &num);

	if(num == 0){
		printf("1\n");
		return 0;
	}

	while(num){
		check = num%10;
		if(check != 6 && check != 9)
			arr[check]++;
		else{
			if(arr[6] == arr[9])
				arr[check]++;
			else if(arr[6] > arr[9])
				arr[9]++;
			else if(arr[9] > arr[6])
				arr[6]++;
		}
		num /= 10;
	}

	num = 0;
	for(int i=0; i<10; i++){
		if(num < arr[i])
			num = arr[i];
	}

	printf("%d\n", num);

}
