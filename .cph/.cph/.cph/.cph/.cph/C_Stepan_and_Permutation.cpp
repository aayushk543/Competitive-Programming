#include<bits/stdc++.h>
using namespace std;

int find_parent(int index, vector<int>& parent) {
    if(index != parent[index]) return parent[index] = find_parent(parent[index], parent);

    return index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, x, y;

        cin >> n >> x >> y;

        if(x > y) swap(x,y);

        vector<int> arr(n + 1);
        vector<int> parent(n + 1);
        vector<int> size(n + 1, 1);


        for(int i = 1; i <= n; i++) cin >> arr[i];
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(int i = 1; i <= n; i++) {
            if(i + x > n) break;
            if(i + x <= n) {
                int parent1 = find_parent(i, parent);
                int parent2 = find_parent(i + x, parent);

                int size1 = size[parent1];
                int size2 = size[parent2];

                if(size1 >= size2) {
                    parent[parent2] = parent1;
                    size[parent1] += size2;
                }
                else {
                    parent[parent1] = parent2;
                    size[parent2] += size1;
                }
            }

            if(i + y > n) continue;

            if(i + y <= n) {
                int parent1 = find_parent(i, parent);
                int parent2 = find_parent(i + y, parent);

                int size1 = size[parent1];
                int size2 = size[parent2];

                if(size1 >= size2) {
                    parent[parent2] = parent1;
                    size[parent1] += size2;
                }
                else {
                    parent[parent1] = parent2;
                    size[parent2] += size1;
                }
            }

        }

        bool flag = true;

        for(int i = 1; i <= n; i++) {
            if(find_parent(i, parent) != find_parent(arr[i], parent)) {
                cout << "NO" << '\n';
                flag = false;
                break;
            }
            
        }

        if(flag) cout << "YES" << '\n';


    }
    return 0;
}