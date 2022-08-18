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
int board[11][11];
int visited[11][11];

int N, M;

void mark(int y, int x, int sign){
   int l = 0;
   while(iR(0,y+l,N) && iR(0,x+l,N)){
      if(board[y+l][x+l] != 1){
         board[y+l][x+l] -= sign;
      }
      l++;
   }
   l = -1;
   while(iR(0,y+l,N) && iR(0,x+l,N)){
      if(board[y+l][x+l] != 1){
         board[y+l][x+l] -= sign;
      }
      l--;
   }
   l = 1;
   while(iR(0,y+l,N) && iR(0,x-l,N)){
      if(board[y+l][x-l] != 1){
         board[y+l][x-l] -= sign;
      }
      l++;
   }
   l = -1;
   while(iR(0,y+l,N) && iR(0,x-l,N)){
      if(board[y+l][x-l] != 1){
         board[y+l][x-l] -= sign;
      }
      l--;
   }
}


int DFS(int x, int y, int depth, int color){
   int res = depth;
   for(int i = x; i < N; i++){
      for(int j = 0; j <N; j++){
         if(i == x && j < y) j = y;
         if((i + j)%2 != color) continue;
         if((board[i][j] == 0)){
            // pf2(i,j);
            mark(i,j,1);
            res = max(DFS(i,j+1,depth+1,color),res);
            mark(i,j,-1);
         }
      }
   }
   return res;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         int cur;
         cin >> cur;
         board[i][j] = 1-cur; // 놓을 수 있으면 0, 아니면 1
      }
   }
   // pf2(DFS(0,0,0,0),DFS(0,1,0,1));
   cout << DFS(0,0,0,0) + DFS(0,1,0,1) << '\n';
}
