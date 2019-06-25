//2884 알람 시계
#include <cstdio>

int main(void)
{
	int hour, mte;

	scanf("%d %d", &hour, &mte);

	if(mte - 45 < 0){
		hour -= 1;
		if(hour < 0)
			hour = 23;
		mte += 60;
	}

	printf("%d %d\n", hour, mte-45);
}
