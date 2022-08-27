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

int solve(vector<ll> muls, vector<ll> factors, vector<bool>& visited, int pos){
    if(pos == muls.size()) return 1;
    int res = 0;
    for(int i = 0; i < muls.size(); i++){
        if(!visited[i]){
            if(muls[i] <= factors[pos]){
                visited[i] = true;
                res += solve(muls,factors,visited,pos+1);
                visited[i] = false;
            }
        }
    }
    return res;
}

ll factorial(ll k){
    ll res = 1;
    for(int i = 2; i <= k; i++){
        res = (i128)res * i;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--> 0){
    ll inp; cin >> inp;
    vector<ll> factors = factorize_help(inp);
    vector<ll> factors_uniq(factors);
    factors_uniq.erase(unique(all(factors_uniq)),factors_uniq.end());
    ll res = 1;
    vector<ll> muls;
    bool check = false;
    for(auto a: factors_uniq){
        ll k = upper_bound(all(factors),a) - lower_bound(all(factors),a) + 1;
        // cout << a << ' ' << k << '\n';
        muls.push_back(k);
        res *= k;
        if( k > 2 ) check = true;
    }
    ll out = 0;
    // case 1: 1, 2;
    if(inp == 1 || inp == 2 || inp == 4) out = 1;   
    // case 2: Infinite
    else if(check) out = -1;
    // case 3: prime or unique factor
    else if(factors_uniq.size() == 1) out = 1;
    // case 4: multiple factor
    else{
        // sort(all(muls));
        // vector<bool> visited(muls.size());
        // out = solve(muls,factors,visited,0);
        out = factorial(factors.size());
    }
    cout << out << '\n';
    // cout << res << '\n';
    }
}