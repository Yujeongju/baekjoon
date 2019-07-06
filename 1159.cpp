//1159 농구경기
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char name[160][31];
char result[160];
int main(void)
{
	int num;
	int cnt=0, rcnt=0;
	scanf("%d", &num);

	for(int i=0; i<num; i++)
		scanf("%s", name[i]);

	for(int i='a'; i<='z'; i++){
		for(int j=0; j<num; j++){
			if(i == name[j][0])
				cnt++;
		}

		if(cnt >= 5)
			result[rcnt++] = i;

		cnt = 0;
	}
	sort(result, result+rcnt);

	result[rcnt] = 0;

	if(rcnt == 0)
		printf("PREDAJA\n");
	else
		printf("%s\n", result);


}
