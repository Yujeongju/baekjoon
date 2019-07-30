//5585 거스름돈
#include <cstdio>
#include <algorithm>

using namespace std;

int coin[6] = {500, 100, 50, 10, 5, 1};
int m, result;
int main(void)
{
	scanf("%d", &m);
	m = 1000 - m;

	for(int i=0; i<6; i++){
		if(m >= coin[i]){
			m -= coin[i];
			result++;
			i--;
		}
	}

	printf("%d\n", result);
}
