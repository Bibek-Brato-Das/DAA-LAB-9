#include <stdio.h>
int main(){
    int n, i, m, mn = 1000000000, best = 2000000000, a[1000];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2) a[i] *= 2;
        if(a[i] < mn) mn = a[i];
    }
    while(1){
        m = 0;
        for(i=1; i<n; i++) if(a[i] > a[m]) m = i;
        if(a[m] - mn < best) best = a[m] - mn;
        if(a[m] % 2) break;              // maximum cannot be reduced further
        a[m] /= 2;
        if(a[m] < mn) mn = a[m];
    }
    printf("%d\n", best);
    return 0;
}
