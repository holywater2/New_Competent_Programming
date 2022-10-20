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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int N, M, K;
int grid[20][20];
pii grid_smell[20][20];
short shark[401][4][4];

int simulate(vector<pii>& shark_pos, int left){
   int ngrid[N][N];
   memset(ngrid,0,sizeof(ngrid));
   for(int i = M; i >= 1; i--){
      if(shark_pos[i].first == -1) continue;
      int dir = shark_pos[i].first;
      int x = shark_pos[i].second / N, y = shark_pos[i].second % N;
      bool success = false;
      for(int j = 0; j < 4; j++){
         if(success) break;
         int ndir = shark[i][dir][j];
         int nx = x + dx[ndir], ny = y + dy[ndir];
         // 다음 움직임 선택
         if(iR(0,nx,N) && iR(0,ny,N) && (grid_smell[nx][ny].first == 0)){
            shark_pos[i].first = ndir;
            shark_pos[i].second = nx*N + ny;
            // grid[x][y] = 0;
            if(ngrid[nx][ny] != 0){ // 쫓아냈어
               shark_pos[ngrid[nx][ny]].first = -1;
               left--;
            }
            ngrid[nx][ny] = i;
            grid_smell[x][y] = {i,K};
            success = true;
         }
      }
      if(!success){
         for(int j = 0; j < 4; j++){
            if(success) break;
            int ndir = shark[i][dir][j];
            int nx = x + dx[ndir], ny = y + dy[ndir];
            if(iR(0,nx,N) && iR(0,ny,N) && (grid_smell[nx][ny].first == i)){
               shark_pos[i].first = ndir;
               shark_pos[i].second = nx*N + ny;
               // grid[x][y] = 0;
               ngrid[nx][ny] = i;
               grid_smell[x][y] = {i,K};
               success = true;
            }
         }
      }
   }
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         grid[i][j] = ngrid[i][j];
         if(ngrid[i][j] != 0)
            grid_smell[i][j] = {ngrid[i][j],K+1};
         if(grid_smell[i][j].second != 0){
            grid_smell[i][j].second--;
            if(grid_smell[i][j].second == 0){
               grid_smell[i][j].first = 0;
            }
         }
      }
   }
   return left;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M >> K;
   vector<pii> shark_pos(M+1); // {shark_dir, shakr_pos};
   for(int i = 0; i < N; i++)
   for(int j = 0; j < N; j++){
      cin >> grid[i][j];
      if(grid[i][j] != 0){
         shark_pos[grid[i][j]] = {0,i*N+j};
      }
      grid_smell[i][j] = {0,0};
   }
   int inp;
   for(int i = 0; i < M; i++){
      cin >> inp;
      shark_pos[i+1].first = inp-1;
   }
   for(int i = 0; i < M; i++){
      for(int j = 0; j < 4; j++){
         for(int k = 0; k < 4; k++){
            // i: mth shark , j : 위 0 아래 1 왼쪽 2 오륵쪽 3
            cin >> shark[i+1][j][k];
            shark[i+1][j][k]--;
         }
      }
   }
   int left = M;
   int cnt = 0;
   while(left > 1 && cnt <= 1000){
      cnt++;
      if(cnt == 1001) break;
      left = simulate(shark_pos,left);
      // for(int i = 0; i < N; i++){
      //    for(int j = 0; j < N; j++){
      //       cout << grid[i][j];
      //    }cout << '\n';
      // }
      // pf1(left);
   }
   if(cnt >= 1001) cnt = -1;
   pf1(cnt);
}
