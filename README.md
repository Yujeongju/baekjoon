# baekjoon
제 나름대로 백준 문제를 해결한 코드입니다.

## 마크다운사용법
https://gist.github.com/ihoneymon/652be052a0727ad59601


<hr>
</hr>

## Guide Code  
### BFS  
<pre><code>
void bfs(int v){
	queue<int> q;
	q.push(v);
	visit[v] = 1;
	while(!q.empty()){
		v = q.front();
		printf("%d ", q.front());
		q.pop();
		for(int i=1; i<=n; i++){
			if(visit[i] == 1 || mat[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 1;
		}
	}
}
</pre></code>

### DFS  
<pre><code>
void dfs(int v){  
  printf("%d ", v);    
	visit[v] = 1;  
	for(int i=1; i<=n; i++){  
		if(visit[i] == 1 || mat[v][i] == 0)  
			continue;  
		dfs(i);  
	}  
}  
</pre></code>

### Dijkstra  
<pre><code>
void dijkstra(int s){
	for(int i=0; i<=N; i++)
		dist[i] = INF;
	dist[s] = 0;
	priority_queue< pair < int, int > > pq;
	pq.push(make_pair(0, s));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost)
			continue;

		for(int i=0; i < graph[here].size(); i++){
			int current_node = graph[here][i].first;
			int next_dist = cost + graph[here][i].second;

			if(dist[current_node] > next_dist){
				dist[current_node] = next_dist;
				pq.push(make_pair(-next_dist, current_node));
			}
		}
	}
}
</pre></code>

### LIS
###### N^2
<pre><code>
for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+1){ 
				dp[i] = dp[j]+1;  
				result = max(dp[i], result);  
			}
		}
	}

</pre></code>

###### N log N
이진탐색을 약간 변형한 알고리즘인 Lower bound(https://yhwan.tistory.com/18)  
*주의 : 결과만 알 수 있다! 요소까지 알 수는 없음.
<pre><code>
int arr[100100];
int lower_bound(vector<int> vt, int num){
	int low = 0, high = vt.size()-1;

	//이분탐색 -> num이 들어갈 위치를 찾는다.
	while(low < high){
		int mid = (low + high) / 2;
		if(vt[mid] >= num)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int main(void)
{
	int n, cnt=1, num;
	vector<int> vt;

	scanf("%d", &n);
	for(int i=0; i < n; i++)
		scanf("%d", &arr[i]);

	vt.push_back(arr[0]);
	for(int i=1; i < n; i++){
		//앞의 값보다 크면 push
		if(arr[i] > vt[vt.size()-1])
			vt.push_back(arr[i]);
		//아니라면 lower_bound를 이용해 알맞은 위치에 push
		else{
			vt[lower_bound(vt, arr[i])] = arr[i];
			//stl 이용한 코드
			//num = lower_bound(vt.begin(), vt.end(), arr[i]) - vt.begin();
			//vt[num] = arr[i];
		}
	}

	//자른 수를 구하는 것이므로 n-vt.size()
	printf("%lu\n", n-vt.size());
}
</pre></code>

### LCS
<pre><code>
for(int i=1; i<=str1_len; i++){
	for(int j=1; j<=str2_len; j++){
		if(str1[i-1] == str2[j-1]){
			dp[i][j] = dp[i-1][j-1] + 1;
		}
		else
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	}
}
printf("%d\n", dp[str1_len][str2_len]);

</pre></code>

### Floyd  
<pre><code>
void floyd(void){
	//from -> to 보다 from -> i -> to가 더 짧을 경우를 찾음
	for(int i=1; i<=N; i++){
		for(int from=1; from<=N; from++){
			//from->i 가 불가능할 경우 continue
			if(graph[from][i] == 0)
				continue;
			//갈 수 있는 정점 모두 탐색
			for(int to=1; to<=N; to++){
				//i와 to가 미연결이거나 from == to라면 continue
				if(graph[i][to] == 0 || from == to)
					continue;

				//한 번도 가지 않은 간선이거나
				//i를 통해 from->i->to가 더 짧을 경우 갱신
				if(graph[from][to] == 0 || graph[from][to] > graph[from][i] + graph[i][to])
					graph[from][to] = graph[from][i] + graph[i][to];
			}
		}
	}
}
</pre></code>
### 에라토스테네스의 체
<pre><code>
result[1] = 1;
	for(int i=2; i<=max; i++){
		for(int j=2; i*j <=max; j++){
			result[i*j] = 1;
		}
	}

	for(int i=min; i<=max; i++)
		if(!result[i])
			printf("%d\n", i);
</pre></code>

### 연쇄행렬곱셈(DP)
<pre><code>
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &cost);
		//발생하는 합을 구하기 위해 1~n까지 모두 더함.
		sum[i] += sum[i-1]+cost;
	}

	//연쇄행렬곱셈 응용
	for(int len = 1; len < n; len++){
		for(int i = 1; i <= n - len; i++){
			int j = i+len;
			dp[i][j] = INF;
			for(int k = i; k < j; k++){
				//연쇄행렬곱셈 -> dp합 뒤는 고유의 값을 넣어야함.
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+ (sum[j]-sum[i-1]) );
			}
		}
	}	
	printf("%lld\n", dp[1][n]);
</pre></code>
</pre></code>
