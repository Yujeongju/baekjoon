//11365 !밀비 급일

#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
	char input[510][510];
	int i=0;

	while(1)
	{
		scanf("%[^\n]s", input[i]);
		getchar();

		if(input[i][0]=='E' && input[i][1]=='N' && input[i][2]=='D')
			break;
		
		i++;
	}

	for(int j=0; j<i; j++)
	{
		for(int k=strlen(input[j])-1; k>=0; k--) // -1이 포인트
		{
			printf("%c", input[j][k]);
		}
		printf("\n");
	}


	return 0;
}
