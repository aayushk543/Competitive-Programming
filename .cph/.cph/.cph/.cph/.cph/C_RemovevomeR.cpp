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

        int count = 1;

        int i = 0;
        char prev = s[0];

        while(i < n) {
            if(prev != s[i]) count++;
            prev = s[i];
            i++; 
        }

        if(count == 2) cout << 2 << '\n';
        else cout << 1 << '\n';

    }
    return 0;
}