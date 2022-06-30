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

typedef pair<int,int> pii;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M;
bool ch[100000];
vector<vector<pii>> g;

pii DFS(int s, int gmax){
   int max = 0;
   int node = s;
   ch[s] = true;
   for(int i = 0; i < g[s].size(); i++){
      int adj = g[s][i].first;
      if(ch[adj] == false){
         pii t = DFS(adj,gmax);
         if(max < t.second+g[s][i].second){
            node = t.first;
            max = t.second+g[s][i].second;
         }
      }
   }
   return pii(node,max+gmax);
}

pii DFS_start(int s){
   memset(ch,0,N*sizeof(ch[0]));
   return DFS(s,0);
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
      // freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   g = vector<vector<pii>> (N,vector<pii>());
   int t,k,w;
   for(int i = 0; i < N; i++){
      cin >> t;
      while(true){
         cin >> k;
         if(k == -1) break;
         else{
            cin >> w;
            g[t-1].pb(pii(k-1,w));
         }
      }
   }
   cout << DFS_start(DFS(0,0).first).second << '\n';
}
