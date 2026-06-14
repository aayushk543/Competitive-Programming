#include <bits/stdc++.h>
using namespace std;

// int target;
// //int max_diff;

// void f(vector<int>& arr, int i, int j, int sum){

//     if(i >= j || j-i+1 < max_diff || sum < target){
//         return;
//     }

//     if(sum == target) {
//         if(j-i+1 >= max_diff) max_diff = j-i+1;
//         return;
//     } 

//     if(arr[i] == 0 && arr[j] == 0){
//         f(arr,i+1,j,sum);
//         f(arr,i,j-1,sum);
//         return;
//     }
//     else if(arr[i] == 1 && arr[j] == 0){
//         f(arr,i,j-1,sum);
//         return f(arr,i+1,j,sum-1);
//     }
//     else if(arr[j] == 1 && arr[i] == 0){
//         f(arr,i+1,j,sum);
//         f(arr,i,j-1,sum-1);
//         return;
//     }
//     f(arr,i,j-1,sum-1);
//     f(arr,i+1,j,sum-1);
//     return;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n,s;
        int sum = 0;

        cin >> n >> s;

        //target = s;
        //max_diff = -1;

        int t_sum = 0;

        vector<int> arr(n+1, 0);

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            t_sum += arr[i];
        }

         int j = 1;
         sum = 0;
         int max_diff = 0;
        
        for(int i = 1; i <= n; i++){
            sum += arr[i];
            if(sum == s) max_diff = max(max_diff, i-j+1);
            while(i > j && sum > s) {
                sum -= arr[j];
                j++;
            }
            if(sum == s) max_diff = max(max_diff, i-j+1);
        }

        if(t_sum >= s) {
            cout << n - max_diff << '\n';
        }
        else cout << -1 << '\n';  

    }

    return 0;
}