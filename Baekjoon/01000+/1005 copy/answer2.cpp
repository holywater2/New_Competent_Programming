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
int maxl[1001], cost[1001], pre[1001];

// bool visited[1001];
// vector<vector<int>> adj;
vector<vector<int>> suc;


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
      memset(pre,0,sizeof(pre));

      // memset(visited,0,sizeof(noneeded));
      cin >> N >> K;
      for(int i = 0; i < N; i++){
         cin >> cost[i];
      }
      suc = vector<vector<int>>(N,vector<int>(0));
      int from, to;
      for(int i = 0; i < K; i++){
         cin >> from >> to;
         suc[from-1].pb(to-1);
         pre[to-1]++;
      }
      // pf1(needed[3]);
      // pf1(needed[3][1]);

      int obj;
      cin >> obj;
      obj--;
      queue<int> q;
      queue<int> val;
      for(int i = 0; i < N; i++){
         if(pre[i] == 0){
            q.push(i);
            val.push(0);
         }
      }
      while(!q.empty()){
         int cur = q.front();
         int pval = val.front();
         q.pop();
         val.pop();
         // if(cur == obj){
         //    cout << maxl[cur] + cost[cur] << '\n';
         //    break;
         // }
         auto it = suc[cur].begin();
         while(it != suc[cur].end()){
            int next = *it;
            pre[next]--;
            maxl[next] = max(maxl[next],cost[cur]+maxl[cur]);
            if(pre[next] <= 0){
               q.push(next);
               val.push(maxl[cur]);
            }
            it++;
         }
      }
   }
}
