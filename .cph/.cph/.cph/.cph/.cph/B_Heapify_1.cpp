#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(int n, int size){
    ll sum = 0;

    while(n <= size){
        sum += n;
        n = n*2;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n + 1);

        for(int i = 1; i <= n; i++) cin >> arr[i];

        bool y = true;

        for(int i = 1; i <= n; i++){

            if(arr[i] == -1) continue;
            else {
            ll sum = 0;
            int m = i;
            int cc = i;
            int maxi = arr[i];
            int prev = m;
            
            while(m <= n){
                maxi = min(maxi, arr[i]);
                sum += arr[m];
                arr[m] = -1;
                prev = m;
                m = m*2;
            }

            // if(f(i,n) == sum){
            //     if(m == maxi) y = true;
            //     else {
            //     y = false;
            //     break;
            // }
            // }
            // else {
            //     y = false;
            //     break;
            // }
            // if(f(i,n) != sum){
            //     y = false;
            //     break;
            // } 

            if(f(i,n) == sum && maxi == cc) continue;
            else{
                y = false;
                break;
            }
            }

        }
        if(y) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}




