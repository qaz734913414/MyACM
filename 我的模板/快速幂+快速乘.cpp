#include <bits/stdc++.h>

// 快速乘求A*B%M
long long QuickMul(long long A, long long B, long long M) {
    long long Res = 0;
    while (B) {
        if (B & 1) {
            Res = (Res + A) % M;
        }
        A = (A + A) % M;
        B >>= 1;
    }
    return Res;
}

// 快速幂求A^B%M
long long QuickPow(long long A, long long B, long long M) {
    long long Res = 0;
    while (B) {
        if (B & 1) {
            Res = QuickMul(Res, A, M) % M;
        }
        A = QuickMul(A, A, M) % M;
        B >>= 1;
    }
    return Res;
}
