#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321
#define cons 1000000   

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

ull N, M;
// int cons = 1000000;
bool ls[cons+1];

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
      // freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   ull res = M-N+1;
   // pf1(res);
   for(ull i = 2; i*i <= M; i++){
      ull sq = i*i;
      ull j = N/sq;
      if(j*sq < N) j+=1;
      for(; j*sq <= M && j*sq >= N; j++){
         if(!ls[j*sq-N]){
            ls[j*sq-N] = true;
            res -= 1;
         }
      }
   }
   pf1(res);
}
