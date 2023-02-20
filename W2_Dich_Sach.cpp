#include <bits/stdc++.h>
#define taskname "O"
using namespace std;

typedef pair<int, int> ii;

struct Node{
	int cnt, cost, id;
	Node(){}
	Node(int cnt, int cost, int id){
		this->cnt = cnt;
		this->cost = cost;
		this->id = id;
	}
	friend bool operator <(const Node &a, const Node &b){
		return a.cnt > b.cnt || (a.cnt == b.cnt && a.cost > b.cost);
	}
};

int n, m;
map<string, int> id;
vector<ii> adj[110];

priority_queue<Node> PQ;
int d[110], cnt[110];
bool isVisit[110];

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		id[s] = i;
	}
	for (int i = 1; i <= m; i++){
		string s_u, s_v; cin >> s_u >> s_v;
		int c; cin >> c;
		int u = id[s_u], v = id[s_v];
		adj[u].push_back(ii(v, c));
		adj[v].push_back(ii(u, c));
	}
}
void Dijkstra(){
	for (int i = 1; i <= n; i++) d[i] = 2e9, cnt[i] = 1000;
	PQ.push(Node(cnt[0], d[0], 0));
	
	while (!PQ.empty()){
		int u = PQ.top().id; PQ.pop();
		if (isVisit[u] == 1) continue;
		isVisit[u] = 1;
		for (ii &e: adj[u]){
			int v = e.first, c = e.second;
			if(isVisit[v] == 1) continue;
			if (cnt[v] > cnt[u] + 1){
				cnt[v] = cnt[u] + 1;
				d[v] = c;
				PQ.push(Node(cnt[v], d[v], v));
			}
			else if (cnt[v] == cnt[u] + 1){
				if (d[v] > c){
					d[v] = c;
					PQ.push(Node(cnt[v], d[v], v));
				}
			}
		}
	}
}
void Solve(){
	Dijkstra();
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		if (d[i] == 2e9){
			cout << "Impossible";
			return ;
		}
		ans += d[i];
	}
	cout << ans;
}

int main(){
	Input();
	Solve();
	return 0;
}
