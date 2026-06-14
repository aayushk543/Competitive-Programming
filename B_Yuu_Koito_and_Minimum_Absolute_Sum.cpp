#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n,0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(!(i == 0 || i == n - 1) && arr[i] == -1){
                arr[i] = 0;
            }
        }

        if(arr[0] == -1 && arr[n-1] == -1){
            arr[0] = 0;
        }
        if(arr[0] == -1){
            arr[0] = arr[n-1];
        }
        if(arr[n-1] == -1){
            arr[n-1] = arr[0];
        }
        cout << abs(arr[0] - arr[n-1]) << '\n';
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
