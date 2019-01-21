#include <cstdio>

int main(void)
{
	char word[100];
	char alpha = 'a';
	int check=0;

	scanf("%s", word);

	while(alpha<='z')
	{
		check=0;
		for(int i=0; word[i]!='\0'; i++)
		{
			if(alpha==word[i])
			{	
				printf("%d ", i);
				check=1;
				break;
			}

		}

		if(check==0)
			printf("-1 ");
		alpha++;
	}

	return 0;
}
