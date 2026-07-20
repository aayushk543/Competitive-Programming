#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<int> arr(n+1);
       for(int i = 1; i <= n; i++) cin >> arr[i];

       vector<int> ans(n + 1);
       int j = 1;
       int mini = arr[j];

       for(int i = 1; i <= n; i++)  {
        while(mini < i - j + 1) {
            j++;
            mini = arr[j];
        }
        
        ans[i] = i - j + 1;
       }

       for(int i = 1; i <= n; i++) cout << ans[i] << " ";
       cout << '\n';
    }
    return 0;
}