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

       vector<int> a1(n + 1);
       vector<int> a2(n + 1);

       int l = -1;
       int r = -1;

       int maxi = INT_MIN;
       int mini = INT_MAX;

       for(int i = 1; i <= n; i++) cin >> a1[i];
       for(int i = 1; i <= n; i++) {
        cin >> a2[i];

        if(a1[i] != a2[i] && l == -1) {
            l = i;
            mini = a2[i];
        }
            else if(a1[i] != a2[i] && l != -1) {
            r = i;
            maxi = a2[i];
        }

       }

       if(l == -1 && r == -1) {
        cout << 1 << " " << n << '\n';
        continue;
       }
       else if(r == -1) r = n;

       while(l > 1 && a2[l-1] <= mini) l--;
       while(r < n && a2[r+1] >= maxi) r++;

       cout << l << " " << r << '\n';
       
    }
    return 0;
}