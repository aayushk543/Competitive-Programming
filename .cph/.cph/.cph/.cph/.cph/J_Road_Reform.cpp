#include<bits/stdc++.h>
using namespace std;

int find_parent(vector<int>& parent, int index) {
    if(parent[index] != index) return parent[index] = find_parent(parent, parent[index]);

    return index;
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long m,k;

        cin >> n >> m >> k;

        //cout << 1 << " ";

        priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>> pq;

        for(int i = 1; i <= m; i++) {
            long long a, b, c;

            cin >> b >> c >> a;
            if(b <= k) pq.push({0, c, a}); 
            else pq.push({b - k, c, a});
        }

        //cout << 1 << " ";

        int connection = 0;
        vector<int> parent(n + 1, -1);

        for(int i = 1; i <= n; i++) parent[i] = i;

        int ans = 0;

        while(connection < n - 1 && !pq.empty()) {
            auto [w, x, y] = pq.top();
            pq.pop();

            int parent1 = find_parent(parent, x);
            int parent2 = find_parent(parent, y);

            if(parent1 == parent2) continue;
            connection++;
            ans += w;

            parent[parent1] = parent2;
        }

        cout << ans << '\n';
    }
    return 0;
}   