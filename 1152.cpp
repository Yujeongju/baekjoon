//1152 단어의 개수
#include <cstdio>
#include <cstring>

char input[1000010];
int main(void)
{
	int cnt=0;

	scanf("%[^\n]s", input);
	input[strlen(input)] = 0;

	if(input[0] != ' ')
		cnt++;

	for(int i=0; i<strlen(input); i++){
		if(input[i] == ' '){
			while(1){
				i++;
				if(input[i] != ' '){
					if(input[i] != 0)
						cnt++;
					break;
				}
			}
		}
	}

	printf("%d\n", cnt);

}
