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
string str;

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> str;
   int res = 0, cur = 0, sign = 1;
   for(int i = 0; i < str.length(); i++){
      if(str[i] <= '9'&& str[i] >= '0'){
         cur *= 10;
         cur += (str[i] - '0');
      } else {
         res += cur * sign;
         cur = 0;
      }
      if(str[i] == '-'){
         sign = -1;
      }
   }
   res += cur*sign;
   cout << res << '\n';
}
