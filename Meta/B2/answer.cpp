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

int R, C;
short mm[3000][3000];

bool cnt(int x, int y){
   int cnt = 0;
   for(int j = 0; j < 4; j++){
      int nx = x + dx[j];
      int ny = y + dy[j];
      if(iR(0,nx,R) && iR(0,ny,C)){
         if(mm[nx][ny] < 2){
            cnt++;
         }
      }
   }
   return cnt > 1;
}

bool bfs(queue<pii> q){
   while(!q.empty()){
      auto cur = q.front();
      q.pop();
      for(int i = 0; i < 4; i++){
         int nx = cur.first + dx[i];
         int ny = cur.second + dy[i];
         if(iR(0,nx,R) && iR(0,ny,C)){
            if(mm[nx][ny] < 2 && !cnt(nx,ny)){
               if(mm[nx][ny] == 1){
                  return false;
               } else {
                  mm[nx][ny] = 3;
                  q.push({nx,ny});
               }
            }
         }
      }
   }
   return true;
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int tc; cin >> tc; // 1 to 85
   for(int i = 1; i <= tc; i++){
      cin >> R >> C;
      bool exist = false;
      queue<pii> q;
      for(int i = 0; i < R; i++){
         string temp;
         cin >> temp;
         if(temp.find("^") != string::npos) exist = true;
         for(int j = 0; j < C; j++){
            if(temp[j] == '#'){ // Rock
               mm[i][j] = 2;
               q.push({i,j});
            } else if(temp[j] == '^'){
               mm[i][j] = 1;
            } else {
               mm[i][j] = 0;
            }
         }
      }
      cout << "Case #" << i << ": ";
      if(!exist){
         cout << "Possible\n";
         for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
               if(mm[i][j] == 3){
                  cout << '.';
               } else if(mm[i][j] == 2){
                  cout << '#';
               } else {
                  cout << '.';
               }
            }
            cout << '\n';
         }
         continue;         
      }

      if((R == 1 || C == 1)){
         cout << "Impossible\n";
         continue;
      }
      if(!bfs(q)){
         cout << "Impossible\n";
      } else {
         cout << "Possible\n";
         for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
               if(mm[i][j] == 3){
                  cout << '.';
               } else if(mm[i][j] == 2){
                  cout << '#';
               } else {
                  cout << '^';
               }
            }
            cout << '\n';
         }
      }
   }
}
