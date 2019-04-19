// Fub0ki
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long             ll;
typedef vector<int>           vi;
typedef vector<ll>            vll;
typedef pair<int, int>        ii;
typedef vector<ii>            vii;
typedef set<int>              si;
typedef map<string, int>      msi;
typedef map<string, string>   mss;
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
#define NumofDigits(n) ((int)log10(n)+1)
#define sc1(x)  scanf("%d",&x)
#define sc2(x,y)  scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sz(v) (int)(v.size())
#define rep(i,v) for (int i = 0; i < sz(v); i++)
#define lp(i, a, b) for (int i = int(a); i < int(b); i++)
#define lpi(i, b, a) for (int i = int(b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define MAX 100005
#define INF 1e18
#define print_prec(ans,num) cout << fixed << setprecision(num) << (ans) << endl
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL)
const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistic*/
/*max_element(all(m),
    [](const ii& p1, const ii& p2) {
        return p1.second < p2.second; });*/
int n;
vi a;
int mem[101][3];
int MinDays(int day ,int lastDay) // lastday (1 gym) (0 contest) (2 free)
{
    if (day == n) return 0;

    int & ret = mem[day][lastDay];

    if(ret != -1)
        return ret;
    ret = 0;


    if (a[day] == 0) ret = (1 + MinDays(day + 1, 2));
    if (a[day] == 1)
    {
        if (lastDay != 0)  ret = MinDays(day+1, 0);
        else ret = (1 + MinDays(day+1, 2));
    }
    if (a[day] == 2)
    {
        if (lastDay != 1) ret = MinDays(day+1, 1);
        else ret = (1 + MinDays(day+1, 2));
    }
    if (a[day] == 3)
    {
        if (lastDay == 2)
        {
            ret = min(MinDays(day+1, 1), MinDays(day+1, 0));
        }
        else if (lastDay != 1)
        {
            ret = MinDays(day+1, 1);
        }
        else
        {
            ret = MinDays(day+1, 0);
        }
    }
    return ret;
}

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    clr(mem,-1);
    cout << MinDays(0,2) << "\n";


    return 0;
}
