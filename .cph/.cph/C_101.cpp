#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int ans = 0;
        bool flag = true;
        int prev = -1;

        int maxi_st = 0;
        int maxi_end = 0;

        vector<int> nums(n);

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            nums[i] = num;

            if(num == 1 || num == -1) {
                if(flag == false) {
                    if(i - prev + 1 >= ans) {
                        maxi_st = prev;
                        maxi_end = i;
                    }
                    ans = max(ans, i - prev + 1);
                }
                if(num == 1 || flag == true) {
                    prev = i;
                }
                flag = false;
            } 
        }

        if(nums[maxi_st] == -1) nums[maxi_st] = 1;
        if(nums[maxi_end] == -1) nums[maxi_end] = 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == -1 && (i >= maxi_st && i <= maxi_end)) nums[i] = 0;
            else if(nums[i] == -1) nums[i] = 1;

            cout << nums[i] << " ";
        }

        cout << '\n';

    
    }
    return 0;
}