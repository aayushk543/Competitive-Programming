#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
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
        for(int i = 0; i < n; i++) cin >> arr[i];

        vector<int> six;
        vector<int> two;
        vector<int> three;
        vector<int> other;

        for(int i = 0; i < n; i++) {

            if(arr[i] % 6 == 0) six.push_back(arr[i]);
            else if(arr[i] % 2 == 0) two.push_back(arr[i]);
            else if(arr[i] % 3 == 0) three.push_back(arr[i]);
            else other.push_back(arr[i]);

        }

        for(int i = 0; i < six.size(); i++) cout << six[i] << " ";
        for(int i = 0; i < two.size(); i++) cout << two[i] << " ";
        for(int i = 0; i < other.size(); i++) cout << other[i] << " ";
        for(int i = 0; i < three.size(); i++) cout << three[i] << " ";

        cout << '\n';
    }
    return 0;
}