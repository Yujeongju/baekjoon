//단어 공부
#include <cstdio>
#include <cstring>
#include <algorithm>

char input[1000010];
int arr[110];
int main(void)
{
	scanf("%s", input);

	for(int i=0; i<strlen(input); i++){
		if(input[i] >= 'A' && input[i] <= 'Z')
			arr[input[i]-'A']++;
		else if(input[i] >= 'a' && input[i] <= 'z')
			arr[input[i]-'a']++;
	}

	int max=0, index=0;

	for(int i=0; i<110; i++){
		if(arr[i] > max){
			max = arr[i];
			index = i;
		}
	}

	for(int i=0; i<110; i++){
		if(index == i)
			continue;
		else{
			if(max == arr[i]){
				printf("?\n");
				return 0;
			}
		}
	}

	printf("%c\n", index + 'A');

}
