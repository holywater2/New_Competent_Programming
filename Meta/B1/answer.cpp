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

int R, C;

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int tc; cin >> tc; // 1 to 85
   for(int i = 1; i <= tc; i++){
      cin >> R >> C;
      bool exist = false;
      for(int i = 0; i < R; i++){
         string temp;
         cin >> temp;
         if(temp.find("^") != string::npos) exist = true;
      }
      if((R == 1 || C == 1)){
         if(exist){
            cout << "Case #" << i << ": ";
            cout << "Impossible\n";
         } else {
            cout << "Case #" << i << ": ";
            cout << "Possible\n";
            for(int j = 0; j < R; j++){
               for(int k = 0; k < C; k++){
                  cout << ".";
               }
               cout << "\n";
            }
         }
      } else{
         cout << "Case #" << i << ": ";
         cout << "Possible\n";
         for(int j = 0; j < R; j++){
            for(int k = 0; k < C; k++){
               cout << "^";
            }
            cout << "\n";
         }
      }
   }

}
