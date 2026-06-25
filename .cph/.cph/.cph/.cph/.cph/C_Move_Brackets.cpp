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
       int sum = 0;

       for(int i = 0; i < n; i++){
        if(s[i] == '(') sum++;
        else sum--;
        if(sum < 0) ans = max(ans, -1*sum);
       }

       cout << ans << '\n';
    }
    return 0;
}