#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> arr(n);
    long long sum = 0;
    int maxi = -1;
    int second_maxi = -1;
    int ind = -1;
    bool t1 = true;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];

        if(maxi != -1 && arr[i] == maxi) t1 = false;

        if(arr[i] > maxi) {
            second_maxi = maxi;
            ind = i + 1;
        }
        else second_maxi = max(second_maxi, arr[i]);

        maxi = max(maxi, arr[i]);
    }

    vector<int> ans;

    long long find = sum - maxi;

    if(find > maxi) {
        for(int i = 0; i < n; i++) {
            if(i == ind - 1) continue;
            if(find - arr[i] == maxi) ans.push_back(i + 1);
        }
    }

    
    if((find) % second_maxi == 0 && (find) / second_maxi == 2) ans.push_back(ind);

    cout << ans.size() << '\n';
    if(ans.size() > 0) {for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";}
    if(ans.size() > 0) cout << '\n';

    return 0;
}




