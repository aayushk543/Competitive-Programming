#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int a,b,k;
       cin >> a >> b >> k;

       vector<vector<int>> vec(k + 1, vector<int>(2));

       for(int i = 1; i <= k; i++) cin >> vec[i][0];
       for(int i = 1; i <= k; i++) cin >> vec[i][1];

       vector<vector<int>> adj1(a + 1);
       vector<vector<int>> adj2(b + 1);

       for(int i = 1; i <= k; i++) {
        adj1[vec[i][0]].push_back(vec[i][1]);
        adj2[vec[i][1]].push_back(vec[i][0]);
       }

    //    vector<int> parent(k + 1);
    //    vector<int> size(k + 1, 1);

    //    for(int i = 1; i <= k; i++) parent[i] = i;

    //    for(int i = 1; i <= k; i++) {

    //     if(parent[i] != i) continue;


    //    }

    long long ans = 0;

    for(int i = 1; i <= k; i++) {
        int curr1 = vec[i][0];
        int curr2 = vec[i][1];

        int size1 = adj1[curr1].size();
        int size2 = adj2[curr2].size();

        ans += (k - (size1 + size2 - 2) - 1);
    }

    cout << ans / 2 << '\n';

    }
    return 0;
}