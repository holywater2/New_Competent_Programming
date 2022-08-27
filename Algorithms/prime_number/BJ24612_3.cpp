#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<long,int> pli;

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
map<ll,int> compress_map;

int compress(ll n, vector<pli> primes){
    if(compress_map.count(n) != 0) return compress_map[n];
    int code = 0;
    int pos  = 1;
    for(int i = 0; i < primes.size(); i++){
        auto p = primes[i];
        ll cur = p.first , pow = cur;
        int cnt = 1;
        if(n % cur == 0){
            while(n % (pow * cur) == 0){
                pow *= cur;
                cnt++;
            }
            code +=  cnt * pos;
        }
        pos *= (p.second + 1);
    }
    return compress_map[n] = code;
}

int div_num(vector<ll> factors, vector<ll> factors_uniq, vector<pli>& primes){
    int res = 1;
    for(auto a : factors_uniq){
        int cnt = upper_bound(all(factors),a)-lower_bound(all(factors),a);
        primes.push_back({a,cnt});
        res *= cnt + 1;
    }
    return res;
}

vector<ll> cand_max(vector<ll> factors, vector<ll> factors_uniq){
    vector<ll> nums;
    nums.push_back(1);
    for(auto a : factors_uniq){
        int num = upper_bound(all(factors),a)-lower_bound(all(factors),a);
        ll pow = 1;
        for(int i = 0; i < num; i++){
            pow *= a;
        }
        nums.push_back(pow);
    }
    sort(all(nums));
    return nums;
}

map<ll,vector<int>> solve(vector<ll> vec, vector<ll> factors, vector<ll> factors_uniq, vector<ll> nums){
    map<ll,vector<int>> mm;
    for(ll num: nums)
        mm[num] = vector<int>();
    ll sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
        for(ll num: nums){
            if(sum % num == 0){
                mm[num].push_back(i+1);
            }
        }
    }
    return mm;
}

vector<ll> freq;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q; cin >> q;
    vector<ll> vec(q+1),vecsum(q+1), gcdvec(q+1);
    for(int i = 0; i < q; i++){
        cin >> vec[i];
        vecsum[i+1] = vecsum[i] + vec[i];
    }
    if(q == 1 && vec[0] == 1){
        int t; cin >> t;
        while(t-->0){
            ll inp; cin >> inp;
            if(inp == 1) cout << 0 << '\n';
            else cout << -1 << '\n';
        }
        return 0;
    }
    
    ll tot = vecsum[q];
    for(int i = 0; i < q; i++){
        gcdvec[i+1] = __gcd<ll>(tot,vecsum[i+1]);
    }
    
    vector<ll> factors = factorize_help(tot);
    vector<ll> factors_uniq(factors);
    factors_uniq.erase(unique(all(factors_uniq)),factors_uniq.end());
    vector<pli> primes;
    
    int div_n = div_num(factors,factors_uniq,primes);
    // cout << div_n << '\n';
    
    freq = vector<ll>(div_n);
    for(int i = 0; i < q; i++){
        // cout << gcdvec[i+1] << " " << compress(gcdvec[i+1],primes) << '\n';
        freq[compress(gcdvec[i+1],primes)]++;
    }

    int block = 1;
    for(int i = 0; i <= primes.size(); i++){
        for(int code = div_n-1; code >= 0; code--){
            if(code / block % (primes[i].second + 1) != 0){
                freq[code-block] += freq[code];
            }
        }
        block *= primes[i].second+1;
    }

    int t; cin >> t;
    while(t --> 0){
        ll inp; cin >> inp;
        if(inp != 1 && tot % inp !=0){
            cout << -1 << '\n';
            continue;
        }
        ll res = q + tot / inp - freq[compress(inp,primes)]*2;
        cout << res << '\n';
    }
}