ll gcd(ll a, ll b) { return a?gcd(b%a, a):abs(b); }
ll lcm(ll x, ll y) { return (x&&y) ? abs(x) / gcd(x,y) * abs(y): 0; }
//(a*b) % mod => O(log b)
ll mulmod(ll a, ll b, ll mod) {
    if (b < 0) return mulmod(a, (b%mod + mod)%mod, mod);
    if (b == 0) return 0LL;
    ll ans = (2LL * mulmod(a, b/2, mod)) % mod;
    if (b%2 == 0) return ans;
    return (ans + a) % mod;
}


ll gcd_extended(ll a, ll b, ll &x, ll &y) {
    if (a == 0) { x = 0, y = 1; return b; }
    ll xx, yy, d = gcd_extended(b%a, a, xx, yy);
    x = yy-(b/a)*xx, y=xx;
    if (d < 0) {d = -d; x = -x; y = -y; }

    return d;
}

//para td i, (0 <= i < k), x = a[i] ( mod m[i])
ll a[MAX], m[MAX];

bool chines_resto(ll &X, int k) {
    //Assume que k >= 1
    ll d, z, w, l = m[0];
    X = (a[0] % m[0] + m[0]) % m[0];
    for (int i = 1; i < k; i++) {
        a[i] %= m[i];
        d = gcd_extended(l, m[i], z, w);
    if ( (a[i]-X) % d != 0) return false;
        X += l*z*((a[i]-X)/d); //Pode usar mulmod(), pra nao estourar ll
        l = lcm(l, m[i]);
        X = ((X%l) + l) % l;
    }
    return true;
}

//Obtido do caderno da equipe I Am Root
