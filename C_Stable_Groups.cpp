#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// overload cout and return pair<A, B>
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// return generic container (vector, set, list) to output stream 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// debugging
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// generate random num
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng_seed(x) mt19937 rng(x)
// shortcuts
#define all(x) (x).begin(), (x).end()   // sort(all(a))

using ll = long long;
typedef long double ld;
const char nl = '\n';

long long n,m,l,k,x,a[200100],b[200030];
void solve(){
	cin>>n>>k>>x;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
 
	for(int i=1; i<n; i++)
	{
		if(a[i]-a[i-1]>x)
		{
			b[m++] = (a[i]-a[i-1]-1)/x;
		}
	}
	sort(b,b+m);
 
	for(;l<m && b[l]<=k;)
	{
		k -= b[l++];
	}
	cout<<m-l+1<<endl;


    // vector<int> gaps;  // to store the gaps between groups
    // for (int i = 1; i < n; ++i) {
    //     int gap = a[i] - a[i - 1];
    //     if (gap > x) {
    //         gaps.push_back(gap);
    //     }
    // }

    // sort(all(gaps));

    // int group_count = gaps.size() + 1;  // initial number of groups
    // for (int gap : gaps) {
    //     int needed_k = (gap + x - 1) / x - 1;  // Calculate required k to merge this gap
    //     if (k >= needed_k) {
    //         group_count--;
    //         k -= needed_k;
    //     } else {
    //         break;
    //     }
    // }

    // cout << group_count << nl;

    // int n, k, x; cin >> n >> k >> x;
    // vector<int> a(n);
    // for (int& x : a) cin >> x;
    // // 
    // sort(all(a));
    // // greedy getting groups, calculate distance with cur 
    // // if k, then, cur + x >= cur1 - x
    // // dbg_out(a);
    // int groups = 1;
    // int prev = a[0];
    // for (int i=1; i<n; i++){
    //     if (a[i] - prev > x){
    //         // use k, i - prev inside 
    //         if (k && a[i] - (prev + x) <= x)
    //             k--;
    //         else
    //             groups++;
    //     }
    //     prev = a[i];       
    // }
    // cout << groups << nl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int test = 0; cin >> test;
    solve();
    // while (test--) solve();
    return 0;
}

/*



*/