#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m;
       cin >> n >> m;

       vector<long long> v1(n);
       vector<long long> v2(m);

       for(int i = 0; i < n; i++) cin >> v1[i];
       for(int i = 0; i < m; i++) cin >> v2[i];

       long long g1 = 0;
       long long g2 = 0;

       if(n == 1) g1 = v1[0];
       if(m == 1) g2 = v2[0];

       for(int i = n - 1; i > 0; i--) {

        if(v1[i] == 0) break;
        g1 += v1[i - 1] - v1[i] + 1; 
        if(i == 1) g1 += v1[n-1];
       }


       for(int i = m - 1; i > 0; i--) {

        if(v2[i] == 0) break;
        g2 += v2[i - 1] - v2[i] + 1; 
        if(i == 1) g2 += v2[m-1];
       }

       //cout << g1 << " " << g2 << '\n';

       if(g1 >= g2) cout << 1 << '\n';
       else cout << 2 << '\n'; 

    }
    return 0;
}