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

       vector<int> arr(n);

       for(int i = 0; i < n; i++) {
        cin >> arr[i];

       }

       // BS

    //    int first = -1, second = -1, third = -1;
    //    bool c = false;

    //    for(int i = 1; i < n; i++){
    //     if(arr[i-1] < arr[i]){
    //         first = i - 1;
    //         second = i;
    //         c = true;
    //     }
    //     else if(arr[i-1] > arr[i] && c) third = i;
    //    }

    //    if(first == -1 || second == -1 || third == -1) cout << "NO" << '\n';
    //    else {
    //     cout << "YES" << '\n';
    //     cout << first + 1 << " " << second + 1 << " " << third + 1 << '\n';
    //    }

    bool c = true;
    for(int i = 0; i < n-2; i++) {
        int first = arr[i];
        int second = arr[i+1];
        int third = arr[i+2];

        if(first < second && second > third) {
            cout << "YES" << '\n';
            cout << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
            c = false;
            break;
        }
    }

    if(c) cout << "NO" << '\n';


    }
    return 0;
}   