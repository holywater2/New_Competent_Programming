#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << endl;
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   
#define inb(A,x,dx,B) (x+dx >= A && x+dx < B)

typedef unsigned long long ull;

using namespace std;

typedef pair<int,int> pii;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int L, R;
queue<pii> qq;
bool checked[1500][1500];
bool checked2[1500][1500];
vector<string> v;

int BFS1(int cx,int cy, int rx, int ry){
   int res = 0;

   queue<pii> wq;
   queue<pii> nwq;
   for(int i = 0; i < L; i++)
   for(int j = 0; j < R; j++){
      if(!checked2[i][j] && v[i][j] == '.'){
         wq.push(pii(i,j));
         checked2[i][j] = true;
         while(!wq.empty()){
            pii t = wq.front();
            wq.pop();
            int x = t.first, y = t.second;

            for(int i = 0; i < 4; i++){
               if(inb(0,x,dx[i],L) && inb(0,y,dy[i],R)){
                  int nx = x+dx[i], ny = y+dy[i];
                  if(v[nx][ny] == 'X' && !checked2[nx][ny]){
                     nwq.push(pii(nx,ny));
                     checked2[nx][ny] = true;
                  }else if(v[nx][ny] == '.' && !checked2[nx][ny]){
                     wq.push(pii(nx,ny));
                     checked2[nx][ny] = true;
                  }
               }
            }
         }
      }
   }
   wq = queue<pii>(nwq);

   queue<pii> q;
   q.push(pii(cx,cy));
   checked[cx][cy] = true;

   while(true){
      queue<pii> nq;
      while(!q.empty()){
         pii t = q.front();
         q.pop();
         int x = t.first, y = t.second;
         // pf2(x,y);
         if(x == rx && y == ry) return res;

         for(int i = 0; i < 4; i++){
            if(inb(0,x,dx[i],L) && inb(0,y,dy[i],R)){
               int nx = x+dx[i], ny = y+dy[i];
               if(v[nx][ny] == '.' && !checked[nx][ny]){
                  q.push(pii(nx,ny));
                  checked[nx][ny] = true;
               } else if(v[nx][ny] == 'X' && !checked[nx][ny]){
                  nq.push(pii(nx,ny));
                  checked[nx][ny] = true; // 무조건 다음 날 얼음이 깨짐
               }
            }
         }
      }
      q = queue<pii>(nq);
      nwq = queue<pii>();
      // cout << "Break\n";
      while(!wq.empty()){
         pii t = wq.front();
         wq.pop();
         int x = t.first, y = t.second;
         v[x][y] = '.';
         // pf2(x,y);

         for(int i = 0; i < 4; i++){
            if(inb(0,x,dx[i],L) && inb(0,y,dy[i],R)){
               int nx = x+dx[i], ny = y+dy[i];
               if(v[nx][ny] == 'X' && !checked2[nx][ny]){
                  nwq.push(pii(nx,ny));
                  checked2[nx][ny] = true;
               }
            }
         }
      }
      wq = queue<pii>(nwq);
      res++;
   }
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
      freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> L >> R;
   v = vector<string>(L," ");
   vector<pii> swan;
   for(int i = 0; i < L; i++){
      cin >> v[i];
      for(int j = 0; j < R; j++){
         if(v[i][j] == 'L'){
            v[i][j] = '.';
            swan.pb(pii(i,j));
         }
      }
   }
   cout << BFS1(swan[0].first,swan[0].second,swan[1].first,swan[1].second) << '\n';
}
