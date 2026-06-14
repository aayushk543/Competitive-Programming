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

        vector<int> arr(n,0);
        int count2 = 0;
        int j;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 2) count2++;
        }

        if(count2%2 == 1){
            cout << -1 << '\n';
        }
        else {
            int c = 0;
            int i;
            for(i = 0; i < n; i++){
                if(arr[i] == 2) c++;
                if(c == count2/2){
                    break;
                }
            }
            cout << i + 1 << '\n';
        }

    }
    return 0;
}
