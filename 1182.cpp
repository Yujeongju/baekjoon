//1182 부분수열의 합
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, S, cnt = 0;
int arr[30];
void sub(int i, int pre){
	if(i == N){
		if(pre == S){
			cnt++;
		}
		return;
	}

	//더했을 경우
	sub(i+1, pre+arr[i]);
	//더하지 않을 경우
	sub(i+1, pre);
}

int main(void)
{
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	sub(0, 0);
	if(S == 0)
		cnt--;

	printf("%d\n", cnt);
}
