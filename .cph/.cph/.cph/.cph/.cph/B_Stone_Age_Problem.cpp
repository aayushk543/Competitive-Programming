#include<bits/stdc++.h>
using namespace std;

int find_parent(int index, vector<int>& parent) {
    if(index != parent[index]) return parent[index] = find_parent(parent[index], parent);

    return index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1, 0);
    long long sum = 0;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    bool ini1 = false; 
    long long curr = -1;
    int last_update = -1;
    vector<pair<long long, int>> prev(n+1, {-1,-1});

    for(int i = 1; i <= q; i++){
        int m;
        cin >> m;
        if(m == 1) {
            int ind;
            long long val;

            cin >> ind >> val;

            if(!ini1) {
                sum += (val - arr[ind]);
                arr[ind] = val;                
            }
            else {
                if(last_update > prev[ind].second) {
                    sum += (val - curr);
                    prev[ind].first = val;
                    prev[ind].second = i;
                }
                else {
                    sum += (val - prev[ind].first);
                    prev[ind].first = val;
                    prev[ind].second = i;
                }
            }

            cout << sum << '\n'; 
        }
        else {

            ini1 = true;
            last_update = i;
            
            cin >> curr;

            sum = curr*n;

            cout << sum << '\n';
        }
    }
    return 0;
}