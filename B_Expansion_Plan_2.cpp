#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x,y;
        string s;

        cin >> n >> x >> y;

        cin >> s;

        int c1 = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '4') c1++;
        }

        x = abs(x);
        y = abs(y);

        if(c1 > 0) n--;

        if(x <= n && y <= n){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

    }
    return 0;
}