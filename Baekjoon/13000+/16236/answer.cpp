#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pf3(a,b,c)  cout << a << ' ' << b << ' ' << c << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define inb(a,x,b) (x < b && a <= x)
#define INF 987654321   

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;

int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};

int N, M;

int board[20][20];
int visited[20][20];
int remain = 2;


int bfs(int size, int y, int x){
   queue<pii> q;
   queue<int> qt;
   memset(&visited,-1,sizeof(visited));
   
   q.push(pii(y,x));
   visited[y][x] = 0;
   qt.push(0);
   int time  = 0;
   int nnx = N,nny =N;
   int nsize = size;
   while(!q.empty()){
      int cy = q.front().first;
      int cx = q.front().second;
      int t = qt.front();
      q.pop();
      qt.pop();
      if(time != 0 && t >= time){
         continue;
      }
      for(int s = 0; s < 4; s++){
         int ny = cy + dy[s];
         int nx = cx + dx[s];
         // pf2(ny,nx);
         if(inb(0,ny,N) && inb(0,nx,N)){
            if((board[ny][nx] == 0 || board[ny][nx] == size) && visited[ny][nx] == -1){
               visited[ny][nx] = 0;
               q.push(pii(ny,nx));
               qt.push(t+1);
            } else if(board[ny][nx] < size && board[ny][nx] > 0){
               time = t+1;
               if(ny < nny){
                  nnx = nx;
                  nny = ny;
               } else if(ny == nny && nx < nnx){
                  nnx = nx;
                  nny = ny;
               }
            }
         }
      }
   }
   if(time == 0) return 0;

   remain--;
   if(remain == 0){
      nsize++;
      remain = nsize;
   }
   board[nny][nnx] = 0;
   return time + bfs(nsize,nny,nnx);

}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   int cx,cy;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         cin >> board[i][j];
         if(board[i][j] == 9){
            cy = i;
            cx = j;
            board[i][j] = 0;
         }
      }
   }
   cout << bfs(2,cy,cx) << '\n';
}
