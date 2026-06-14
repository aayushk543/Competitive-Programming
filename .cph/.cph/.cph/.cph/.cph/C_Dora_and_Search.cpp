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

        vector<int> nums(n, 0);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int i = 0, j = n - 1;

        int mini = 1, maxi = n;
        int c = 0;

        while(i < j && c < n){
            if(nums[i] == mini){
                mini++;
                i++;
            }
            else if(nums[i] == maxi){
                maxi--;
                i++;
            }

            if(nums[j] == mini){
                mini++;
                j--;
            }
            else if(nums[j] == maxi){
                maxi--;
                j--;
            }
            c++;
            
        }

        if(i >= j){
            cout << -1 << '\n';
        }
        else {
            cout << i + 1 << " " << j + 1 << '\n';
        }
        
    }
    return 0;
}
