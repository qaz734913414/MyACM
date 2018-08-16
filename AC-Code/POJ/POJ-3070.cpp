#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e4;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
	Finish_read = 0;
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		if (ch == EOF) {
			return;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= f;
	Finish_read = 1;
};

struct Matrix {
	ll mat[2][2];
	Matrix() {}
	Matrix operator * (Matrix const &a) const {
		Matrix res;
		mem(res.mat, 0);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2 ; ++k) {
					res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j] % mod) % mod;
				}
			}
		}
		return res;
	}
};

Matrix operator ^ (Matrix base, ll k) {
	Matrix res;
	mem(res.mat, 0);
	res.mat[0][0] = res.mat[1][1] = 1;
	while (k) {
		if (k & 1) {
			res = res * base;
		}
		base = base * base;
		k >>= 1;
	}
	return res;
}

ll Fib(ll x) {
	Matrix base;
	base.mat[0][0] = base.mat[1][0] = base.mat[0][1] = 1;
	base.mat[1][1] = 0;
	return (base ^ x).mat[0][1];
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll n;
	while (~scanf("%lld", &n) && n != -1) {
		printf("%lld\n", Fib(n));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
