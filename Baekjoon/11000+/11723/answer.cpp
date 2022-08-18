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

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   set<int> s;
   while(N --> 0){
      string cmd; int num;
      cin >> cmd;
      if(cmd == "all"){
         for(int i = 1; i <= 20; i++)
            s.insert(i);
      } else if(cmd == "empty"){
         s.erase(all(s));
      } else {
         cin >> num;
         if(cmd == "add"){
            s.insert(num);
         } else if(cmd == "remove"){
            s.erase(num);
         } else if(cmd == "check"){
            pf1(s.count(num));
         } else if(cmd == "toggle"){
            if(s.count(num)){
               s.erase(num);
            } else {
               s.insert(num);
            }
         }
      }
   }
}
