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

int N;

string gen(string cur){
   string next(cur);
   if(cur[0] == '.'){
      next[0] = '-';
      return next;
   } else{
      for(int i = 0; i < cur.size(); i++){
         if(cur[i] == '-'){
            next[i] = '.';
            continue;
         }
         next[i] = '-';
         break;
      }   
   }
   return next;
}

// int pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048};

int main(){
   #ifdef LOCAL
      // freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int tc; cin >> tc; // 1 to 100
   for(int i = 1; i <= tc; i++){
      cin >> N;
      string code;
      cin >> code;
      cout << "Case #" << i << ":\n";
      // case 1
      char c = '.';
      if(code[0] == c){
         c = '-';
      }
      int k = (int)ceil(log2(N));
      string str(k,'.');
      for(int i = 0; i < N-1; i++){
         if(str == code){
            str = gen(str);
         }
         pf1(c + str);
         str = gen(str);
      }
   }
}
