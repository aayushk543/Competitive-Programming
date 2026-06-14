#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        vector<ll> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<ll> pref(n);
        pref[0] = b[0];
        vector<int> cnt(n+1);
        vector<ll> extra(n);

        for(int i = 1; i < n; i++) pref[i] = pref[i-1] + b[i];

        for(int i = 0; i < n; i++){
            ll need = a[i] + (i > 0 ? pref[i-1] : 0);

            int j = lower_bound(pref.begin(), pref.end(), need) - pref.begin();

            cnt[i]++;
            cnt[j]--;

            if(j < n){
                ll used = (i > 0 ? pref[j] - pref[i-1] : pref[j]);
                extra[j] += a[i] - (used - b[j]);
            }

        }
        ll active = 0;
        for (int i = 0; i < n; i++) {
            active += cnt[i];
            cout << active * b[i] + extra[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}