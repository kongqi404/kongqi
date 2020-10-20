#include<iostream>
#include<vector>
#include<queue>
constexpr int inf = 10000;
constexpr int maxn = 100;
using namespace std; 
struct Edge{                                 //图的边表示法
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	Dijkstra() 
	{
		memset(done, 0, sizeof(done));
		memset(d, 0, sizeof(d));
		n = 0;
		m = 0;
	}
	void init(int n) 
	{ 
		this->n = n; 
	}
	void add_edge(int from, int to, int dist)
	{
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}
	void dijkstra(int s) 
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> a;
		for (int i = 0; i < n; i++) d[i] = inf;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		a.push({ 0,s });
		while (!a.empty())
		{
			pair<int, int> x = a.top();
			a.pop();
			if (done[x.second]) continue;
			done[x.second] = true;
			for (int i = 0; i < G[x.second].size(); i++)
			{
				Edge e = edges[G[x.second][i]];
				if (e.dist + d[x.second] < d[e.to])
				{
					d[e.to] = e.dist + d[x.second];
					a.push({ d[e.to],e.to });
				}
			}
		}
	}
};
int main()
{
	Dijkstra  s = Dijkstra();
	int n,l;
	cin >> n;
	s.init(n);
	int from, to, dist;
	cin >> from>>to >> dist;
	while (from < n && from >= 0 && to < n && to >= 0 && from != to && dist >= 0)
	{
		s.add_edge(from, to, dist);
		cin >> from >> to >> dist;
	}
	cin >> l;
	s.dijkstra(l);
	for (int i = 0; i < n; i++)
	{
		cout << s.d[i] << endl;
	}

}
