#define LOCAL

#include <iostream>
#include <vector>
#include <string>  
#include <queue>
#include <algorithm>
#include <cstring>  // memset(a,0,sizeof(a));
#include <bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pf3(a,b,c)    cout << a << ' ' << b << ' ' << c << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

using namespace std;
typedef unsigned long long ull;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int disjoint[101];
int sz[101];
int N;

int getp(int node){
   if(disjoint[node] == node)
      return node;
   return disjoint[node] = getp(disjoint[node]);
}

void unite(int a, int b){
   int pa = getp(a);
   int pb = getp(b);
   if(sz[pb] > sz[pa]) swap(pa,pb);
   disjoint[pb] = pa;
   sz[pa] += sz[pb];
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<pdd> v;
   for(int i = 0; i < N; i++){
      double x,y;
      cin >> x >> y;
      v.push_back({x,y});
      disjoint[i] = i;
      sz[i] = 1;
   }
   priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
   for(int i = 0; i < N-1; i++){
      auto cur = v[i];
      for(int j = i+1; j < N; j++){
         auto next = v[j];
         auto dist = pow((cur.first-next.first)*(cur.first-next.first)+(cur.second-next.second)*(cur.second-next.second),0.5);
         pq.push({dist,i*N + j});
      }
   }
   double res = 0;
   while(!pq.empty()){
      auto cur = pq.top();
      pq.pop();
      int i = cur.second/N;
      int j = cur.second%N;
      // pf2(i,j);
      // pf1(cur.first);
      // pf3(disjoint[0],disjoint[1],disjoint[2]);
      if(getp(i) == getp(j)) continue;
      res += cur.first;
      unite(i,j);
   }
   cout << res << '\n';
}
