#include <bits/stdc++.h>
using namespace std;

int a;
multiset<int> r;
multiset<int, greater<int> > o;
int main() {
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
        int b; scanf("%d", &b);
        if (o.empty()) o.insert(b);
        else {
            if (b > *o.begin()) r.insert(b);
            else o.insert(b);
        }
        if (o.size() > r.size() + 1) {
            r.insert(*o.begin());
            o.erase(o.begin());
        } else if (r.size() > o.size()) {
            o.insert(*r.begin());
            r.erase(r.begin());
        }
        if (o.size() > r.size())
            printf("%d.00 ", *o.begin());
        else
            printf("%d.%c0 ", (*o.begin() + *r.begin()) / 2, ((*o.begin() + *r.begin()) & 1) ? '5': '0');
    }
    return 0;
}
