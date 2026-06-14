#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll,ll>> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    // Sort by x
    sort(pts.begin(), pts.end());

    // Set ordered by y
    set<pair<ll,ll>> st;

    ll ans = LLONG_MAX;
    int left = 0;

    for (int i = 0; i < n; i++) {
        ll x = pts[i].first;
        ll y = pts[i].second;

        // Remove points too far in x
        while (left < i) {
            ll dx = x - pts[left].first;
            if (dx * dx > ans) {
                st.erase({pts[left].second, pts[left].first});
                left++;
            } else break;
        }

        // Only check points within y-range
        ll d = sqrt(ans) + 1;
        auto it1 = st.lower_bound({y - d, -LLONG_MAX});
        auto it2 = st.upper_bound({y + d, LLONG_MAX});

        for (auto it = it1; it != it2; it++) {
            ll dy = y - it->first;
            ll dx = x - it->second;
            ans = min(ans, dx*dx + dy*dy);
        }

        st.insert({y, x});
    }

    cout << ans << '\n';
    return 0;
}
