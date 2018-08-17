#include <bits/stdc++.h>
const int maxn = 3;

long long Catalan[maxn];

// 递推求卡特兰数
// Catalan[0]=Catalan[1]=1
// Catalan[n]=Catalan[n-1]*(4*n-2)/(n+1)
void CalalanInit() {
    memset(Catalan, 0, sizeof(Catalan));
    Catalan[0] = Catalan[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        Catalan[i] = Catalan[i - 1] * (4 * i - 2) / (i + 1);
    }
}
