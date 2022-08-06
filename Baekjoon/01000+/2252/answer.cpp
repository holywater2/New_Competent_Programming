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

int N, M;
vector<vector<int>> suc;
int pre[32001];

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   suc = vector<vector<int>>(N,vector<int>(0));
   int from, to;
   for(int i = 0; i < M; i++){
      cin >> from >> to;
      pre[to-1]++;
      suc[from-1].pb(to-1);
   }
   queue<int> q;
   for(int i = 0; i < N; i++){
      if(pre[i] == 0){
         q.push(i);
         pre[i]--;
      }
   }
   while(!q.empty()){
      int cur = q.front();
      q.pop();
      cout << cur+1 << ' ';
      auto it = suc[cur].begin();
      while(it != suc[cur].end()){
         int next = *it;
         pre[next]--;
         if(pre[next] == 0){
            q.push(next);
         }
         it++;
      }

   }
   cout << '\n';
}
