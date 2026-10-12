#include <stdio.h>
#include <stdlib.h>
int cmp(const void *x, const void *y){ return *(int*)x - *(int*)y; }
int main(){
    int n, i, j = 0, r = 0, s[1000], e[1000];
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &s[i], &e[i]);
    qsort(s, n, sizeof(int), cmp);
    qsort(e, n, sizeof(int), cmp);
    for(i=0; i<n; i++){
        if(e[j] <= s[i]) j++;        // a room is free
        else r++;                    // need a new room
    }
    printf("%d\n", r);
    return 0;
}
