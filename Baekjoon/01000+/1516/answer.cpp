#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

using namespace std;

typedef unsigned long long ull;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int TC, N,K;
int gmax = 0;
int maxl[1001];
int cost[1001];
// bool visited[1001];
// vector<vector<int>> adj;
vector<vector<int>> needed;


int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> TC;
   for(; TC > 0; TC--){
      memset(maxl,0,sizeof(maxl));
      // memset(visited,0,sizeof(noneeded));
      gmax = -1;
      cin >> N >> K;
      for(int i = 0; i < N; i++){
         cin >> cost[i];
      }
      needed = vector<vector<int>>(N+1,vector<int>(0));
      int from, to;
      for(int i = 0; i < K; i++){
         cin >> from >> to;
         needed[to-1].pb(from-1);
      }
      // pf1(needed[3]);
      // pf1(needed[3][1]);

      int obj;
      cin >> obj;
      queue<int> q;
      queue<int> val;
      q.push(obj-1);
      val.push(0);
      while(!q.empty()){
         int cur = q.front();
         int pval = val.front();
         q.pop();
         val.pop();
         
         maxl[cur] = max(maxl[cur],cost[cur]+pval);
         // pf2(cur,maxl[cur]);
         gmax = max(gmax,maxl[cur]);
         auto it = needed[cur].begin();
         while(it != needed[cur].end()){
            q.push(*it);
            val.push(maxl[cur]);
            it++;
         }
         needed[cur].erase(all(needed[cur]));
      }
      cout << gmax << '\n';
   }
}
