//11866 조세퍼스 문제0
#include <cstdio>
#include <queue>

using namespace std;
int main(void)
{
	queue<int> que;
	int input, crop, cnt=1;
	scanf("%d %d", &input, &crop);

	for(int i=1; i<=input; i++)
		que.push(i);

	printf("<");
	while(que.size() != 1){
		if(crop == cnt){
			printf("%d, ", que.front());
			que.pop();
			cnt=1;
		}
		else{
			que.push(que.front());
			que.pop();
			cnt++;
		}
	}
	printf("%d>\n", que.front());
	que.pop();

}
