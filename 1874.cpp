#include <cstdio>
#include <cstdlib>

#define MAX_TOP 100100

int stack[MAX_TOP];
int result[200100] = {0};
int cur=1;

void push(int num)
{
	stack[cur] = num;
	cur++;
}

void pop(void)
{
	cur--;
}

int main(void)
{
	int num=0, input, pre=0;
	int i=1, k=0;

	scanf("%d", &num);

	while(num--){
		scanf("%d", &input);
		if(input > pre){
			while(1){
				if(input != i-1){
					result[k++] = '+';
					push(i);
					i++;
				}
				else{
					result[k++] = '-';
					pre = input;
					pop();
					break;
				}
			}
		}
		else{
			pop();
			pre = input;
			if(stack[cur] == input)
				result[k++] = '-';
			else{
				printf("NO\n");
				return 0;
			}
		}
	}

	for(int i=0; i<k; i++){
		printf("%c\n", result[i]);
	}

	return 0;

}
