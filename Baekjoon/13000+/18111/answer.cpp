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

int N, M, B;
int board[501][501];

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M >> B;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         cin >> board[i][j];
      }
   }
   int rmin = 987654321, hr = -1;
   for(int h = 0; h <= 256; h++){
      int cost = 0;
      int block_left = B;
      for(int i = 0; i < N; i++){
         for(int j = 0; j < M; j++){
            if(board[i][j] > h){
               cost += (board[i][j]-h)*2;
               block_left += (board[i][j]-h);
            } else if(board[i][j] < h){
               cost += (h-board[i][j]);
               block_left -= (h-board[i][j]);
            }
         }
      }
      if(block_left >= 0){
         if(rmin >= cost){
            rmin = cost;
            if(h > hr){
               hr = h;
            }
         }
      }
   }
   cout << rmin << " " << hr << '\n';

}
