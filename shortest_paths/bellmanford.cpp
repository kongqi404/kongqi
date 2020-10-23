#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define INF 10000000
#define MAXN 20005
using namespace std;
struct Edge{                                 //图的边表示法
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct Bellmanford
{
	int n, m;
	int l[MAXN];
	vector<Edge> edges;
	vector<int> G[MAXN];
	int d[MAXN];
	bool done[MAXN];
	Bellmanford(int _n)
	{
		this->n = _n;
		memset(d, 0, sizeof(d));
		memset(done, 0, sizeof(done));
		memset(l,0,sizeof(l));
		m = 0;
		
	}
	void add_edge(int from, int to, int dist)
	{
		edges.push_back(Edge(from,to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void bellmanford(int s)
	{
		queue<int> a;
		
		for (int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		for (int i = 0; i < n; i++)
		{
			a.push(s);
			while (!a.empty())
			{
				int x = a.front();
				a.pop();
				if (done[x]) continue;
				done[x] = true;
				for (int j = 0; j < G[x].size(); j++)
				{
					
					Edge e = edges[G[x][j]];
					a.push(e.to);
					if (d[x] + e.dist < d[e.to])
					{
						d[e.to] = d[x] + e.dist;
					}
				}
			}
			memset(done, 0, sizeof(done));
			int flag=0;
			for(int i=0;i<n;i++)
			{
				if(d[i]!=l[i])
				{
					l[i]=d[i];
					flag=1;
				}
			}
			if(!flag)
				break;
		}
		for (int i = 1; i < n; i++)
		{
			cout << d[i] << endl;
		}
	}


};
int main()
{
	int n,m;
	cin >> n>>m;
	Bellmanford b = Bellmanford(n);
	int from, to, dist;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> dist;
		b.add_edge(from-1, to-1, dist);
	}
	b.bellmanford(0);

}
