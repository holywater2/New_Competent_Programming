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

int N, M;
int board[128][128];

int solve(int x, int y, int l, int std){
   if(l == 1)
      return (board[x][y] == std);
   int s = std;
   for(int i = x; i < x+l; i++){
      for(int j =y; j < y+l; j++){
         if(std != board[i][j]){
            std = -1;
            i = 128;
            j = 128;
         }
      }
   }
   if(std != -1) return 1;
   else{
      std = s;
      return solve(x,y,l/2,std) + solve(x,y+l/2,l/2,std) + solve(x+l/2,y,l/2,std) + solve(x+l/2,y+l/2,l/2,std);
   }
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
         cin >> board[i][j];
      }
   }
   cout << solve(0,0,N,0) << '\n';
   cout << solve(0,0,N,1) << '\n';
}
