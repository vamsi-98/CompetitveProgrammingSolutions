// Fub0ki
// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long             ll;
typedef long double           ld;
typedef vector<int>           vi;
typedef vector<ll>            vll;
typedef pair<int, int>        ii;
typedef pair<int, ii>         iii;
typedef vector<ii>            vii;
typedef set<int>              si;
typedef map<string, int>      msi;
typedef map<string, string>   mss;
#define re return
#define clr(x,v) memset(x,v,sizeof(x))
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define bn begin()
#define nd end()
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define NumofDigits(n) ((int)log10(n)+1)
#define sc1(x)  scanf("%d",&x)
#define sc2(x,y)  scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sz         size()
#define rep(i,v) for (int i = 0; i < v.sz; i++)
#define lp(i, a, b) for (int i = int(a); i < int(b); i++)
#define lpi(i, b, a) for (int i = int(b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-10
#define MAX 1000005
#define INF 1e18
int MOD = 1e9 + 7;
const double PI = acos(-1.0);
#define print_prec(ans,num) cout << fixed << setprecision(num) << (ans) << endl
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL)
const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

ll GCD(ll a, ll b) { re((!b) ? a : GCD(b, a%b)); }
ll LCM(ll a, ll b) { re a / (GCD(a, b))*b; }
ll nCr(ll n, ll r) { if (n<r)re 0; if (r == 0)re 1; re n*nCr(n - 1, r - 1) / r; }
ll PowMod(ll bs, ll ex, ll M) { if (!ex)re 1; ll p = PowMod((bs*bs) % M, ex >> 1, M); re(ex & 1) ? (p*bs) % M : p; }
ll ModInverse(ll a) { re PowMod(a, MOD - 2, MOD); }
ll ExtGCD(ll a, ll b, ll& x, ll& y) { if (!b) { x = 1; y = 0; re a; } ll r = ExtGCD(b, a%b, y, x); y -= a / b*x; re r; }
ll mult(ll a, ll b) { re(1LL * a * b) % MOD; }
bool isPrime(ll n) { if (n == 2)re 1; if (n<2 || n % 2 == 0)re 0; for (ll i = 3; i*i <= n; i += 2)if (n%i == 0)re 0; re 1; }
bool isPalindrome(string str) { ll l = 0; ll h = str.sz - 1; while (h > l) { if (str[l++] != str[h--]) { re 0; } } re 1; }
//#Of Even=(R-L+1)-odd(L,R)
ll NoOfOdd(ll L, ll R) { ll N = (R - L) / 2; if (R % 2 != 0 || L % 2 != 0)N++; re N; }
bool isPerfectSquare(ld x) { ld sr = sqrt(x); re((sr - floor(sr)) == 0); }
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistic*/
/*max_element(all(m),
    [](const ii& p1, const ii& p2) {
        return p1.second < p2.second; });*/
const int N = 600;
int rank1[N], pos[N], in[N], topo[N];
int g[N][N];
int t,n,m;
void solve()
{
	queue<int> q;
	lp(i,0,n) if (!in[i]) q.push(i);
	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		topo[cnt++] = cur;
		lp(i,0,n)
		{
			if (g[cur][i])
			{
				in[i]--;
				if (!in[i]) q.push(i);
			}
		}
	}
	if (cnt == n)
	{
		lp(i,0,n - 1)
		{
			std::cout << topo[i]+1 << " ";
		}
		std::cout << topo[n-1]+1 << "\n";
	}
	else
	{
		std::cout << "IMPOSSIBLE" << "\n";
	}
}


int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
	cin >> t;
	while (t--)
	{
		clr(in,0), clr(pos,0), clr(rank1,0), clr(g,0), clr(topo,0);
		cin >> n;
		lp(i,0,n)
		{
			cin >> rank1[i];
			rank1[i]--;
			pos[rank1[i]] = i;
		}
		lp(i,0,n)
		{
			lp(j,i+1,n)
			{
				g[rank1[i]][rank1[j]] = 1;
				in[rank1[j]]++;
			}
		}
		cin >> m;
		while (m--)
		{
			int x,y;
			cin >> x >> y;
			x--,y--;
			swap(g[x][y], g[y][x]);
			if (pos[x] < pos[y]) in[x]++, in[y]--;
			else in[x]--, in[y]++;
		}
		solve();
	}
    return 0;
}
