//1016 제곱ㄴㄴ수
#include <cstdio>
#include <iostream>
#include <math.h>

long long result[1000010];
long long num[1000010];

int main(void)
{
	int cnt=0, r_cnt=0;
	long long min, max, div;
	long long i, j;

	scanf("%lld %lld", &min, &max);

	//제곱수 저장
	for(i=2; i*i <= max; i++){
		num[i] = i*i;
		cnt++;
	}

	for(i=2; i<cnt+2; i++){
		div = min;
		if(div % num[i] != 0){
			//그냥 num[i]를 넣으면 범위에 맞지 않기 때문에 안 됨.
			//범위에 맞는 값을 넣어주는 것임
			div = (min/num[i]+1)*num[i];
		}

		for(j=div; j<=max; j += num[i]){
			if(!result[j-min]){
				//제곱 ㅇㅇ수를 센다.
				result[j-min] = 1;
				r_cnt++;
			}
		}
	}

	printf("%lld\n", max-min-r_cnt+1);

	exit(0);
}
