#include <stdio.h>
int main(){
    int n, i, j, k, m, a, b, t, code, f[40], p[40], len[20], id[20];
    long long cost = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++){ scanf("%d", &f[i]); p[i] = -1; }   // p = parent, -1 = active root
    m = n;
    for(k=0; k<n-1; k++){
        a = b = -1;                                        // two smallest active nodes
        for(i=0; i<m; i++) if(p[i] == -1){
            if(a == -1 || f[i] < f[a]){ b = a; a = i; }
            else if(b == -1 || f[i] < f[b]) b = i;
        }
        f[m] = f[a] + f[b]; p[m] = -1; p[a] = p[b] = m; m++;
    }
    for(i=0; i<n; i++){
        len[i] = 0;
        for(j=i; p[j] != -1; j=p[j]) len[i]++;             // depth of symbol i
        id[i] = i; cost += (long long)f[i]*len[i];
    }
    for(i=0; i<n; i++)                                     // sort by (length, symbol)
        for(j=i+1; j<n; j++)
            if(len[id[j]] < len[id[i]] || (len[id[j]] == len[id[i]] && id[j] < id[i])){
                t = id[i]; id[i] = id[j]; id[j] = t;
            }
    code = 0;
    printf("symbol\tfreq\tlength\tcode\n");
    for(i=0; i<n; i++){
        if(i > 0) code = (code + 1) << (len[id[i]] - len[id[i-1]]);
        printf("%d\t%d\t%d\t", id[i]+1, f[id[i]], len[id[i]]);
        for(j=len[id[i]]-1; j>=0; j--) printf("%d", (code >> j) & 1);
        printf("\n");
    }
    printf("total bits = %lld\n", cost);
    return 0;
}
