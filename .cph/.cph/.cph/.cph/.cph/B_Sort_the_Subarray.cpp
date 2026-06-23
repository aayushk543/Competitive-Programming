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

       vector<int> a1(n);
       vector<int> a2(n);

       for(int i = 0; i < n; i++) cin >> a1[i];
       for(int i = 0; i < n; i++) {
        cin >> a2[i];
       }

       vector<int> ans(2, -1);
       int max_len = -1;

       for(int i = 1; i < n; i++){
        if(a2[i-1] <= a2[i]){
            int l = i-1;
            int r = i-1;

            bool c = true;

            while(r < n-1 && a2[r] <= a2[r+1]) {
                r++;
                c = (a2[r] == a1[r]);
            }

            if(c == false && max_len < r - l + 1) {
                max_len = r - l + 1;
                ans[0] = l;
                ans[1] = r+1;
            }
            i = r+1;
        }
       }

       cout << ans[0] + 1 << " " << ans[1] << '\n';



    }
    return 0;
}