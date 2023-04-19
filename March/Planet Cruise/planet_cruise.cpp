#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> planets;
vector<int> f;
int T;
vector<vector<int>> v;

// util function to get manhattan distance between planets
int distance(int i, int j)
{
    return abs(planets[i].first - planets[j].first) + abs(planets[i].second - planets[j].second);
}

int bruteforce(int currentPlanet, int currentCost, int currentTime)
{
    if (currentTime >= T)
    {
        return 10000000;
    }
    if (currentPlanet == n - 1)
    {
        return currentCost;
    }
    int MIN = 10000000;
    for (int nextPlanet = currentPlanet + 1; nextPlanet < n; nextPlanet++)
    {
        int ans = bruteforce(
            nextPlanet,
            currentCost + v[nextPlanet][currentTime + distance(currentPlanet, nextPlanet)] + distance(currentPlanet, nextPlanet) * f[currentPlanet],
            currentTime + distance(currentPlanet, nextPlanet));
        MIN = min(MIN, ans);
    }
    return MIN;
}

void dynamicProgramming()
{
    // Inputs
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        planets.push_back({x, y});
    }
    for (int i = 0; i < n; i++)
    {
        int _f;
        cin >> _f;
        f.push_back(_f);
    }
    cin >> T;
    v = vector(n, vector<int>(T));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < T; j++)
        {
            int _v;
            cin >> _v;
            v[i][j] = _v;
        }
    }

    // sort planets from x
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [](const int lhs, const int rhs)
         { return planets[lhs].first < planets[rhs].first; });
    vector<pair<int, int>> _planets;
    vector<int> _f;
    vector<vector<int>> _v;
    for (int sortedIndex : indices)
    {
        _planets.push_back(planets[sortedIndex]);
        _f.push_back(f[sortedIndex]);
        _v.push_back(vector<int>(v[sortedIndex]));
    }
    planets = _planets;
    f = _f;
    v = _v;

    int dp[110][600];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < T; j++)
        {
            dp[i][j] = 100000000;
        }
    }
    dp[0][0] = 0; // base case
    for (int t = 0; t < T; t++)
    {
        for (int i = 1; i < n; i++)
        {
            int MIN = 100000000;
            for (int j = 0; j < i; j++)
            {
                int d = distance(i, j);
                if (t - d < 0)
                    continue;
                MIN = min(MIN, dp[j][t - d] + f[j] * d);
            }
            dp[i][t] = v[i][t] + MIN;
        }
    }

    // print dp array
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<T; j++) {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    int ans = 100000000;
    for (int i = 0; i < T; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << "\n";
}

int main()
{
    dynamicProgramming();
    bruteforce(0, 0, 0);
}
