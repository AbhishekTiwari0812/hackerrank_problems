#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;
    vector<pair<long long,long long> > v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &v[i].first, &v[i].second);        
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    set<pair<int,int> > q;
    long long t = v[0].first;
    int it = 0;
    while (it < n || q.size()) {
        while (it < n && v[it].first <= t) {
            q.insert(make_pair(v[it].second, it));
            ++it;
        }
        if (q.empty()) {
            t = v[it].first;
        } else {
            int i = q.begin()->second;
            q.erase(q.begin());
            t += v[i].second;
            sum += t-v[i].first;
        }
    }
    cout << sum / n << endl;
    return 0;
}