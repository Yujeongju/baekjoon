//1110 더하기 사이클 수학

#include <cstdio>

int main(void)
{
	int origin=0;
	int input, cnt=0;;
	int tmp, tmp2;

	scanf("%d", &input);
	origin = input;

	while(1){
		cnt++;
		if(input < 10)
			tmp = input;
		else{
			tmp = input/10;
			input%=10;
			tmp += input;
		}

		tmp2 = tmp%10;
		input = input*10 + tmp2;
		if(origin==input){
			printf("%d\n", cnt);
			break;
		}
	}

	return 0;
}
