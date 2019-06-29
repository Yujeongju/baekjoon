//2160 그림비교
#include <cstdio>
#include <algorithm>

#define INF 2<<18
using namespace std;

char data[60][10][10];
int return_diff(int n1, int n2)
{
	int cnt=0;

	for(int i=0; i<5; i++){
		for(int j=0; j<7; j++){
			if(data[n1][i][j] != data[n2][i][j])
				cnt++;
		}
	}

	return cnt;
}
int main(void)
{
	int t, diff, min_diff=INF, first, second;
	char input;
	scanf("%d", &t);

	for(int i=0; i<t; i++){
		for(int j=0; j<5; j++){
			getchar();
			scanf("%s", data[i][j]);
		}
	}

	for(int i=0; i<t; i++){
		for(int j=i+1; j<t; j++){
			diff = return_diff(i, j);
			if(min_diff > diff){
				min_diff = diff;
				first = i+1;
				second = j+1;
			}
		}
	}

	printf("%d %d\n", first, second);
}
