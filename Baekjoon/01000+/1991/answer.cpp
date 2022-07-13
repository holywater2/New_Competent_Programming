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

int N;
int TREE[26][2];

void post(int i){
   if(i == -1) return;
   cout << char('A' + i);
   post(TREE[i][0]);
   post(TREE[i][1]);
}

void pre(int i){
   if(i == -1) return;
   pre(TREE[i][0]);
   cout << char('A' + i);
   pre(TREE[i][1]);
}

void suffix(int i){
   if(i == -1) return;
   suffix(TREE[i][0]);
   suffix(TREE[i][1]);
   cout << char('A' + i);
}

int main(){
   #ifdef LOCAL
      freopen("data/data.txt", "r", stdin);
   //    freopen("data/input.txt", "r", stdin);
   //  freopen("data/output.txt", "w", stdout);
   #endif
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin >> N;
   char ch,ch1,ch2;
   for(int i = 0; i < N; i++){
      cin >> ch >> ch1 >> ch2;
      TREE[ch-'A'][0] = (ch1 == '.') ? -1 : ch1-'A';
      TREE[ch-'A'][1] = (ch2 == '.') ? -1 : ch2-'A';
   }
   post(0); cout << '\n';
   pre(0); cout << '\n';
   suffix(0); cout << '\n';
}
