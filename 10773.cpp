//10773 제로
#include <cstdio>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> st;
	int input, num;

	scanf("%d", &input);
	for(int i=0; i<input; i++){
		scanf("%d", &num);
		if(num != 0)
			st.push(num);
		else
			st.pop();
	}

	num = 0;
	while(!st.empty()){
		num += st.top();
		st.pop();
	}

	printf("%d\n", num);

}
