#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
// used for ensure the mul of some number is in range of 10^18 before modulus.
typedef __int128 i128;
typedef pair<ll,ll> pll;


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

vector<ll> twomul(vector<ll> v1, vector<ll> v2){
    ll a = v1[0], b = v1[1];
    ll c = v2[0], d = v2[1];
    vector<ll> res(4);
    res[0] = a*c + b*d;
    res[1] = a*d - b*c;
    return res;
}

vector<ll> lag_mul(vector<ll> v1, vector<ll> v2){
    ll a = v1[0], b = v1[1], c = v1[2], d = v1[3];
    ll x = v2[0], y = v2[1], z = v2[2], w = v2[3];
    vector<ll> res(4);
    res[0] = abs(a*x + b*y + c*z + d*w);
    res[1] = abs(a*y - b*x - c*w + d*z);
    res[2] = abs(a*z + b*w - c*x - d*y); 
    res[3] = abs(a*w - b*z + c*y - d*x);
    return res;
}

map<ll,vector<ll>> mm;

bool isSquare(ll inp){
    return (ll)sqrt(inp) * (ll)sqrt(inp) == inp;
}

int Lnum(ll inp, vector<ll>& factors, vector<ll>& factors_uniq){
    if(isSquare(inp)){
        return 1;
    }
    // case 2
    factors = factorize_help(inp);
    factors_uniq = vector<ll>(factors);
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
        return 2;
    }
    while(true){
        if(inp % 4 == 0){
            inp >>= 2;
        } else{
            break;
        }
    }
    if(inp % 8 != 7){
        return 3;
    }
    return 4;
}

vector<ll> SOE(ll n){
    vector<bool> notPrime(n+1);
    vector<ll> res;
    ll i = 2;
    for(; i*i <= n; i++){
        if(!notPrime[i]){
            ll t = 2*i;
            while(t < n){
                notPrime[t] = true;
                t += i;
            }
        }
        res.push_back(i);
    }
    for(; i <= n; i++){
        if(!notPrime[i]){
            res.push_back(i);
        }
    }
    return res;
}

vector<ll> primes;

ll find_qnr(ll p){
    ll k;
    for(ll q: primes){
        if(!isSquare(p%q)){
            // cout << q << '\n';
            k = powmod(q,(p-1)/4,p); // q^(4p-1) % p;
            if(k*k%p == p-1 || k*k%p == -1)
                return k;
        }
    }
    while(true){
        ll q = rand() % (p-primes.back()) + primes.back();
        if(!isSquare(p%q) && prime_check_ML(q)){
            k = powmod(q,(p-1)/4,p); // q^(4p-1) % p;
            if(k*k%p == p-1 || k*k%p == -1)
                return k;
        }
    }
}

vector<ll> euclidian_for_fermat(ll a, ll b){
    // cout << a << " " << b << '\n';
    ll rootp = (ll)sqrt(a);
    if(isSquare(a)) rootp++;

    ll c;
    vector<ll> res(4);
    int cnt = 0;
    while(cnt < 2){
        // cout << a << " " << b << " " << rootp <<'\n';
        if(b > a) swap(a,b);
        c = a % b;
        if(c <= rootp){
            cnt++;
            if(cnt == 1) res[0] = c;
            if(cnt == 2) res[1] = c;
        }
        a = b; b = c;
    }
    return res;
}

vector<ll> fermat_twosum(ll p){ // p should be prime of 4p+1;
    if(mm.count(p) != 0) return mm[p];
    // ll qnr, k;
    // ll qnr = find_qnr(p); // quadratic non residue
    // ll k = powmod(qnr,(p-1)/4,p); // q^(4p-1) % p;
    ll k = find_qnr(p);
    return mm[p] = euclidian_for_fermat(p,k);
}

vector<ll> onesum(ll p){
    if(mm.count(p) != 0) return mm[p];
    vector<ll> res = {(ll)sqrt(p),0,0,0};
    return mm[p] = res;
}

