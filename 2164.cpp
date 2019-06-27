//2164 카드2
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;
int main(void)
{
	deque<int> dq;
	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
		dq.push_front(i);

	while(dq.size() != 1){
		dq.pop_back();
		dq.push_front(dq.back());
		dq.pop_back();
	}

	printf("%d\n", dq.front());
}
