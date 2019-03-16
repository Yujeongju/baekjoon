#include <cstdio>
#include <cstring>

int check(char *);

int main(void)
{
	int time, cek;
	char arr[51];

	scanf("%d", &time);

	for(int i=0; i<time; i++)
	{
		scanf("%s", arr);
		cek=check(arr);
		if(cek==1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;

}

int check(char *arr)
{
	int num1=0;
	int i=0;
	int time=strlen(arr);

	while(i<time)
	{
		if(arr[i]=='(')
			num1++;
		else if(arr[i]==')')
        {	
            num1--;
            if(num1<0)
                return 0;
        }
        else
            return 0;

		i++;
	}

	if(num1==0)
		return 1;
	else
		return 0;
}

