#define LOCAL

#include<bits/stdc++.h>

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

int N, M;

list<int> ls;

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N >> M;
   for(int i = 0; i < N; i++){
      ls.pb(i+1);
   }
   list<int>::iterator it = ls.begin();
   int cnt = 0;
   while(!ls.empty()){
      if(it == ls.end()){
         it = ls.begin();
      }
      int j = 0;
      if(!cnt++){
         cout << "<";
      } else {
         cout << ", ";
      }
      for(;j<M-1;j++){
         it++;
         if(it==ls.end()){
            it = ls.begin();
         }
      }
      cout << *it;
      it = ls.erase(it);
   }
   cout << ">\n";
}
