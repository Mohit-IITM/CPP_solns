#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>

using namespace std;

/* ************************************************************************************************************************************ */
typedef long long ll;
typedef long double ld;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define endl "\n"
#define ya cout << "YES" << endl;
#define na cout << "NO" << endl;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long
int mod = 1000000007;
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
    {
        x += m0;
    }
    return x;
}
vector<bool> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))
    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}

/* ************************************************************************************************************************************* */
/* CODE BEGINS HERE */

void solv()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    forn(i, n)
    {
        cin >> h[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfs;
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> vis(n, false);
    forn(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int val = h[x] - h[y];
        adj[x].push_back({val, y});
        adj[y].push_back({-val, x});
    }
    vector<int> mins(n, 0);
    bfs.push({0, 0});
    vis[0] = true;
    while (!bfs.empty())
    {
        int node = bfs.top().second;
        int val1 = bfs.top().first;
        mins[node] += val1;
        bfs.pop();
        for (auto x : adj[node])
        {
            if (!vis[x.second])
            {
                vis[x.second] = true;
                bfs.push(x);
            }
        }
    }
    int q;
    cin >> q;
    forn(i, q)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        if (mins[x] - mins[y] > z)
        {
            na;
        }
        else
        {
            ya;
        }
    }
    forn(i, n)
    {
        // cout << mins[i] << " ";
    }
    // cout << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solv();
    }
}