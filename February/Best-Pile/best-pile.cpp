#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU
{
    vector<int> parent, sz;
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findsets(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        parent[v] = findsets(parent[v]);
        return parent[v];
    }
    bool unionset(int u, int v)
    {
        u = findsets(u);
        v = findsets(v);
        if (u == v)
        {
            return false;
        }
        if (sz[v] > sz[u])
        {
            swap(u, v);
        }
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};
int main()
{
    ll n, m;
    cin >> n >> m;
    ll grid[n][m];
    ll floodfill[n][m];
    ll currentColor = 1;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    auto g = [&](int i, int j)
    {
        return i * m + j;
    };
    DSU st(n * m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }
            for (int k = 0; k < 4; ++k)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0)
                    continue;
                st.unionset(g(i, j), g(nx, ny));
            }
        }
    }
    int c = 1;
    vector<int> cur(n * m, -1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            floodfill[i][j] = 0;
            if (grid[i][j] == 0)
                continue;
            int v = st.findsets(g(i, j));
            if (cur[v] != -1)
            {
                floodfill[i][j] = cur[v];
            }
            else
            {
                cur[v] = currentColor++;
                floodfill[i][j] = cur[v];
            }
        }
    }
    ll surfaceAreas[currentColor + 1];
    for (ll i = 0; i < currentColor + 1; i++)
    {
        surfaceAreas[i] = 0;
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }
            surfaceAreas[floodfill[i][j]] += 4 * grid[i][j] + 1;
            if (i - 1 >= 0)
            {
                if (floodfill[i - 1][j] == floodfill[i][j])
                {
                    surfaceAreas[floodfill[i][j]] -= min(grid[i][j], grid[i - 1][j]);
                }
            }
            if (i + 1 < n)
            {
                if (floodfill[i + 1][j] == floodfill[i][j])
                {
                    surfaceAreas[floodfill[i][j]] -= min(grid[i][j], grid[i + 1][j]);
                }
            }
            if (j - 1 >= 0)
            {
                if (floodfill[i][j - 1] == floodfill[i][j])
                {
                    surfaceAreas[floodfill[i][j]] -= min(grid[i][j], grid[i][j - 1]);
                }
            }
            if (j + 1 < m)
            {
                if (floodfill[i][j + 1] == floodfill[i][j])
                {
                    surfaceAreas[floodfill[i][j]] -= min(grid[i][j], grid[i][j + 1]);
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < currentColor + 1; i++)
    {
        ans = max(surfaceAreas[i], ans);
    }
    cout << ans << "\n";
    return 0;
}
