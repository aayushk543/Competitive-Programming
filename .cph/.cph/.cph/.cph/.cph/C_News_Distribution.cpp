#include<bits/stdc++.h>
using namespace std;

int find_parent(int index, vector<int>& parent) {
    if(index != parent[index]) return parent[index] = find_parent(parent[index], parent);

    return index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
       cin >> n >> m;

       vector<int> parent(n + 1);
       vector<long long> size(n + 1, 1);

       for(int i = 1; i <= n; i++) parent[i] = i;

       for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;

        int curr;

        if(k > 0) cin >> curr;

        //curr = find_parent(curr, parent);

        for(int j = 2; j <= k; j++) {
            int now;
            cin >> now;

            int parent1 = find_parent(now, parent);
            int parent2 = find_parent(curr, parent);
            long long size1 = size[parent1];
            long long size2 = size[parent2];

            if(size1 > size2) {
                parent[parent2] = parent1;
                size[parent1] += size[parent2];
            }
            else {
                parent[parent1] = parent2;
                size[parent2] += size[parent1];
            }
        }
        
       }

       for(int i = 1; i <= n; i++) cout << size[find_parent(i, parent)] << " ";

       cout << '\n';
    return 0;
}