//2292 벌집
#include <cstdio>

int main(void)
{
	long long input, house=1, cnt=1;
	long long tmp=1;

	scanf("%lld", &input);

	while(1){
		if(input <= house){
			break;
		}

		cnt++;
		house += 6*(cnt-1);
	}

	printf("%lld\n", cnt);
}