vector<ll> twosum(ll p){
    if(mm.count(p) != 0) return mm[p];
    if(p % 4 == 1 && prime_check_ML(p)){
        return fermat_twosum(p);
    }
    // int s = 0;
    // while((p & 1) == 0){
    //     p >>= 1;
    //     s++;
    // }
    vector<ll> res = {1,0,0,0};
    for(ll i = 1; i* i <= p; i++){
        if(isSquare(p-i*i)){
            // cout << i << " " << sqrt(p-i*i) << '\n';
            if(i > (ll)sqrt(p-i*i)){
                res[0] = i;
                res[1] = (ll)sqrt(p-i*i);
            } else {
                res[0] = (ll)sqrt(p-i*i);
                res[1] = i;
            }
            break;
        }
    }
    // vector<ll> v2 = {1,1,0,0};
    // while(s --> 0)
    //     res = twomul(res,v2);
    return mm[p] = res;
}
vector<ll> autocalc(ll p, int lsum);

vector<ll> threesum(ll p){
    if(mm.count(p) != 0) return mm[p];
    ll z = 0;
    vector<ll> res;
    while(z++ < (ll)sqrt(p)){
        ll cur = p - z*z;
        // cout << cur << " " << z << '\n';

        if(cur % 4 == 1 && prime_check_ML(cur)){
            res = fermat_twosum(cur);
            res[3] = z;
            return mm[p] = res;
        }
    }
    z = 0;
    while(z++ < (ll)sqrt(p)){
        ll cur = p - z*z;
        vector<ll> v1,v1u;
        int lnum = Lnum(cur,v1,v1u);
        if(lnum <= 2){
            res = autocalc(cur,lnum);
            sort(all(res),greater<long long>());
            res[lnum] = z;
            return mm[p] = res;
        }
    }
}

vector<ll> autocalc(ll p, int lsum){
    if(mm.count(p) != 0) return mm[p];
    if(lsum == 1) return onesum(p);
    if(lsum == 2) return twosum(p);
    return threesum(p);
}
void res_print(vector<ll> v, int n);

vector<ll> foursum_prime(ll p){
    if(mm.count(p) != 0) return mm[p];
    vector<ll> res = {1,0,0,0};
    for(int i = 1; i*i < p; i++){
        vector<ll> f1, f1u, f2, f2u;
        int lnumi = Lnum(i,f1,f1u);
        if(lnumi != 4){
            int lnumir = Lnum(p-i,f2,f2u);
            if(lnumir != 4){
                // res_print(autocalc(i,lnumi),lnumi);
                // res_print(autocalc(p-i,lnumir),lnumir);
                res = autocalc(i,lnumi);
                vector<ll> t = autocalc(p-i,lnumir);
                sort(all(t),greater<long long>());
                for(int i = lnumi; i < 4; i++){
                    res[i] = t[i-lnumi];
                }
                break;
            }
        }
    }
    return res;
}

vector<ll> foursum(ll m, vector<ll>& factors, vector<ll>& factors_uniq){
    if(mm.count(m) != 0) return mm[m];
    if(factors.empty()){
        factors = factorize_help(m);
        factors_uniq = vector<ll>(factors);
        factors_uniq.erase(unique(all(factors_uniq)),factors_uniq.end());
    }
    vector<ll> res = {1,0,0,0};
    for(auto div: factors){
        if(mm.count(div) != 0) res = lag_mul(res,mm[div]);
        else{
            res = lag_mul(res,foursum_prime(div));
        }
    }
    return res;
}

void res_print(vector<ll> v, int n){
    sort(all(v),greater<long long>());
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(ll inp = 1; inp < 100000; inp++){
    // ll inp; cin >> inp;
    vector<ll> factors;
    vector<ll> factors_uniq;

    int lnum = Lnum(inp, factors, factors_uniq);
    cout << lnum << '\n';
    // cout << inp << '\n';
    
    primes = SOE(100000);
    vector<ll> res;
    if(lnum != 2) continue;
    if(lnum == 1) {
        res = onesum(inp);
        res_print(onesum(inp),1);
    } else if (lnum == 2){
        res = twosum(inp);
        res_print(twosum(inp),2);
    } else if (lnum == 3){
        res = threesum(inp);
        res_print(threesum(inp),3);
    } else {
        res = foursum(inp,factors,factors_uniq);
        res_print(foursum(inp,factors,factors_uniq),4);
    }
    ll a = 0;
    for(auto k: res){
        a += k*k;
    }
    cout << a << '\n';
    if(a != inp) cout << inp << " failed\n";
    }
}