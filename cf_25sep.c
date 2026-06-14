#include<stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main () {
    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);
        int ans = 0;
        int neg = 0;
        long long int arr[n];

        for(int i = 0; i < n; i++){
            scanf("%d",&arr[i]);
        }
        int s = sizeof(arr) / sizeof(arr[0]);
        qsort(arr, s, sizeof(long long), compare);
        long long int diff = 0;
        for(int i = 0; i < n; i+=2){

        }
        printf("%d\n",ans);

    }
}