#define LOCAL

#include <iostream>
#include <vector>
#include <string>  
#include <queue>
#include <algorithm>
#include <cstring>  // memset(a,0,sizeof(a));

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h) 
#define all(v)      v.begin(),v.end()
#define INF 987654321   

typedef unsigned long long ull;

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, M, cmp;

int main(){
   #ifdef LOCAL
      freopen("data/data2.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
      freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   vector<int> v = vector<int>(N,0);
   for(int i = 0; i < N; i++)
      cin >> v[i];
   cin >> cmp;
   for(int i = 0; i< N; i++){
      if(v[i] == cmp) M++;
   }
   cout << M << '\n';
}
