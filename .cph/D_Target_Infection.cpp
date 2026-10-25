#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       long long m,k;

       vector<vector<int>> arr(n);

       for(int i = 0; i < n; i++) {
        int u,v;
        cin >> u >> v;

        arr[i] = {u, v};
       }

       sort(arr.begin(), arr.end());

       long long count = 0;

       int i = 0, j = 0;

       while(j - i + 1 < m) {
        if()
       }
    }
    return 0;
}