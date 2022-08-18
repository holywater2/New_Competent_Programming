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

int N, M, X;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M >> X;
   vector<vector<pii>> adj(N);
   for(int i = 0; i < M; i++){
      int s,f,c;
      cin >> s >> f >> c;
      adj[s-1].push_back({f-1,c});
   }
   vector<int> dist_all(N);
   for(int i = 0; i < N; i++){
      int st = i;
      vector<int> dist(N,INF);
      dist[st] = 0;
      priority_queue<pii> pq;
      pq.push({0,st});
      while(!pq.empty()){
         int cost = -pq.top().first;
         int here = pq.top().second;
         pq.pop();
         if(dist[here] < cost) continue;
         for(auto next : adj[here]){
            int there = next.first;
            int dis = next.second + cost;
            if(dist[there] > dis){
               dist[there] = dis;
               pq.push({-dis,there});
            }
         }
      }
      if(i == X-1){
         for(int i = 0; i < N; i++){
            dist_all[i] += dist[i];
         }
      }else{
         dist_all[i] += dist[X-1];
      }
   }
   cout << *max_element(all(dist_all)) << '\n';
}
