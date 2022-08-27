#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef __int128 i128;
#define all(x) (x).begin(), (x).end()


namespace miller_rabin {
	ll mul(ll x, ll y, ll mod) { return (i128)x * y % mod; }
	ll _pow(ll x, ll y, ll p) {
		ll ret = 1, piv = x % p;
		while (y) {
			if (y & 1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(ll x, ll a) {
		if (x % a == 0) return 0;
		ll d = x - 1;
		while (1) {
			ll tmp = _pow(a, d, x);
			if (d & 1) return (tmp != 1 && tmp != x - 1);
			else if (tmp == x - 1) return 0;
			d >>= 1;
		}
	}
	bool isprime(ll x) {
		for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
			if (x == i) return 1;
			if (x > 40 && miller_rabin(x, i)) return 0;
		}
		if (x <= 40) return 0;
		return 1;
	}
}
namespace pollard_rho {
	void rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (miller_rabin::isprime(n)) {
			v.push_back(n);
			return;
		}
		ll a, b, c, g = n;
        auto f = [&](ll x) {
            return (c + miller_rabin::mul(x, x, n)) % n;
        };
        do {
            if (g == n) {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 20 + 1;
            }
            a = f(a);
            b = f(f(b));
            g = __gcd<long long>(abs(a - b), n);
        } while (g == 1);
		rec(g, v);
		rec(n / g, v);
	}
	vector<ll> factorize(ll n) {
		vector<ll> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
}

ll mul(ll x, ll y, ll mod){return (i128)x * y % mod;}

ll powmod(ll x, ll y, ll mod){
    ll res = 1, pow = x % mod;
    while(y > 0){
        if(y & 1) res = mul(res,pow,mod);
        pow = mul(pow,pow,mod);
        y >>= 1;
    }
    return res;
}

/*
 * checking a^{(2^s-1)*d}+1 , a^{(2^s-2)*d}+1, a^d+1 is whether 0 or
 * a^d-1 is 0. Return false when x is prime.
 */
bool check_composite(ll x, ll a, ll s, ll d){
    if(x == a) return false;
    ll cur = powmod(a,d,x);
    if(cur == 1 || cur == x-1) return false;
    for(int i = 1; i < s; i++){
        cur = mul(cur,cur,x);
        if(cur == x-1) return false;
    }
    return true;
}

bool prime_check_ML(ll x){
    if(x < 2) return false;
    ll d = x-1;
    int s = 0;
    while((d & 1) == 0){
        d >>= 1;
        s++;
    }
    for(int a: {2,3,5,7,11,13,17,19,21,23}){
        if(x == a) return true;
        if(check_composite(x,a,s,d)) return false;
    }
    return true;
}

/*
 * Pollard rho
 */

void factorize(ll n, vector<ll>& v){
    if(n == 1) return;
    if(n % 2 == 0){
        v.push_back(2);
        factorize(n / 2, v);
        return;
    }
    if(prime_check_ML(n)) {
        v.push_back(n);
        return;
    }
    ll x, y, c, g = n;
    auto f = [&](ll x){return (mul(x,x,n) + c) % n;};
    do {
        if(g == n){
            x = y = rand() % (n - 2) + 2;
            c = rand() % 20 + 1;
        }
        x = f(x);
        y = f(f(y));
        g = __gcd<ll>(abs(x-y),n);
    } while (g == 1);
    factorize(g, v);
    factorize(n / g, v);
}

vector<ll> factorize_help(ll n){
    vector<ll> ret;
    factorize(n, ret);
    sort(all(ret));
    return ret;
}

int main() {
	// fastio;
	// ll n; cin >> n;
    for(int i = 1; i < 100000000ll; i++){
        ll n = i;
        vector<long long> factor = pollard_rho::factorize(n);
        vector<long long> factor_unique(factor);
        factor_unique.erase(unique(factor_unique.begin(),factor_unique.end()),factor_unique.end());
        long long res = 1;
        for(auto a : factor_unique){
            res *= upper_bound(factor.begin(),factor.end(),a)-lower_bound(factor.begin(),factor.end(),a) + 1;
        }
        
        factor = factorize_help(n);
        factor_unique = vector<long long>(factor);
        factor_unique.erase(unique(factor_unique.begin(),factor_unique.end()),factor_unique.end());
        long long res2 = 1;
        for(auto a : factor_unique){
            res2 *= upper_bound(factor.begin(),factor.end(),a)-lower_bound(factor.begin(),factor.end(),a) + 1;
        }
        if(res != res2){
            cout << n << " " << res << " " << res2 <<'\n';
        }
    }
}
