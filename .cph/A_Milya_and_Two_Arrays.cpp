#include<bits/stdc++.h>
using namespace std;

int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        set<int> s1;
        set<int> s2;

        int count = 0;
        map<int,int> mp;

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;
            s1.insert(curr);
        }

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;
            s2.insert(curr);
        }

        if(s1.size() + s2.size() <= 3) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}