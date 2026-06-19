#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        int count = 0;
        cin >> n;

        vector<int> arr(2*n + 1, -1);

        for(int i = 0; i < n; i++){
            int x; 
            cin >> x;
            arr[x] = i+1;
        }

        for(int i = 1; i <= 2*n; i++){
            if(i * i > 2*n - 1) break;
            if(arr[i] != -1) {
                
                for(int j = i+1; j <= 2*n && i * j <= 2*n - 1; j++){
                    if(arr[j] == -1) continue;
                    else if(arr[i]  +  arr[j] == i * j) count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
