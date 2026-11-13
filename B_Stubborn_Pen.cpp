#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n; 
        string s;
        cin >> s;

        int ans = 0;

        if(n > 0 && s[0] == 'B') ans++;

        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}