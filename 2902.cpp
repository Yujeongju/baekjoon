#include <cstdio>

int main(void)
{
	char word[100];
	int i=0;

	scanf("%s", word);

	printf("%c", word[0]);
	while(word[i]!='\0')
	{
		
		if(word[i]=='-')
			printf("%c", word[i+1]);

		i++;
	}

	return 0;
}
