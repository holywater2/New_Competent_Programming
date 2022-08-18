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


int N, M;
int board[2187][2187];

int solve(int x, int y, int l, int std){
   if(l == 1)
      return (board[x][y] == std);
   int s = std;
   for(int i = x; i < x+l; i++){
      for(int j =y; j < y+l; j++){
         if(std != board[i][j]){
            std = -2;
            i = INF;
            j = INF;
         }
      }
   }
   if(std != -2) return 1;
   else{
      std = s;
      int res = 0;
      for(int i = 0; i < 9; i++){
         res += solve(x+((i/3)*l)/3, y+((i%3)*l)/3,l/3,std);
      }
      return res;
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
   cout << solve(0,0,N,-1) << '\n';
   cout << solve(0,0,N,0) << '\n';
   cout << solve(0,0,N,1) << '\n';
}
