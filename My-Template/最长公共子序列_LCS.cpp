#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

// dp[i][j]:Str1[1]~Str1[i]和Str2[1]~Str2[j]对应的公共子序列长度
int dp[maxn][maxn];

// 最长公共子序列(LCS)
void LCS(std::string Str1, std::string Str2) {
    int LenA = int(Str1.length()), LenB = int(Str2.length());
    for (int i = 0; i < LenA; ++i) {
        for (int j = 0; j < LenB; ++j) {
            if (Str1[i] == Str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
}
