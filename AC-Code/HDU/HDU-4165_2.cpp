
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

// 卡特兰数列
/*
 * 数列递推式:
 * 令h(0)=1,h(1)=1(1).
 * h(n)= h(0)h(n-1)+h(1)h(n-2) + … + h(n-1)h(0) (n≥2)
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll Catalan[31];
    mem(Catalan, 0);
    Catalan[0] = 1;
    Catalan[1] = 1;
    for (int i = 2; i <= 30; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            Catalan[i] += Catalan[j] * Catalan[i - j - 1];
        }
    }
    int n;
    while (cin >> n, n) {
        cout << Catalan[n] << endl;
    }
    return 0;
}
