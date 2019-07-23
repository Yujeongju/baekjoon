//2455 지능형기차
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int out, in, result=0, tmp=0;
	
	for(int i=0; i<4; i++){
		scanf("%d %d", &out, &in);
		tmp = (tmp + in - out);
		result = max(tmp, result);
	}

	printf("%d\n", result);
}
