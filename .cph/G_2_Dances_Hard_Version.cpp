#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, vector<int>& b, int mid) {
    int n = a.size();

    for(int i = mid; i < n; i++) {
        if(a[i - mid] >= b[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n, m;
       cin >> n >> m;

       vector<int> a(n);
       vector<int> b(n);

       a[0] = 1;

       for(int i = 1; i < n; i++) cin >> a[i];
       for(int i = 0; i < n; i++) cin >> b[i];

       a[0] = m;

       sort(a.begin(), a.end());
       sort(b.begin(), b.end());

       if(check(a, b, 0)) {
        cout << 0 << '\n';
        continue;
       }

       int l = 0, r = n;

       while(l < r) {
        int mid = (l + r) / 2;

        if(check(a, b, mid)) r = mid;
        else l = mid + 1;
       }

       cout << max(1, r) << '\n';
    }
    return 0;
}