#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> arr1(n);
    vector<int> arr2(n);

    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];

    vector<int> vis(n + 1, false);

    int i = 0, j = 0, ans = 0;

    while(i < n && j < n) {
        int curr = arr1[i];

        if(vis[curr] == true) {
            i++;
            continue;
        }

        vis[curr] = true;

        while(j < n && arr2[j] != curr) {
            vis[arr2[j]] = true;
            j++;
            ans++;
        }

        i++;
        j++;
    }

    cout << ans << '\n';
}   