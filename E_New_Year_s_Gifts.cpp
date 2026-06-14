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

        long long k;
        cin >> k;

        vector<int> a(m,0);

        for(int i = 0; i < m; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());
  
        vector<long long> x1;
        vector<long long> x;
        vector<long long> x2;
        vector<long long> x3;

        vector<long long> z;
        int s1 = 0, k1 = 0;

        long long sum = 0;
        int ans = 0;

        vector<long long> xz;

        for(int i = 0; i < n && k > 0; i++){
            long long m1,m2,m3;
            cin >> m1 >> m2 >> m3;

            x1.push_back(m1);
            x2.push_back(m2);
            x3.push_back(m3);
        }

        

        k -= sum;

        int i, j = -1;
        for(i = 0; i < n && k -xz[i] >= 0; i++){
            ans++;
            k -= xz[i];
        }

        if(i < ans2.size() && k -xz[i] < 0){
            cout << ans << '\n';
        }
        else {
            while(k){
                j++;
                long long xr = x[j];
                while(k < m && a[k1] < xr){
                    k1++;
                } 
                k -= xr;
                ans++;
            }
        }
        if(k < 0) ans--;

        cout << ans << '\n';

    }
    return 0;
}