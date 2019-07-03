//2011 암호코드
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MOD 1000000

using namespace std;

long long dp[5010];
int main(void)
{
	int length;
	char arr[5010];
	scanf("%s", arr);
	length = strlen(arr);

	if(arr[0] == '0'){ //0으로 시작하는 암호는 없음
		printf("0\n");
		return 0;
	}

	dp[1] = dp[0] = 1;

	int number;
	for(int i=2; i<=length; i++){
		//0 예외처리때문에 숫자로 바꿔야됨. => 101같은거
		number = (arr[i-2]-'0')*10 + (arr[i-1]-'0');
		
		//결합할 수 없으면 1개짜리 그대로
		if(arr[i-1] > '0'){
			//더하는이유는 앞에서 두번째를 위해 => 25114에서 25
			//i==2 일 때만 더하고 나머지는 dp[i-1]을 그대로 대입해도 정답
			dp[i] = (dp[i]+dp[i-1])%MOD;
		}

		//앞의 숫자와 합칠 수 있는 경우
		if(number >= 10 && number <=26){
			//1개짜리(결합X) + 2개짜리(결합O)
			dp[i] = (dp[i]+dp[i-2])%MOD;
		}
	}

	printf("%lld\n", dp[length]);

}
