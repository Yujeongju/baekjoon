//2914 저작권
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int A, I;
	int mel;
	scanf("%d %d", &A, &I);

	mel = A*I;
	mel -= (A-1);

	printf("%d\n", mel);

}
