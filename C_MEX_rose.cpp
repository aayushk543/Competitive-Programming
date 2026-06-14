
#include<iostream>
#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin >> n >> k;
        vector<int> ans(n,0);
        int count = 0;

        for(int i = 0; i < n; i++){
            int s;
            cin >> s;
            if(s < k){
                ans[s]++;
            }
            if(s == k){
                count++;
            }
        }
        int count1 = count;
        int count2 = 0;
        for(int i = 0; i < k; i++){
            if(ans[i] == 0 && count == 0){
                count2++;
            }
            else if(ans[i] == 0 && count > 0){
                count--;
            }
        }
        
        cout << count2 + count1 << '\n';
    }
    return 0;
}