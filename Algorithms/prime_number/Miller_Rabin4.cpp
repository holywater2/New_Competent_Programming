#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
// used for ensure the mul of some number is in range of 10^18 before modulus.
typedef __int128 i128;


/*
Miller rabin prime check- O(k(log n)^3)
,where k is the number of checking list of a
and n is the number being checked.
*/

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
    // cout << s << ' ' << d << '\n';
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

map<ll,ll> euler_phi;

ll euler_phi_f(ll n){
    if(n == 1) return 1;
    if(euler_phi.count(n) != 0) return euler_phi[n];
    vector<ll> factors = factorize_help(n);
    vector<ll> factors_uniq(factors);
    factors_uniq.erase(unique(all(factors_uniq)),factors_uniq.end());
    ll res = n;
    for(auto a: factors_uniq){
        res = (i128)res * (a-1) / a;
    }
    euler_phi[n] = res;
    return res;
}

vector<ll> lag_mul(vector<ll> v1, vector<ll> v2){
    ll a = v1[0], b = v1[1], c = v1[2], d = v1[3];
    ll x = v2[0], y = v2[1], z = v2[2], w = v2[3];
    vector<ll> res(4);
    res[0] = a*x + b*y + c*z + d*w;
    res[1] = a*y - b*x - c*w + d*z;
    res[2] = a*z + b*w - c*x + d*y;
    res[3] = a*w + b*z - c*y - d*x;
    return res;
}

map<ll,vector<ll>> mm;

vector<ll> lagrange_square(ll m){
    if(mm.count(m) != 0) return mm[m];
    if(m == 1) {
        vector<ll> res = {1,0,0,0};
        return res;
    }
    if(m == 2){
        vector<ll> res = {1,1,0,0};
        return res;
    }
    if(prime_check_ML(m)){
        for(ll a = 1; a*a <= m-1; a++){
            ll cur = m-1-a*a;
            cout << cur << ' '<< a << '\n';
            if(cur == 0){
                vector<ll> res = {a,1,0,0};
                mm[m] = res;
                return res;
            }
            if((ll)sqrt(cur)*(ll)sqrt(cur) == cur){
                vector<ll> res = {a,(ll)sqrt(cur),1,0};
                mm[m] = res;
                return res;
            }
        }
    }
    vector<ll> res = {1,0,0,0};
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll inp; cin >> inp;
    if((ll)sqrt(inp)* (ll)sqrt(inp) == inp){
        cout << 1 << '\n';
        return 0;
    }
    vector<ll> factors = factorize_help(inp);
    vector<ll> factors_uniq(factors);
    factors_uniq.erase(unique(all(factors_uniq)),factors_uniq.end());
    int res1 = 0;
    for(auto a: factors_uniq){
        if(a%4 == 3){
            int temp = upper_bound(all(factors),a) - lower_bound(all(factors),a);
            if(temp%2 != 0){
                res1++;
                break;
            }
        }
    }
    if(res1 != 1){
        cout << 2 << '\n';
        return 0;
    }
    while(true){
        if(inp % 4 == 0){
            inp >>= 2;
        } else{
            break;
        }
    }
    if(inp % 8 != 7){
        cout << 3 << '\n';
        return 0;
    }
    cout << 4 << '\n';
}