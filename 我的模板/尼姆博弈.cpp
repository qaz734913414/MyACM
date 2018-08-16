#include <bits/stdc++.h>

// 尼姆博弈
bool Nim(std::vector<int> Num) {
    int ans = 0;
    for (int i = 0; i < int(Num.size()); ++i) {
        ans ^= Num[i];
    }
    // ans不为零则先手赢，否则为后手赢
    return ans != 0 ? true : false;
}
