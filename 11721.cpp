//11721 열 개씩 끊어 출력하기

#include <cstdio>

int main(void)
{
	int cnt=0;
	char string[100];

	scanf("%s", string);

	printf("%c", string[cnt++]);
	while(1)
	{
		if(string[cnt]=='\0')
			break;
		else
		{
			if(cnt%10==0)
				printf("\n");
			printf("%c", string[cnt]);
		}
		cnt++;
	}

	return 0;
}
