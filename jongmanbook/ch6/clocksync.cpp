#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 2<<28
using namespace std;

int button[10][16]={
	{ 0, 1, 2, -1 }, { 3, 7, 9, 11, -1 },
	{ 4, 10, 14, 15, -1 }, { 0, 4, 5, 6, 7, -1 },
	{ 6, 7, 8, 10, 12, -1 }, { 0, 2, 14, 15, -1 },
	{ 3, 14, 15, -1 }, { 4, 5, 7, 14, 15, -1 },
	{ 1, 2, 3, 4, 5, -1 }, { 3, 4, 5, 9, 13, -1 }
};
int clocks[20], result;
int check(){
	for(int i=0; i<16; i++)
		if(clocks[i] != 12)
			return 0;
	return 1;
}

void push(int btn)
{
	for(int i=0; i<16; i++){
		if(button[btn][i] == -1)
			break;
		if(clocks[button[btn][i]] >= 12)
			clocks[button[btn][i]] = 0;
		clocks[button[btn][i]] += 3;
	}
}

int solve(int btn)
{
	if(btn == 10){
		if(check() == 1)
			return 0;
		else
			return INF;
	}

	int ret = INF;
	for(int i=0; i<4; i++){
		ret = min(ret, i + solve(btn+1));
		push(btn);
	}

	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--){
		result = INF;
		for(int i=0; i<16; i++)
			scanf("%d", &clocks[i]);

		result = solve(0);
		if(result == INF)
			result = -1;

		printf("%d\n", result);
	}
}
