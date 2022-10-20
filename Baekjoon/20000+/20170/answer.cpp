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
   vector<int> v1(6), v2(6);
   for(int i = 0; i < 6; i++){
      cin >> v1[i];
   }
   for(int i = 0; i < 6; i++){
      cin >> v2[i];
   }
   sort(all(v1));
   sort(all(v2));
   int cnt = 0;
   for(int i = 0; i < 6; i++)
      for(int j = 0; j < 6; j++){
         if(v1[i] > v2[j]) cnt++;
      }
   int denom = 36;
   if(cnt % 2 == 0){
      cnt /= 2;
      denom /= 2;
   }
   if(cnt % 2 == 0){
      cnt /= 2;
      denom /= 2;
   }
   if(cnt % 3 == 0){
      cnt /= 3;
      denom /= 3;
   }
   if(cnt % 3 == 0){
      cnt /= 3;
      denom /= 3;
   }
   cout << cnt << '/' << denom << '\n';
}
