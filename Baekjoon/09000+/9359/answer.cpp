#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a
#define pf1(a)      cout << a << '\n'
#define pf2(a,b)    cout << a << ' ' << b << '\n'
#define pf3(a,b,c)  cout << a << ' ' << b << ' ' << c << '\n'
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF         987654321
#define MAX         (1e9+1)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

ll A[100],B[100], N[100];
vector<bool> primes_check;
vector<ll> primes;


vector<ll> prime_factor(int n){
   vector<ll> res;
   for(auto p: primes){
      if(p > n) break;
      if(n % p == 0){
         res.push_back(p);
         while(n % p == 0)
            n /= p;
      }
   }
   if(n != 1)
      res.push_back(n);
   return res;
}

ll recursive(vector<ll>& factors, int pos, ll cur ,ll bound){
   if(pos == factors.size() || factors[pos] * cur > bound) return 0;
   ll res = (bound/factors[pos]) / cur;
   res += recursive(factors,pos+1,cur,bound);
   res -= recursive(factors,pos+1,factors[pos]*cur,bound);
   return res;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int T; cin >> T;
   ll limit = floor(sqrt((double)MAX))+1;
   // pf1(limit);
   primes_check = vector<bool>(limit);
   for(ll i = 2; i*i <= MAX; i++){
      if(!primes_check[i]){
         primes.push_back(i);
         ll next = i*2;
         while(next < limit){
            primes_check[next] = true;
            next += i;
         }
      }
   }

   for(int i = 0; i < T; i++){
      ll res = 0;
      cin >> A[i] >> B[i] >> N[i];
      auto factors = prime_factor(N[i]);
      // for(auto f : factors)
      //    pf1(f);
      ll ans = recursive(factors,0,1,B[i]) - recursive(factors,0,1,A[i]-1);
      // pf2(recursive(factors,0,1,B[i]),recursive(factors,0,1,A[i]-1));
      cout << "Case #" << i+1 <<": " << B[i]-A[i]+1-ans << '\n';
   }
}
