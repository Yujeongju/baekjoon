//5532 방학숙제
#include <cstdio>
#include <algorithm>

using namespace std;
int main(void)
{
	int L, A, B, C, D;
	int math=0, korean=0;
	int result;

	scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);
	if(A%C != 0)
		korean = A/C +1;
	else
		korean = A/C;

	if(B%D != 0)
		math = B/D + 1;
	else
		math = B/D;

	result = L - max(korean, math);

	printf("%d\n", result);
}
