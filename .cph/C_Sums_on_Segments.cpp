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

        vector<int> arr(n + 1);

        int index = -1;

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            if(arr[i] != 1 && arr[i] != -1) index = i;
        }

        //for(int i = 1; i <= n; i++) arr[i] += arr[i-1];

        if(index == -1) {

            long long mini = 0, maxi = 0;
            long long sum = 0;

            for(int i = 1; i <= n; i++) {
                sum += arr[i];

                if(sum < 0) sum = 0;
                maxi = max(sum, maxi);
            }

            sum = 0;

            for(int i = 1; i <= n; i++) {
                sum += arr[i];

                if(sum > 0) sum = 0;

                mini = min(mini, sum);
            }

            cout << maxi - mini + 1 << '\n';

            for(int i = mini; i <= maxi; i++) {
                cout << i << " ";
            }
            cout << '\n';
        }
        else {

            long long mini = 0, maxi = 0;
            long long sum = 0;
            set<long long> s;

            for(int i = 1; i < index; i++) {
                sum += arr[i];

                if(sum < 0) sum = 0;
                maxi = max(sum, maxi);
            }

            sum = 0;

            for(int i = 1; i < index; i++) {
                sum += arr[i];

                if(sum > 0) sum = 0;

                mini = min(mini, sum);
            }

            for(int i = mini; i <= maxi; i++) s.insert(i);

            mini = 0, maxi = 0;
            sum = 0;

            for(int i = index + 1; i <= n; i++) {
                sum += arr[i];

                if(sum < 0) sum = 0;
                maxi = max(sum, maxi);
            }

            sum = 0;

            for(int i = index + 1; i <= n; i++) {
                sum += arr[i];

                if(sum > 0) sum = 0;

                mini = min(mini, sum);
            }

            sum = 0;

            for(int i = mini; i <= maxi; i++) s.insert(i);

            mini = 0, maxi = 0;

            for(int i = 1; i <= n; i++) {
                sum += arr[i];
                s.insert(sum);
                if(sum < 0 && i < index) sum = 0;
            }

            sum = 0;

            for(int i = n; i >= 1; i--) {
                sum += arr[i];
                s.insert(sum);
                if(sum > 0 && i > index) sum = 0;
            }

            sum = 0;

            for(int i = 1; i <= n; i++) {
                sum += arr[i];
                s.insert(sum);
                if(sum > 0 && i < index) sum = 0;
            }

            sum = 0;

            for(int i = n; i >= 1; i--) {
                sum += arr[i];
                s.insert(sum);
                if(sum < 0 && i > index) sum = 0;
            }

            s.insert(arr[index]);

            cout << s.size() << '\n';

            for(auto it = s.begin(); it != s.end(); it++) {
                cout << *it << " ";
            }

            cout << '\n';
        }
    }
    return 0;
}