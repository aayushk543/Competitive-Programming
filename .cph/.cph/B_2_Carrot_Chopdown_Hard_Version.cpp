#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m;
       cin >> n >> m;

       vector<int> arr(m + 1, 0);

       for(int i = 0; i < n; i++) {
        int curr;
        cin >> curr;

        arr[curr]++;
       }

       vector<int> freq(m + 1);

       for(int i = 1; i <= m; i++) freq[i] += freq[i-1];

       vector<int> ans(m, 0);



       for(int i = 1; i <= m; i++) {

        for(int j = 1; j * i <= m; j++) {
            int l = j * i;
            int r = min(m, (j + 1)*i);

            
        }
       }

       for(int i = 0; i < m; i++) cout << ans[i] << " ";
       cout << '\n';


    }
    return 0;
}