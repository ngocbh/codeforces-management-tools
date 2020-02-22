<<<<<<< Updated upstream
#include <queue>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

#define INF 0x3f3f3f

typedef pair<int, int> iPair;

class Graph
{
    int V;
    vector<iPair> *adj;

public:
    Graph(int V);
    ~Graph()
    {
        delete[] adj;
    }

    void AddEgde(int u, int v, int weight);

    void AddHalfEgde(int u, int v, int weight);

    void DijkstraMinStreet(int goc, int dich);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<iPair>[V + 1];
}

void Graph::AddEgde(int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Graph::AddHalfEgde(int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
}

void Graph::DijkstraMinStreet(int goc, int dich)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> q;
    vector<int> d(V + 1, INF);
    vector<int> p(V + 1, 0);
    vector<bool> f(V + 1, 0);

    d[goc] = 0;
    q.push(make_pair(d[goc], goc));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (f[u])
            continue;
        f[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (d[v] > d[u] + weight)
            {
                d[v] = d[u] + weight;
                q.push(make_pair(d[v], v));
            }
        }
    }
    long long res = d[dich];
    printf("%d", d[dich]);
}

int main()
{

    int m, n;
    Graph *g;
    scanf("%d%d", &n, &m);
    g = new Graph(n);
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        g->AddHalfEgde(u, v, w);
    }
    for (int i = 1; i <= n; i++)
    {
        g->AddHalfEgde(i, i - 1, 0);
    }
    g->DijkstraMinStreet(0, n);
    return 0;
}
=======
#include <queue>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

#define INF 0x3f3f3f

typedef pair<int, int> iPair;

class Graph
{
    int V;
    vector<iPair> *adj;

public:
    Graph(int V);
    ~Graph()
    {
        delete[] adj;
    }

    void AddEgde(int u, int v, int weight);

    void AddHalfEgde(int u, int v, int weight);

    void DijkstraMinStreet(int goc, int dich);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<iPair>[V + 1];
}

void Graph::AddEgde(int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void Graph::AddHalfEgde(int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
}

void Graph::DijkstraMinStreet(int goc, int dich)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> q;
    vector<int> d(V + 1, INF);
    vector<int> p(V + 1, 0);
    vector<bool> f(V + 1, 0);

    d[goc] = 0;
    q.push(make_pair(d[goc], goc));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (f[u])
            continue;
        f[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (d[v] > d[u] + weight)
            {
                d[v] = d[u] + weight;
                q.push(make_pair(d[v], v));
            }
        }
    }
    long long res = d[dich];
    printf("%d", d[dich]);
}

int main()
{

    int m, n;
    Graph *g;
    scanf("%d%d", &n, &m);
    g = new Graph(n);
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        g->AddHalfEgde(u, v, w);
    }
    for (int i = 1; i <= n; i++)
    {
        g->AddHalfEgde(i, i - 1, 0);
    }
    g->DijkstraMinStreet(0, n);
    return 0;
}
>>>>>>> Stashed changes
