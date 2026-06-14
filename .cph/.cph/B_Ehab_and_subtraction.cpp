#include<bits/stdc++.h>
using namespace std;

int main() {
    
        int n,k;
        cin >> n >> k;

        vector<long long> arr(n,0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        

        sort(arr.begin(), arr.end());
        long long c = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] - c > 0 && count < k){
                count++;
                cout << arr[i] - c << '\n';
                c += (arr[i] - c);
            }
            else if(count >= k) break;
        }

        while(count < k){
            cout << 0 << '\n';
            count++;
        }
        
    
    return 0; 
}