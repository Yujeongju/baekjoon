//8958 OX퀴즈
#include <cstdio>
#include <cstring>

int main(void)
{
	char input[100];
	int t, cnt=0, result = 0;

	scanf("%d", &t);

	for(int i=0; i<t; i++){
		result = cnt =0;
		scanf("%s", input);
		for(int j=0; j<strlen(input); j++){
			if(input[j] == 'O')
				cnt++;
			else
				cnt = 0;
			result += cnt;
		}
		printf("%d\n", result);
	}
}

