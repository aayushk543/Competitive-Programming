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
        vector<pair<int,int>> arr2;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            arr2.push_back({arr[i],i});
        }

        sort(arr2.begin(), arr2.end());

        bool t = true;

        for(int i = 1; i < n; i++){
            if((arr2[i-1].second - arr2[i].second) % 2 == 0){
                t = false;
                break;
            }
        }

        if(t){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

        

    }
    return 0;
}