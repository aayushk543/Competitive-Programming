#include<bits/stdc++.h>
using namespace std;

int count_f(vector<long long>& arr) {
    int n = arr.size();

    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }

    sort(v.begin(), v.end());

    vector<bool> vis(n, false);
    long long swaps = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] || v[i].second == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while (!vis[j]) {
            vis[j] = true;
            j = v[j].second;
            cycleSize++;
        }

        swaps += cycleSize - 1;
    }

    return swaps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<long long> a(n);
       vector<long long> b(n);

       for(int i = 0; i < n; i++) cin >> a[i];
       for(int i = 0; i < n; i++) cin >> b[i];

        int ans = 0;
        bool c = true;

       for(int i = 0; i < n; i++){

        int value = b[i];

        
        int k = i;
        int mini = INT_MIN;

        for(int j = i; j < n; j++){
            if(a[j] <= value) {
                k = j;
                mini = a[j];
                break;
            }
        }

        if(mini == INT_MIN) {
            c = false;
            cout << -1 << '\n';
            break;
        }

        int p = k;

        while(k-1 >= i){
            swap(a[k-1], a[k]);
            k--;
            ans++;
        }
       
       }

       if(c) cout << ans << '\n';

    }
    return 0;
}