ll countDer(ll n, ll m){
    ll der[n+1] = {0};
    der[1] = 0;
    der[2] = 1;

    for(ll i = 3; i<=n; i++){
        der[i] = mod_mul(i-1, mod_add(der[i-1], der[i-2], m), m);
    }
    return der[n];
}
void solve(){
    ll n; cin>>n;
    cout<<countDer(n, MOD)<<endl;
}