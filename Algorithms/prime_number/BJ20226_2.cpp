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

void helper(ll cur,ll pos, vector<ll> factors_uniq, vector<ll> nums, vector<ll>& div){
    int sz = factors_uniq.size();
    if(pos == sz){
        div.push_back(cur);
        return;
    }
    for(int j = 0; j <= nums[pos]; j++){
        helper(cur,pos+1,factors_uniq,nums,div);
        cur *= factors_uniq[pos];
    }
}

ll divsum(ll cur, vector<ll> div){
    ll rmin = cur+2; int count = 0;
    if(prime_check_ML(cur)) return 1 + cur;
    else{
        auto idx = upper_bound(all(div),sqrt(cur));
        for(auto i = idx; i != div.end(); i++){
            if(cur % *i == 0){
                if(rmin == -1) rmin = cur/(*i) + *i;
                rmin = min(rmin, cur/(*i) + *i);
                count++;
            }
            if(count == 3) break;
        }
        for(auto i = idx; i != div.begin(); i--){
            if(cur % *i == 0){
                if(rmin == -1) rmin = cur/(*i) + *i;
                rmin = min(rmin, cur/(*i) + *i);
                count++;
            }
            if(count == 6) break;
        }
    }
    return rmin;
}

ll solve(ll n, vector<ll> factors, vector<ll> factors_uniq){
    if(factors.size() == 1 || factors.size() == 0) return n + 1 + 1;
    vector<ll> nums;
    // ll res =1;
    for(auto a : factors_uniq){
        int num = upper_bound(all(factors),a)-lower_bound(all(factors),a);
        nums.push_back(num);
        // res *= num+1;
    }
    // cout << res << '\n';
    vector<ll> divs;
    helper(1,0,factors_uniq,nums,divs);
    // cout << divs.size() << '\n';
    sort(all(divs));
    ll rmin = divs[1] + divsum(n/divs[1],divs);
    // for(auto d: divs){
    //     if(d == 1) continue;
    //     rmin = min(rmin, d + divsum(n/d,divs));
    //     // cout << d << ' ' << rmin << '\n';
    // }
    for (int i = 0; i < divs.size(); i++) {
		auto it = lower_bound(divs.begin(), divs.end(), sqrt(divs[i]));
		for (auto j = it - 3; j <= it + 3; j++) {
			if (j < divs.begin() || j >= divs.end()) continue;
			if (divs[i] % *j) continue;
			rmin = min(rmin, n / divs[i] + divs[i] / *j + *j);
		}
	}
    return rmin;
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
    // int t; cin >> t;
    while(true){
        ll inp; cin >> inp;
        if(inp == 0) break;
        vector<ll> factors = factorize_help(inp);
        vector<ll> factors_uniq(factors);
        factors_uniq.erase(unique(all(factors_uniq)),factors_uniq.end());
        cout << solve(inp, factors,factors_uniq) << '\n';
    }
}