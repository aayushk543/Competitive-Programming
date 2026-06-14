#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(auto& x : a) cin >> x;
        sort(a.begin(), a.end());

        vector<bool> dp(n, false);
        int cntTrue = 0;
        int r = n - 1; // right boundary of window (inclusive), starts at last element

        for(int i = n - 1; i >= 0; i--){
            // Shrink r while a[r] > a[i] + k
            while(r > i && a[r] > a[i] + k){
                if(dp[r]) cntTrue--;
                r--;
            }
            // Window of valid next moves is [i+1 .. r]
            // If no winning dp[j] in window, then dp[i]=true (Dabir loses if he picks i)
            dp[i] = (r == i || cntTrue == 0);
            if(dp[i]) cntTrue++;
        }

        bool ok = false;
        for(int i = 0; i < n; i++) if(dp[i]){ ok = true; break; }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}