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
int num[7];
int ddiv[] = {1,1,10,100,1000,10000,100000,1000000};

int ndigit(int num, int n){
   return (num/ddiv[n]) % 10;
}

   queue<pii> q;


int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   int temp = N, pos = 0;
   while(temp > 0){
      temp /= 10;
      pos++;
   }
   int gmax = -1;
   q.push({N,0});
   map<int, bool> visited;
   int level = 0;
   while(!q.empty()){
      auto cur = q.front();
      int cnum = cur.first;
      if(cur.second > level){
         visited.clear();
         level = cur.second;
      }
      q.pop();
      for(int i = 1; i <= pos; i++){
         for(int j = i+1; j <= pos; j++){
            if(j == pos && ndigit(cnum,i) == 0) continue;
            int newnum = cnum-ndigit(cnum,j)*ddiv[j] - ndigit(cnum,i)*ddiv[i];
            newnum += ndigit(cnum,j)*ddiv[i] + ndigit(cnum,i)*ddiv[j];
            if(cur.second == M-1){
               gmax = max(gmax,newnum);
            } else{
               if(visited.find(newnum) == visited.end()){
                  q.push({newnum,cur.second+1});
                  visited[newnum] = true;
                  // pf2(newnum,cur.second+1);
               }
            }
         }
      }
   }
   cout << gmax << '\n';
}
