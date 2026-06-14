#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        for(int i = 0; i < n-k; i++){
            if(s[i] == '1') {
                s[i] = '0';
                if(s[i+k] == '0') s[i+k] = '1';
                else s[i+k] = '0';
            }
        }

        bool ans = true;
        for(int i = n-k; i < n; i++){
            if(s[i] == '1') ans = false;
        }

        if(ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
