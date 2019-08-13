//2217 로프
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int rope[100100], result;
bool comp(int a, int b){
	return a>b;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &rope[i]);
	sort(rope, rope+n, comp);
	for(int i=0; i<n; i++)
		result = max(result, rope[i]*(i+1));
	printf("%d\n", result);
}
