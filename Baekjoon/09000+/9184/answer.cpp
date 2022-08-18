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
int dp[101][101][101];

int a, b, c;

int solve(int a, int b, int c){
   int& res = dp[a+50][b+50][c+50];
   // pf3(a,b,c);
   // pf1(res);
   if(res != 0) return res;
   if(a <= 0 | b <= 0 | c <= 0) return res = 1;
   if(a > 20 | b > 20 | c > 20) return res = solve(20,20,20);
   if(a < b & b < c) return res = solve(a,b,c-1) + solve(a,b-1,c-1) - solve(a, b-1, c);
   return res = solve(a-1,b,c) + solve(a-1,b-1,c) + solve(a-1,b,c-1) - solve(a-1,b-1,c-1);
}

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   while(true){
      cin >> a >> b >> c;
      if(a == -1 && b == -1 && c == -1){
         break;
      }
      cout << "w(" << a << ", " << b << ", " << c << ") = ";
      cout << solve(a,b,c) << '\n';
   }
}
