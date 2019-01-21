#include <cstdio>

int main(void)
{
	int T;
	int R,r;
	char S[100];

	scanf("%d", &T);
	while(T--)
	{
		int i=0;
		scanf("%d", &R);
		scanf("%s", S);

		while(1)
		{
			if(S[i]=='\0')
				break;

			for(int j=0; j<R; j++)
				printf("%c", S[i]);
			i++;
		}

		printf("\n");
	}

	return 0;
}
