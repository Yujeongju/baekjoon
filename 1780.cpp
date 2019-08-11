//1780 종이의 개수
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[3000][3000];
int cnt1, cnt2, cnt3;
void count(int x, int y, int size)
{
	int val = arr[x][y];
	bool flag = 1;
	for(int i=x; i<x+size; i++)
		for(int j=y; j<y+size; j++)
			if(val != arr[i][j]){
				flag = 0;
				break;
			}

	if(flag){
		if(val == -1)
			cnt1++;
		else if(val == 0)
			cnt2++;
		else if(val == 1)
			cnt3++;
	}
	else{
		int new_s = size/3;
		count(x, y, new_s);
		count(x+new_s, y, new_s);
		count(x+new_s*2, y, new_s);
		
		count(x, y+new_s, new_s);
		count(x+new_s, y+new_s, new_s);
		count(x+new_s*2, y+new_s, new_s);

		count(x, y+new_s*2, new_s);
		count(x+new_s, y+new_s*2, new_s);
		count(x+new_s*2, y+new_s*2, new_s);
	}

	return;
}

int main(void)
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	count(0, 0, n);

	printf("%d\n%d\n%d\n", cnt1, cnt2, cnt3);

}
