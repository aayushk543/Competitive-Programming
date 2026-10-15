#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,k,z;
       cin >> n >> k >> z;

       vector<int> arr(n);

       for(int i = 0; i < n; i++) cin >> arr[i];

       queue<tuple<int,int,int,int,int>> q;

       q.push({arr[0], 0, 0, 0, 0});

       vector<int> vis(n, INT_MIN);

       vis[0] = arr[0];

       while(!q.empty()) {
        auto [score, l, r, prev, index] = q.front();
        q.pop();

        if(l + r >= k || vis[index] > score) continue;

        if((l < z && prev == 2 && index > 0) && (vis[index - 1] < score + arr[index - 1])) {
            vis[index - 1] = score + arr[index - 1];
            q.push({score + arr[index - 1], l + 1, r, 1, index - 1});
        }
        if(index < n - 1 && vis[index + 1] < score + arr[index + 1]) {
            vis[index + 1] = score + arr[index + 1];
            q.push({score + arr[index + 1], l, r + 1, 2, index + 1});
        }

       }

       int ans = -1;

       for(int i = 0; i < n; i++) ans = max(ans, vis[i]);

       cout << ans << '\n';
    }
    return 0;
}