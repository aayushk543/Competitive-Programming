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

        int l = (n*(n-1))/2;
        

        vector<long long> arr(l,0);

        for(int i = 0; i < l; i++){
            cin >> arr[i];
            
        }

        long long maxi = arr[0];

        sort(arr.begin(), arr.end());

        int count = n-2;
        cout << arr[count] << " ";

        for(int i = 1; i < n-1; i++){
            count += (n-i-1);
            cout << arr[count] << " ";
        }

        cout << maxi + 1 << '\n';

        
    }
    return 0;
}