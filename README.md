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
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost)
			continue;

		for(int i=0; i<graph[here].size(); i++){
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
<pre><code>
int Lower_Bound(vector<int> vt, int num) {
    int low = 0, high = vt.size() - 1;
 
    while (low < high) {
        int mid = (low + high) / 2;
        if (vt[mid] >= num)
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}
 
int main(void)
{
    int n, num;
    scanf("%d", &n);
    vector<int> vt;
    vt.push_back(-1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num > vt[vt.size()-1])
            vt.push_back(num);
        else 
            vt[Lower_Bound(vt, num)] = num;
    }
    printf("%d", n - vt.size() + 1);
 
    return 0;
}


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
