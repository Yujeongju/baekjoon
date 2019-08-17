//2529 부등호
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long result1=-1, result2=99999999999;
int visit[30], k;
char input[30], tmp[30], res1[30], res2[30];

long long convert(char *tmp)
{
	long long num=0, mul=1;
	for(int i=k+1; i>=0; i--, mul*=10){
		num += ((tmp[i]-'0') * mul);
	}

	return num;
}

void dfs(int num, int cnt)
{
	if(cnt == k+1){
		long long chnum = convert(tmp);
		if(result1 < chnum){
			result1 = chnum;
			strcpy(res1, tmp);
		}
		
		if(result2 > chnum){
			result2 = chnum;
			strcpy(res2, tmp);
		}
		
		return;
	}

	if(visit[num] != 0)
		return;

	tmp[cnt] = num+'0';

	if(input[cnt] == '<'){
		for(int i=0; i<10; i++){
			if(num < i){
				visit[num] = 1;
				dfs(i, cnt+1);
				visit[num] = 0;
			}
		}
	}
	else if(input[cnt] == '>'){
		for(int i=0; i<10; i++){
			if(num > i){
				visit[num] = 1;
				dfs(i, cnt+1);
				visit[num] = 0;
			}
		}
	}
	//k==9이면 input[9]가 null이기 때문에 예외처리 해줌(반례 : 9 > > > > > > > >)
	else{
		dfs(0, cnt+1);
	}
	
}

int main(void)
{
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf(" %c", &input[i]);
	}
	input[k] = 0;

	for(int i=0; i<10; i++){
		int cnt = 0;
		dfs(i, cnt);
	}

	printf("%s\n%s\n", res1, res2);
}
