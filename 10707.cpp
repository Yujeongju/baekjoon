//10707 수도요금
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int x_m, y_m, y_cut, y_plus;
	int used;
	int x_result=0, y_result=0;

	scanf("%d", &x_m);
	scanf("%d %d %d", &y_m, &y_cut, &y_plus);
	scanf("%d", &used);

	x_result = used * x_m;
	y_result = y_m;
	if(used > y_cut){
		y_result += (y_plus * (used - y_cut));
	}

	printf("%d\n", min(x_result, y_result));

}

