#include <stdio.h>
int main(){
    int n, i, a, b;
    long long L[1000], x, y, cost = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%lld", &L[i]);
    while(n > 1){
        a = 0;
        for(i=1; i<n; i++) if(L[i] < L[a]) a = i;
        x = L[a]; L[a] = L[n-1]; n--;             // remove the smallest
        b = 0;
        for(i=1; i<n; i++) if(L[i] < L[b]) b = i;
        y = L[b]; L[b] = x + y; cost += x + y;    // merge with the next smallest
    }
    printf("%lld\n", cost);
    return 0;
}
