//2504 괄호의값 스택

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

stack<char> s;

int main(void)
{
	int result=0;
	int tmp=1;
	int cnt2=0, cnt3=0;
	char input[31];

	scanf("%s", input);
	strtok(input, "\n");
/*
	for(int i=0; i<strlen(input); i++){
		switch(input[i]){
			case ')': cnt2++; break;
			case '(': cnt2--; break;
			case '[': cnt3++; break;
			case ']': cnt3--; break;
		}

		if(cnt2 < 0 || cnt3 < 0){
			printf("0\n");
			return 0;
		}
	}

	if(cnt2!=0 || cnt3!=0){
		printf("0\n");
		return 0;
	}
*/
	for(int i=0; i<strlen(input); i++){
		if(input[i] == '('){
			tmp*=2;
			s.push(input[i]);
		}
		else if(input[i] == '['){
			tmp*=3;
			s.push(input[i]);
		}
		else if(input[i]==')' && (s.empty() || s.top()!='(')){
			printf("0\n");
			return 0;
		}
		else if(input[i]==']' && (s.empty() || s.top()!='[')){
			printf("0\n");
			return 0;
		}
		else if(input[i] == ')'){
			if(input[i-1] == '(')
				result += tmp;
			s.pop();
			tmp/=2;
		}
		else if(input[i] == ']'){
			if(input[i-1] == '[')
				result += tmp;
			s.pop();
			tmp/=3;
		}
	}


	if(!s.empty())
		printf("0\n");
	else
		printf("%d\n", result);

}
