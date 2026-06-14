#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt = 0;

void merge_count(vector<ll>& a, int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    merge_count(a, l, mid);
    merge_count(a, mid + 1, r);

    vector<ll> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            cnt += (mid - i + 1); 
            temp.push_back(a[j++]);
        }
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = l; k <= r; k++)
        a[k] = temp[k - l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<ll,ll>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        sort(v.begin(), v.end());

        vector<ll> r(n);
        for (int i = 0; i < n; i++)
            r[i] = v[i].second;

        cnt = 0;
        merge_count(r, 0, n - 1);

        cout << cnt << '\n';
    }
}
