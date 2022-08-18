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
int board[64][64];

void solve(int x, int y, int l){
   if(l == 1){
      cout << board[x][y];
      return;
   }
   bool check = true;
   int std = board[x][y];
   for(int i = x; i < x+l; i++){
      for(int j = y; j < y+l; j++){
         if(std != board[i][j]){
            check = false;
            break;
         }
      }
      if(!check) break;
   }
   if(check){
      cout << std;
      }
   else{
      cout << '(';
      solve(x,y,l/2);
      solve(x,y+l/2,l/2);
      solve(x+l/2,y,l/2);
      solve(x+l/2,y+l/2,l/2);
      cout << ')';
   }
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   string str;
   getline(cin,str);
   for(int i =0 ; i< N; i++){
      getline(cin,str);
      for(int j = 0; j < N; j++){
         board[i][j] = str[j]-'0';
      }
   }
   solve(0,0,N);
   cout << '\n';
}
