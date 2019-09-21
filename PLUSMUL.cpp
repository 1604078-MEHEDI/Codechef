///https://www.codechef.com/problems/PLUSMUL
///https://discuss.codechef.com/t/how-to-solve-the-question-plusmul-from-snackdown-elimination-round/14843/2
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll Mod = 1e9 + 7;
ll dp[maxn];
ll g[maxn];
ll h[maxn];

int main()
{
	FASTIO
	///*
	//double start_time = clock();
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
//*/
	int T;
	cin >> T;
	//T = 1;
	for (int cs = 1; cs <= T; cs++) {
		int n;
		cin >> n;
		ll a[n + 2];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++) {
			dp[i] = h[i] = g[i] = 0;
		}

		dp[0] = g[0] = h[0] = a[0];
		ll pw2 = 1;
		for (int i = 1; i <= n; i++) {
			h[i] = (h[i - 1] * a[i] + pw2 * a[i]) % Mod;
			dp[i] = (g[i - 1] + h[i]) % Mod;
			g[i] = (g[i - 1] + dp[i]) % Mod;
			pw2 = (pw2 * 2) % Mod;
			dbg4(h[i], dp[i], g[i], pw2);
		}
		cout << dp[n - 1] << endl;
	}

	//double end_time = clock();
	//printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
	return 0;
}
