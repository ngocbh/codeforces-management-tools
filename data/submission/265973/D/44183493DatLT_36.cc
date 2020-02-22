<<<<<<< Updated upstream
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#define For(i, a, b) for(long long i = a; i < b; i++)
using namespace std;

vector<long long> parent;
int result;
struct edge{
	long long u, v, w;
};
struct cmp
{
	bool operator() (struct edge a, struct edge b) 
	{
		return b.w < a.w;
	}
};
class Graph
{
	long long V, E;
	priority_queue<struct edge, vector<struct edge>, cmp > Q; 
	public:
		Graph(long long V, long long E);
		void addEdge(long long u, long long v, long long w);
		void kruskal();
		long long findRoot(long long u);
};

Graph :: Graph(long long V, long long E)
{
	this -> V = V;
	this -> E = E;
}

void Graph :: addEdge(long long u, long long v, long long w)
{
	if(w != -1){
		struct edge e1;
		e1.u = u;
		e1.v = v;
		e1.w = -w;
		Q.push(e1);
	}
	else {
		struct edge e1;
		e1.u = u;
		e1.v = v;
		e1.w = -INT_MAX;
		Q.push(e1);
	}
}
void Graph :: kruskal()
{
	For(i, 0, V) parent.push_back(i);
	long long count = 0;
	long long sum = 0;
	while (!Q.empty())
	{
		struct edge e;
		e = Q.top();
		Q.pop();
		long long rootU = findRoot(e.u);
		long long rootV = findRoot(e.v);
		if(rootU != rootV || e.w == -INT_MAX)
		{
			parent.at(rootV) = rootU;
			sum += e.w;
			//cout << e.w << " ";
			count ++;
		}
		else if (e.w != -INT_MAX) {
			result = -e.w;
			break;
		}
	}
	//---------------------
	cout << result;
}
long long Graph :: findRoot(long long u)
{
	if (u != parent.at(u)) parent[u] = findRoot(parent.at(u));
	return parent[u];
}
//---------------------
int main()
{
	long long n, m;
	cin >> n >> m;
	Graph g(n, m);
	For(i, 0, m)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u - 1, v - 1, w);
	}
	//------------------------------
	g.kruskal();
	return 0;
}
=======
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#define For(i, a, b) for(long long i = a; i < b; i++)
using namespace std;

vector<long long> parent;
int result;
struct edge{
	long long u, v, w;
};
struct cmp
{
	bool operator() (struct edge a, struct edge b) 
	{
		return b.w < a.w;
	}
};
class Graph
{
	long long V, E;
	priority_queue<struct edge, vector<struct edge>, cmp > Q; 
	public:
		Graph(long long V, long long E);
		void addEdge(long long u, long long v, long long w);
		void kruskal();
		long long findRoot(long long u);
};

Graph :: Graph(long long V, long long E)
{
	this -> V = V;
	this -> E = E;
}

void Graph :: addEdge(long long u, long long v, long long w)
{
	if(w != -1){
		struct edge e1;
		e1.u = u;
		e1.v = v;
		e1.w = -w;
		Q.push(e1);
	}
	else {
		struct edge e1;
		e1.u = u;
		e1.v = v;
		e1.w = -INT_MAX;
		Q.push(e1);
	}
}
void Graph :: kruskal()
{
	For(i, 0, V) parent.push_back(i);
	long long count = 0;
	long long sum = 0;
	while (!Q.empty())
	{
		struct edge e;
		e = Q.top();
		Q.pop();
		long long rootU = findRoot(e.u);
		long long rootV = findRoot(e.v);
		if(rootU != rootV || e.w == -INT_MAX)
		{
			parent.at(rootV) = rootU;
			sum += e.w;
			//cout << e.w << " ";
			count ++;
		}
		else if (e.w != -INT_MAX) {
			result = -e.w;
			break;
		}
	}
	//---------------------
	cout << result;
}
long long Graph :: findRoot(long long u)
{
	if (u != parent.at(u)) parent[u] = findRoot(parent.at(u));
	return parent[u];
}
//---------------------
int main()
{
	long long n, m;
	cin >> n >> m;
	Graph g(n, m);
	For(i, 0, m)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u - 1, v - 1, w);
	}
	//------------------------------
	g.kruskal();
	return 0;
}
>>>>>>> Stashed changes
