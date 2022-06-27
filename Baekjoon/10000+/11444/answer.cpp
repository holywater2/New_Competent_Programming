#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

ull N, M;

int mod = 1000000007;

map<ull,vector<ull>> mm;

vector<ull> vecmul(vector<ull> v1, vector<ull> v2){
   ull arr[] = {v1[0]*v2[0]+v1[1]*v2[2],v1[0]*v2[1]+v1[1]*v2[3],v1[2]*v2[0]+v1[3]*v2[2],v1[2]*v2[1]+v1[3]*v2[3]};
   vector<ull> res(arr,arr+4);
   for(int i = 0; i < 4;i++){
      res[i] %= mod;
   }
   return res;
}

vector<ull> solve(ull N){
   if(mm.find(N) != mm.end()) return mm[N];
   vector<ull> res(4,0);
   if(N == 0){
      res[0] = 1; res[3] = 1;
      return res;
   } else if(N == 1){
      res[0] = 1, res[1] = 1; res[2] = 1; res[3] = 0;
      return res;
   }
   res = vecmul(solve(N/2),solve(N/2));
   if(N%2 == 1){
      res = vecmul(res,solve(1));
   }
   mm[N] = res;
   return res;
}

// a2 1 1 a1
// a1 1 0 a0
// a b e f -> ae + bg, af + bh
// c d g h -> ce + dg, cg + dh

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
      // freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   if(N == 1){
      cout << 1 <<'\n';
   } else{
      auto res = solve(N-1);
      // pf2(res[0],res[1]);
      // pf2(res[2],res[3]);
      cout << res[0]%mod << '\n';
   }
}
