//2161 카드1
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> first, result;
int main(void)
{
	int t, ck=0;
	scanf("%d", &t);
	for(int i=1; i<=t; i++)
		first.push(i);

	while(first.size() != 1){
		result.push(first.front());
		first.pop();

		t = first.front();
		first.pop();
		first.push(t);
		ck++;
	}

	while(!result.empty()){
		printf("%d ", result.front());
		result.pop();
	}

	printf("%d\n", first.front());

}
