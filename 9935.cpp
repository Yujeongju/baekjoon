//9935 문자열 폭발
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char input[1000100], pong[50];
char result[1000100];
int main(void)
{
	int index=0, il, pl, check=0;
	scanf("%s", input);
	scanf("%s", pong);
	il = strlen(input);
	pl = strlen(pong);

	for(int i=0; i<il; i++){
		result[index++] = input[i];
		if(result[index-1] == pong[pl-1]){
			if(index - pl < 0)
				continue;

			check = 1;
			for(int j=0; j<pl; j++){
				if(result[index-j-1] != pong[pl-j-1]){
					check = 0;
					break;
				}
			}

			if(check)
				index -= pl;
		}
	}

	if(index == 0){
		printf("FRULA\n");
		return 0;
	}

	result[index] = 0;
	printf("%s\n", result);

}
