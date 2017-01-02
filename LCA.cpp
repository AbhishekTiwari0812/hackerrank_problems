#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;

int ROOT = 0;

const int maxn = 1e6 + 10;
const int maxd = 21;

int fenw[maxn * 2];

void add(int pos, int delta)
{
    for (int i = pos; i < maxn * 2; i = i | (i + 1))
        fenw[i] += delta;
}

int get(int pos)
{
    int res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
        res += fenw[i];
    return res;
}

int get(int l, int r)
{
    return get(r - 1) - get(l - 1);
}

vector<int> g[maxn];

int timer;
int in[maxn], out[maxn];

int euler[maxd][maxn * 2];
int height[maxn];
int maxlog[maxn * 2];

inline int better(int u, int v)
{
    return height[u] < height[v] ? u : v;
}

void dfs(int u, int prev = -1, int h = 0)
{
    in[u] = timer;
    height[u] = h;
    euler[0][timer++] = u;
    for (int v: g[u])
    {
        if (v == prev)
            continue;
        dfs(v, u, h + 1);
        euler[0][timer++] = u;
    }
    out[u] = timer;
}

inline int lca(int u, int v)
{
    int l = min(in[u], in[v]);
    int r = max(out[u], out[v]);
    int deg = maxlog[r - l];
    return better(euler[deg][l], euler[deg][r - (1 << deg)]);
}

int calculate(vector<int> &a)
{
    if (a.size() < 2)
        return 0;

    int candidate = 0;
    forn (i, sz(a))
        if (height[a[i]] < height[a[candidate]])
            candidate = i;
    rotate(a.begin() + candidate, a.begin() + candidate + 1, a.end());

    int other_lca = a[0];
    forn (i, sz(a) - 1)
        other_lca = lca(other_lca, a[i]);
    int root = lca(a.back(), other_lca);

    int cnt = 0;
    if (a.back() == root && other_lca != root)
        ++cnt;

    for (int u: a)
        add(in[u], 1);
    for (int u: a)
    {
        int c = get(in[u], out[u]);
        assert(c >= 1);
        cnt += (c == 1);
    }
    for (int u: a)
        add(in[u], -1);
    return cnt;
}

int main()
{
    int n;
    scanf("%d\n", &n);
    ROOT = rand() % n;
    forn (i, n - 1)
    {
        int u, v;
        scanf("%d %d\n", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(ROOT);
    assert(timer < 2 * maxn);
    forn (deg, maxd - 1)
        forn (i, timer - 2 * (1 << deg) + 1)
            euler[deg + 1][i] = better(euler[deg][i], euler[deg][i + (1 << deg)]);
    int lg = 0;
    forn (i, timer)
    {
        while (2 * (1 << lg) <= i)
            ++lg;
        maxlog[i] = lg;
    }

    int q;
    scanf("%d\n", &q);
    forn (i, q)
    {
        int s;
        scanf("%d", &s);
        assert(s >= 1 && s <= n);
        vector<int> a;
        forn (j, s)
        {
            int u;
            scanf(" %d", &u);
            --u;
            a.push_back(u);
        }
        scanf("\n");
        printf("%d\n", (calculate(a) + 1) / 2);
    }
    return 0;
}