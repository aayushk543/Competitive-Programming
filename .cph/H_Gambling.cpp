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

        vector<int> x(n);
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            cin >> x[i];
            mp[x[i]].push_back(i);
        }

        


    }
    return 0;
}