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

int N, M, K, X;

vector<vector<pii>> adj;
vector<int> dijk(int dep){
   vector<int> dist(N,INF);
   dist[dep] = 0;
   priority_queue<pii> pq;
   pq.push({0,dep});
   while(!pq.empty()){
      int cost = -pq.top().first;
      int here = pq.top().second;
      pq.pop();
      if(dist[here] < cost) continue;

      for(auto next : adj[here]){
         int nextDist = cost + next.second;
         int there = next.first;

         if(nextDist < dist[there]){
            dist[there] = nextDist;
            pq.push({-nextDist,there});
         }
      }
   }
   return dist;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M >> K >> X;
   adj = vector<vector<pii>>(N);
   for(int i = 0; i < M; i++){
      int dep,dst;
      cin >> dep >> dst;
      adj[dep-1].push_back({dst-1,1});
   }
   auto res = dijk(X-1);
   vector<int> r;
   for(int i = 0; i < N; i++){
      if(res[i] == K){
         r.push_back(i);
      }
   }
   if(r.empty()) cout << -1 << '\n';
   else{
      for(auto i: r){
         pf1(i+1);
      }
   }
}
