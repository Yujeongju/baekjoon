#include <cstdio>
#include <algorithm>

using namespace std;

int lcn(int x, int y)
{
	int tmp;
	int a=x, b=y;
	while(b){
		tmp = a;
		a = b;
		b = tmp%b;
	}

	return (x*y)/a;
}

int main(void)
{
	int num, M, N, x, y;
	int lcn_num=0;
	int tmpy, yy;
	int flag=0;

	scanf("%d", &num);

	while(num--){
		scanf("%d %d", &M, &N);
		scanf("%d %d", &x, &y);
		
		lcn_num = lcn(x,y);
		tmpy = x;

		flag = 0;
		for(int i=0; i<N; i++){
			if(tmpy%N == 0)
				yy = N;
			else
				yy = tmpy%N;

			if(yy==y){
				flag=1;
				printf("%d\n", x);
				break;
			}
			else{
				tmpy = tmpy%N+M;
				x+=M;
			}
			
		}

		if(!flag)
			printf("-1\n");

	}

	return 0;
}
