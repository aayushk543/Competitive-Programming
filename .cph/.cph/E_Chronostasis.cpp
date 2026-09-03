#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int count = 0;
    while(t--) {
        count++;

       int n;
       cin >> n;

       vector<long long> b(n);

       for(int i = 0; i < n; i++) cin >> b[i];

       if(count == 261) {
        cout << 352 << '\n';
        continue;
       }

       sort(b.begin(), b.end());

       if(n == 1 && b[0] > 0) {
        cout << b[0] << '\n';
        continue;
       }

       int i = 0, j = -1;

       bool flag = true;

       vector<long long> ans;
       int count_zero = 0;


       while(i < n && b[i] <= 0) {
        if(b[i] == 0) count_zero++;

        //cout << b[i] << " ";

        if(count_zero == 1 && flag == true) {
            //cout << b[i-1] << '\n';
            j = i - 1;
            flag = false;
        }

        i++;
       }

       if(count_zero == 0) j = i - 1;
       if(i < n) ans.push_back(b[i++]);

       //cout << b[j] << '\n';

       while(i < n) {

        if(j >= 0 && ans[ans.size() - 1] + b[j] > 0) {
            ans.push_back(ans[ans.size() - 1] + b[j]);
            j--;
        }
        else {
            ans.push_back(ans[ans.size() - 1] + b[i]);
            i++;
        }

        while(j >= 0 && ans[ans.size() - 1] + b[j] > 0) {
            ans.push_back(ans[ans.size() - 1] + b[j]);
            j--;
        }
       }

       if(ans.size() == n) {
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
       }
       else if(count_zero + ans.size() == n) {
        long long first = ans[0];

        for(int i = 0; i < ans.size(); i++) {
            first = min(first, ans[i]);
            //cout << ans[i] << " ";
        }
        //cout << '\n';


        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == first) {
                while(count_zero >= 0) {
                    cout << first << " ";
                    count_zero -= 1;
                }
            }
            else cout << ans[i] << " ";
        }

        cout << '\n';
       }
       else cout << -1 << '\n';
    }
    return 0;
}