//2490 윷놀이
#include <cstdio>

int main(void)
{
	int input[4], cnt=0, t=3;
	while(t--){
		cnt = 0;
		scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);

		for(int i=0; i<4; i++)
			if(input[i] == 1)
				cnt++;

		switch(cnt){
			case 1: printf("C\n"); break;
			case 2: printf("B\n"); break;
			case 3: printf("A\n"); break;
			case 4: printf("E\n"); break;
			case 0: printf("D\n"); break;
		}
	}
}
