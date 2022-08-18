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
int board[101][101];
int dist[101][101];
bool visited[101][101];


int N, M;

int w(int pos){
   return pos/N;
}

int h(int pos){
   return pos%N;
}
int zip(int x, int y){
   return x*N + y;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   string str; 
   getline(cin,str);
   for(int i = 0; i < M; i++){
      getline(cin,str);
      // pf1(str);
      for(int j = 0; j < N; j++){
         board[j][i] = str[j]-'0';
         dist[j][i] = INF;
      }
   }
   priority_queue<pair<int,pii>> pq;
   pq.push({0,{0,0}});
   int res = 0;
   dist[0][0] = 0;
   while(!pq.empty()){
      auto cost = -pq.top().first;
      auto pos  = pq.top().second;
      int x = pos.first;
      int y = pos.second;
      // pf3(x,y,cost);
      if((x == N-1) && (y == M-1)){
         res = cost;
         break;
      }
      pq.pop();
      if(dist[x][y] < cost) continue;

      for(int i = 0; i < 4; i++){
         int nx = x +dx[i];
         int ny = y +dy[i];
         // pf2(nx,ny);
         // pf3("T",iR(0,nx,N),iR(0,ny,M));
         if(iR(0,nx,N) && iR(0,ny,M)){
            if(dist[nx][ny] > cost + board[nx][ny]){
               dist[nx][ny] = cost + board[nx][ny];
               pq.push({-cost-board[nx][ny],{nx,ny}});
            }
         }
      }
   }
   cout << res << '\n';
}
