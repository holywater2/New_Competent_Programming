#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   
#define inb(a,x,b) (x >= a && x < b)

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ax = -1, ay = -1, bx = -1, by = -1;
int R, L, T;

vector<vector<int>> diffuse(vector<vector<int>> board){
   vector<vector<int>> res = vector<vector<int>>(R,vector<int>(L,0));
   for(int i = 0; i < R; i++)
   for(int j = 0; j < L; j++)
      res[i][j] = 0;
   res[ax][ay] = -1;
   res[bx][by] = -1;

   for(int i = 0; i < R; i++)
   for(int j = 0; j < L; j++){
      if(board[i][j] == -1)
         continue;
      int sum = 0;
      for(int k = 0; k < 4; k++){
         int nx = i+dx[k], ny = j+dy[k];
         if(inb(0,nx,R) && inb(0,ny,L)){
            if(board[nx][ny] != -1){
               res[nx][ny] += board[i][j]/5;
               sum += board[i][j]/5;
            }
         }
      }
      res[i][j] += board[i][j]-sum;
   }
   return res;
}

void clean(vector<vector<int>> &board){
   int cx = ax, cy = ay;
   int nx = -1, ny=-1;
   while(true){
      // pf2(cx,cy);
      if(cx == ax && cy < L && cy > 0){
         nx = cx; ny = cy-1;
      } else if(cx == 0 && 0 <= cy && cy < L-1){
         nx = cx; ny = cy+1;
      } else if(cy == 0 && cx <= ax && cx > 0 ){
         nx = cx-1; ny = cy;
      } else {
         nx = cx+1; ny = cy;
      }
      board[cx][cy] = board[nx][ny];
      if(nx == ax && ny == ay){
         board[cx][cy] = 0;
         break;
      }
      cx = nx; cy = ny;
   }
   board[ax][ay] = -1;
   cx = bx, cy = by;
   nx = -1; ny = -1;
   while(true){
      // pf2(cx,cy);
      if(cx == bx && cy < L && cy > 0){
         nx = cx; ny = cy-1;
      } else if(cx == R-1 && 0 <= cy && cy < L-1){
         nx = cx; ny = cy+1;
      } else if(cy == 0 && cx < R-1 && cx >= bx ){
         nx = cx+1; ny = cy;
      } else { 
         nx = cx-1; ny = cy;
      }
      board[cx][cy] = board[nx][ny];
      if(nx == bx && ny == by){
         board[cx][cy] = 0;
         break;
      }
      cx = nx; cy = ny;
   }
   board[bx][by] = -1;
}




int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> R >> L >> T;
   vector<vector<int>> board = vector<vector<int>>(R,vector<int>(L,0));

   for(int i = 0; i < R; i++)
   for(int j = 0; j < L; j++){
      cin >> board[i][j];
      if(board[i][j] == -1){
         if(ax == -1){
            ax = i; ay = j;
         } else {
            bx = i; by = j;
         }
      }
   }
   
   for(int i = 0; i < T; i++){
      board = diffuse(board);
      clean(board);
   }
   int res = 0;
   for(int i = 0; i < R; i++){
   for(int j = 0; j < L; j++){
      res += board[i][j];
      // cout << board[i][j] << ' ';
   }
   // cout << '\n';
   }
   cout << res+2 << '\n';

}
