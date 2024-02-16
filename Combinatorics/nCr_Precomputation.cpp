//headers 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using lld = long double;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void _print(vector<ll> &arr){for(auto &x:arr)cout<<x<<" ";cout<<endl;}

/*--------------------------------------------------------------------------------------------------------------------------*/

// O(N) : precomputation
// O(1) : each nCr query
ll combination(ll n, ll r, ll m, vector<ll> &fact, vector<ll> &ifact){
    // O(1)
    return mod_mul(fact[n], mod_mul(ifact[n-r], ifact[r], m), m);
}
void solve(){
    ll N = 1e6; 
    ll m = MOD;
    vector<ll> fact(N+1);
    vector<ll> ifact(N+1);
    fact[0] = 1;
    for(ll i = 1; i<=N; i++){
        fact[i] = mod_mul(i, fact[i-1], m);
    }
    // ifact[n] = fact[n] ^ (m-2)
    ifact[N] = expo(fact[N], m-2, m);
    for(ll i = N-1; i>=0; i--){
        ifact[i] = mod_mul(i+1, ifact[i+1], m);
    }

    cout<<combination(10, 3, m, fact, ifact)<<endl;
}
 
signed main() {
    fastio();
    solve();
}