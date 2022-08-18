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

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;
bool sieve[4000001];

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<int> prime;
   for(int i = 2 ; i <= N; i++){
      if(!sieve[i]) prime.pb(i);
      int num = i;
      while(num <= N){
         sieve[num] = true;
         num += i;
      }
   }
   if(N == 1){
      cout << 0 << '\n';
      return 0;
   }
   int n = 0, m = 0;
   int sum = 0;
   int ans = 0;
   while(m <= prime.size()){
      while(sum < N && m <= prime.size()){
         m++;
         sum += prime[m-1];
      }
      while(sum > N && n < m){
         sum -= prime[n];
         n++;
      }
      // pf3(sum,n,m);
      if(sum == N){
         ans += 1;
      }
      m++;
      if(m <= prime.size())
         sum += prime[m-1];
   }
   cout << ans << '\n';
}
