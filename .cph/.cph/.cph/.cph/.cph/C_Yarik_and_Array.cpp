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

       vector<int> v(n);
       int sum = 0, max_sum = 0;

       for(int i = 0; i < n; i++) {
        cin >> v[i];
        max_sum = max(max_sum, v[i]);
       }

       int i = 1;
       sum = max(v[0],0);

       while(i < n){
            while(i < n && abs(v[i-1]) % 2 != abs(v[i]) % 2){
                
                sum += v[i];
                
                max_sum = max(sum, max_sum);

                if(sum < 0) sum = 0;
                i++;
            }
            while(i < n && abs(v[i-1]) % 2 == abs(v[i]) % 2) i++;
            if(i < n) sum = v[i-1];
       }

       if(v.size() == 1) cout << v[0] << '\n';
       else cout << max(max_sum, sum) << '\n';
    }
    return 0;
}