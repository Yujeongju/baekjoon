//3015 오아시스 재결합
#include <cstdio>
#include <stack>
#include <utility>

using namespace std;
int main(void)
{
	stack<pair<int, int> > st;
	pair<int, int> temp;
	int t, input;
	long long cnt=0;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &input);

		//stack을 내림차순으로 만들어야함.
		//stack이 비어있지않고 top이 input보다 작을 때
		while(st.size() > 0 && st.top().first < input){
			cnt+=st.top().second; //연속된 것은 연속된 만큼, 아니면 1 더해줌
			st.pop(); //pop
		}

		//비어있지 않을 떄
		if(st.size() > 0){
			//값이 같다면 second를 증가시킨다->3 3 3 3같은 case를 위함
			if(st.top().first == input){
				temp = st.top();
				st.pop();

				cnt += temp.second;
				if(st.size() > 0)
					cnt++;

				temp.second++;
				st.push(temp);
			}
			//같지 않다면 push하고 cnt++
			else{
				st.push(make_pair(input, 1));
				cnt++;
			}
		}
		//스택이 비어있다면 그냥 push
		else{
			st.push(make_pair(input, 1));
		}
	}

	printf("%lld\n", cnt);
}
