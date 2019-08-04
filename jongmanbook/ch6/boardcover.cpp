#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//가장 왼쪽 위 블록 기준
int stype[4][3][2] = {
	{{0,0}, {1,0}, {0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

int C, h, w;
int arr[30][30];

int set(int x, int y, int type, int push)
{
	int nxtx, nxty;
	//블럭 채우기
	for(int i=0; i<3; i++){
		nxtx = x + stype[type][i][0];
		nxty = y + stype[type][i][1];
		arr[nxtx][nxty] += push;
	}

	for(int i=0; i<3; i++){
		nxtx = x + stype[type][i][0];
		nxty = y + stype[type][i][1];

		if(nxtx < 0 || nxty < 0 || nxtx >= h || nxty >= w)
			return 0;
		else if(arr[nxtx][nxty] > 1)
			return 0;
	}

	return 1;
}

int cover(void)
{
	int x=-1, y=-1;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(arr[i][j] == 0){
				x = i;
				y = j;
				break;
			}
		}

		if(x != -1)
			break;
	}

	if(x == -1)
		return 1;

	int result = 0;
	for(int type=0; type<4; type++){
		//덮을 수 있을 때
		if(set(x, y, type, 1)){
			result += cover();
		}
		//덮은걸 치운다
		set(x, y, type, -1);
	}
	
	return result;
}

int main(void)
{
	char c;
	scanf("%d", &C);
	while(C--){
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &h, &w);
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf(" %c", &c);
				if(c == '#')
					arr[i][j] = 1;
				else if(c == '.')
					arr[i][j] = 0;
			}
		}

		printf("%d\n", cover());
	}
}
