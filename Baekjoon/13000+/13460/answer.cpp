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
int board[10][10];
int rx,ry,bx,by,hx,hy;

int solve(){

}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   string str;
   for(int i = 0; i < N; i++){
      cin >> str;
      for(int j = 0; j < M; j++){
         if(str[j] == '#'){
            board[i][j] == 1;
         } else if(str[j] == 'O'){
            hx = i, hy = j;
         } else if(str[j] == 'R'){
            rx = i, ry = j;
         } else if(str[j] == 'B'){
            bx = i, by = j;
         }
      }
   }
   int res; 
   cout << N << '\n';

}
