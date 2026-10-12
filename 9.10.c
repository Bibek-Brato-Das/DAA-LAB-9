#include <stdio.h>
#include <string.h>
char s[10][200], t[10][200];
int n, L[10], ovm[10][10], best;
int ov(char *a, char *b){                 // longest suffix of a that is a prefix of b
    int la = strlen(a), lb = strlen(b), k = la < lb ? la : lb;
    for(; k>0; k--) if(strncmp(a+la-k, b, k) == 0) return k;
    return 0;
}
void perm(int last, int cnt, int len, int used){   // exact: try all orders
    int j;
    if(cnt == n){ if(len < best) best = len; return; }
    for(j=0; j<n; j++)
        if(((used >> j) & 1) == 0)
            perm(j, cnt+1, len + L[j] - (cnt ? ovm[last][j] : 0), used | (1 << j));
}
int greedy(int m){                        // works on t[]
    int i, j, bi = 0, bj = 1, bo, o;
    while(m > 1){
        bo = -1;
        for(i=0; i<m; i++) for(j=0; j<m; j++) if(i != j){
            o = ov(t[i], t[j]);
            if(o > bo){ bo = o; bi = i; bj = j; }
        }
        strcat(t[bi], t[bj] + bo);        // merge j into i
        if(bj != m-1) strcpy(t[bj], t[m-1]);
        m--;
    }
    return strlen(t[0]);
}
int main(){
    int i, j, m, ok, g;
    char u[10][200];
    scanf("%d", &m);
    for(i=0; i<m; i++) scanf("%s", u[i]);
    n = 0;
    for(i=0; i<m; i++){                   // drop substrings and duplicates
        ok = 1;
        for(j=0; j<m; j++)
            if(i != j && strstr(u[j], u[i]) && (strlen(u[j]) > strlen(u[i]) || j < i)) ok = 0;
        if(ok) strcpy(s[n++], u[i]);
    }
    for(i=0; i<n; i++){
        L[i] = strlen(s[i]); strcpy(t[i], s[i]);
        for(j=0; j<n; j++) if(i != j) ovm[i][j] = ov(s[i], s[j]);
    }
    best = 1000000000; perm(0, 0, 0, 0);
    g = greedy(n);
    printf("greedy length  = %d\noptimal length = %d\nratio = %.3f\n", g, best, (double)g/best);
    return 0;
}
