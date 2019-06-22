//2869 달팽이는 올라가고 싶다
#include <cstdio>
#include <algorithm>

#define MAX 1000000000+1

using namespace std;

int main(void)
{
	long long het, up, down;
	long long day, result = MAX;
	long long left=0 , right=0;

	scanf("%lld %lld %lld", &up, &down, &het);
	left = 0;
	right = het/(up-down)+1;

	while(left <= right){
		day = (left+right)/2;
		
		if(het <= day*(up-down) + up){
			result = min(result, day+1);
			right = day-1;
		}
		else{
			left = day+1;
		}
	}

	printf("%lld\n", result);


}
