#include <bits/stdc++.h>

// 单独求解欧拉函数
int Phi(int X) {
    int Res = X;
    for (int i = 2; i <= int(sqrt(X)); ++i) {
        if (!(X % i)) {
            Res = Res / i * (i - 1);
            while (!(X % i)) {
                X /= i;
            }
        }
    }
    if (X > 1) {
        Res = Res / X * (X - 1);
    }
    return Res;
}
