//1158 조세퍼스 문제 더블링크드리스트
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node{
	int value;
	Node* back;
	Node* next;
}Node;

int main(void)
{
	Node** brid;
	Node* cur = (Node*)malloc(sizeof(Node));
	int *result;
	int num, k=0, cnt;
	int cutting;

	scanf("%d %d", &num, &cutting);
	cnt = num;

	brid = (Node**)malloc(sizeof(Node*) * num);
	result = (int*)malloc(sizeof(int) * num);

	for(int i=1; i<=num; i++){
		brid[i] = (Node*)malloc(sizeof(Node));
	}

	brid[1]->value = 1;
	brid[1]->next = brid[2];
	brid[1]->back = brid[num];

	for(int i=2; i<=num-1; i++){
		brid[i]->value = i;
		brid[i]->next = brid[i+1];
		brid[i]->back = brid[i-1];
	}

	brid[num]->value = num;
	brid[num]->next = brid[1];
	brid[num]->back = brid[num-1];

	int i=1;
	cur = brid[1];

	while(cnt>0){
		if(cnt==1){
			result[k++] = cur->value;
			free(cur);
			cnt--;
			break;
		}

		if(i%cutting == 0){
			result[k++] = cur->value;
			cur->back->next = cur->next;
			cur->next->back = cur->back;
			free(cur);
			cnt--;
			i=0;
		}

		i++;
		cur = cur->next;
	}

	for(int i=0; i<num; i++){
		if(i==0)
			printf("<%d", result[i]);
		else if(i==num-1)
			printf(", %d", result[i]);
		else
			printf(", %d", result[i]);
	}
	printf(">\n");

	return 0;

}
