#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> mp;

        vector<int> pos(n, INT_MIN);
        vector<int> last_pos(n);

        map<int,int> mp2;

        for(int i = 0; i < n; i++) {
            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
                pos[i] = i + 1;
                last_pos[i] = n - i;

                mp2[arr[i]] = i;
            }
            else {
                pos[mp2[arr[i]]] = max(pos[mp2[arr[i]]], i - mp[arr[i]]);
                last_pos[mp2[arr[i]]] = n - i;
                mp[arr[i]] = i;
            }
        }

        for(int i = 0; i < n; i++) {
            if(pos[i] != INT_MIN) {
                //cout << arr[i] << " " << pos[i] << '\n';
                pos[i] = max(pos[i], last_pos[i]);
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++) {

            if(pos[i] == INT_MIN) continue;
            else {
                pq.push({pos[i], arr[i]});
            }
        }

        int mini = INT_MAX;

        for(int i = 1; i <= n; i++) {

            while(!pq.empty() && i == pq.top().first) {
                mini = min(mini, pq.top().second);
                pq.pop();
            }

            if(mini == INT_MAX) cout << -1 << " ";
            else cout << mini << " ";
        }

        cout << '\n';
    }
}