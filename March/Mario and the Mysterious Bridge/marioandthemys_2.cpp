#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V + 1];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    int minCostBFS(int src, int dest)
    {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> dist(V, 0);

        q.push(src);
        visited[src] = true;
        dist[src] = 0;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (int nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[f] + 1;
                }
            }
        }
        return dist[dest];
    }
};

int min_jumps(int n, vector<pair<int, int> > red, vector<pair<int, int> > blue, vector<int> broken, int maxJmp)
{
    vector<int> board(n + 1, 0);
    vector<int> brokenPlaces(n + 1, 0);
    for (int i = 0; i < broken.size(); i++)
    {
        brokenPlaces[broken[i]] = 1;
    }
    // board to graph conversion
    for (auto sp : blue)
    {

        int s = sp.first;
        int e = sp.second;
        if (!(brokenPlaces[s]) && !(brokenPlaces[e-s]))
        // if (!(brokenPlaces[s]))
            board[s] = -1 * e;
    }

    for (auto lp : red)
    {
        int s = lp.first;
        int e = lp.second;
        if (!(brokenPlaces[s]) && !(brokenPlaces[e+s]))
        // if (!(brokenPlaces[s]))
            board[s] = e;
    }

    // Graph
    Graph g(n + 1);
    for (int u = 1; u < n; u++)
    {
        for (int jmp = 1; jmp <= maxJmp; jmp++)
        {
            int v = u + jmp;
            v += board[v];
            if (v <= n && (!brokenPlaces[v]))
            {
                g.addEdge(u, v);
            }
        }
    }
    return g.minCostBFS(1, n);
}

int main()
{
    
    int n,r, bl, bc,J;

    vector<pair<int, int> > red;
    vector<pair<int, int> > blue;
    vector<int> broken;
    cin >>n>>r >> bl >> bc>>J;
    for (int i = 0; i < r; i++)
    {
        int a, b;
        // cout<<i<<endl;
        cin >> a >> b;
        pair<int, int> t1;
        t1 = make_pair(a, b);
        red.push_back(t1);
    }
    for (int i = 0; i < bl; i++)
    {
        int a, b;
        // cout<<i<<endl;
        cin >> a >> b;
        pair<int, int> t1;
        t1 = make_pair(a, b);
        blue.push_back(t1);
    }

    for (int i = 0; i < bc; i++)
    {
        int tmp;
        cin >> tmp;
        broken.push_back(tmp);
    }


    cout << min_jumps(n, red, blue, broken, J);
}