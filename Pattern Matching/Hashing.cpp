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
ll mminvprime(ll a, ll m){a = a % m; return expo(a, m-2, m);}

void _print(vector<ll> &arr){for(auto &x:arr)cout<<x<<" ";cout<<endl;}
/*--------------------------------------------------------------------------------------------------------------------------*/
struct Hashing {
    ll p = 30;
    ll m = 1e9 + 7;
    ll n; 
    vector<ll> hashes;
    vector<ll> powersOfP;
    vector<ll> inversePowersOfP;

    Hashing(string s){
        n = s.size();
        hashes.resize(n);
        fillPowersOfP();
        fillInversePowersOfP();
        prefixHashes(s);
    }

    void fillPowersOfP(){
        powersOfP.resize(n);
        powersOfP[0] = 1;
        for(ll i = 1; i<n; i++){
            powersOfP[i] = (powersOfP[i-1]*p)%m;
        }
    }

    void fillInversePowersOfP(){
        inversePowersOfP.resize(n);
        // let x = p^(n-1)
        // mminvprime(x, m) = mminvprime(x^(m-2), m)
        // mminvprime : multiplicative module inverse
        inversePowersOfP[n-1] = mminvprime(expo(p, n-1, m), m);
        for(ll i = n-2; i>=0; i--){
            inversePowersOfP[i] = (p*inversePowersOfP[i+1])%m;
        }
    }

    void prefixHashes(string &s){
        hashes.resize(n);
        ll currentHash = 0;
        for(ll i = 0; i<n; i++){
            ll charValue = s[i] - 'a' + 1;
            // hash(string + ch) = hash(string) + charvalue*(p^(string size))
            hashes[i] = (currentHash + charValue*powersOfP[i])%m;
            currentHash = hashes[i];
        }
    }

    ll substringHash(ll l, ll r){
        // returns the hash of the substring from l to r-1
        ll val1 = hashes[r];
        ll val2 = l > 0 ? hashes[l-1] : 0LL;

        return ((val1 - val2 + m)*inversePowersOfP[l])%m;
    }
};
void solve(){
    string s, p;
    cin>>s>>p;
    
    Hashing hs = Hashing(s);
    Hashing hp = Hashing(p);

    ll n = s.size(); ll m = p.size();
    ll count = 0;
    ll patternHash = hp.substringHash(0, m-1);
    for(ll i = 0; i<=n-m; i++){
        ll currStringHash = hs.substringHash(i, i+m-1);
        if(currStringHash == patternHash) {
            count++;
        }
    }
    cout<<count<<endl;
}
 
signed main() {
    fastio();
    solve();
}