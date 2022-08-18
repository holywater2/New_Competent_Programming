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
   string ansl[] = {"yes","no"};
   while(true){
      string cur;
      while(true){
         string temp;
         getline(cin,temp);
         cur.append(temp);
         if(temp.back() == '.') break;
      }
      if(cur.at(0) == '.'){
         break;
      }
      int ans = 0;
      stack<int> st;
      for(int i = 0; i < cur.size(); i++){
         if(cur[i] == '['){
            st.push(1);
         } else if(cur[i] == '('){
            st.push(2);
         } else if(cur[i] == ']'){
            if(st.empty()){
               ans = 1;
               break;
            }
            if(1 != st.top()){
               ans = 1;
               break;
            }
            st.pop();
         } else if(cur[i] == ')'){
            if(st.empty()){
               ans = 1;
               break;
            }
            if(2 != st.top()){
               ans = 1;
               break;
            }
            st.pop();
         }
      }
      if(!st.empty()) ans = 1;
      cout << ansl[ans] << '\n';
   }
}
