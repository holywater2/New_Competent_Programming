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
bool visited[101][101];
int num[101][101];

int DFS(int str, int fin, int depth){
   int res = -1;
   for(int i = 0; i < N; i++){
      if(!visited[str][i] && num[str][i] > 0){
         pf2(str,i);
         visited[str][i] = true;
         visited[i][str] = true;
         num[str][i] += depth;
         num[i][str] += depth;
         int temp = DFS(i,depth+1);
      }
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
   int str,fin;
   cin >> str >> fin;
   cin >> M;
   for(int i = 0; i < M; i++){
      int x, y;
      cin >> x >> y;
      num[x][y] = 1;
      num[y][x] = 1;
   }
   DFS(str,0);
   cout << num[str][fin] << '\n';
}
