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
int board[1001][1001];
bool visited[1001][1001];
int disjoint[1000*1000];
int sz[1000*1000];
bool dvisited[1000*1000];


int dcount = 1;

int getp(int node){
   if(disjoint[node] == node){
      return disjoint[node];
   }
   return disjoint[node] = getp(disjoint[node]);
}

void unite(int a, int b){
   int pa = getp(a);
   int pb = getp(b);
   if(sz[pb] > sz[pa]) swap(pa,pb);
   disjoint[pb] = disjoint[pa];
   sz[pa] += sz[pb];
}

void DFS(int y, int x){
   // pf3(y,x,board[y][x]);
   if(!visited[y][x]){
      visited[y][x] = true;
      int dir = board[y][x];
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      // pf2(ny,nx);

      unite(y*M+x, ny*M+nx);
      DFS(ny,nx);
   }
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   for(int i = 0; i < N; i++){
      string line;
      cin >> line;
      for(int j = 0; j < M; j++){
         char cur = line.at(j);
         int num;
         if(cur == 'U')
            num = 3;
         else if(cur == 'D')
            num = 2;
         else if(cur == 'L')
            num = 1;
         else
            num = 0;
         board[i][j] = num;
         disjoint[M*i + j] = M*i + j;
         sz[M*i + j] = 1;
      }
   }
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         DFS(i,j);
      }
   }
   int res = 0;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         int dnum = getp(M*i + j);
         // pf3(i,j,dnum);
         if(!dvisited[dnum]){
            dvisited[dnum] = true;
            res++;
         }
      }
   }
   cout << res << '\n';
}
