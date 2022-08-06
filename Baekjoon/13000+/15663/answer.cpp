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

int N, M;
int res[8];
vector<int> v;


void solve(int cnt = 0, int idx = 0){
   if(cnt == M){
      for(int i = 0; i < M; i++){
         cout << res[i] << ' ';
      }
      cout << '\n';
      return;
   }
   int prev = -1;
   for(int i = idx; i < N; i++){
      if(prev == v[i]) continue;
      prev = v[i];
      res[cnt] = v[i];
      solve(cnt+1, i);
   }
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   cin >> N >> M;
   v = vector<int>(N,0);
   for(int i = 0; i < N; i++)
      cin >> v[i];
   sort(all(v));
   solve();
}
