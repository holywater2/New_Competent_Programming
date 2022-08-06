#define LOCAL

#include<bits/stdc++.h>

#define sf1(a)      cin  >> a;
#define pf1(a)      cout << a << '\n';
#define pf2(a,b)    cout << a << ' ' << b << '\n';
#define pb(a)       push_back(a)
#define iR(l,a,h)   (a >= l && a < h)
#define all(v)      v.begin(),v.end()
#define INF 987654321   

using namespace std;

typedef unsigned long long ull;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int TC, N,K;
int gmax = 0;
int maxl[1001];
int cost[1001];
// bool visited[1001];
// vector<vector<int>> adj;
vector<vector<int>> needed;
#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,string> pis;

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool visited[8];

int solver(int k, vector<vector<int>> &dungeons, int depth){
    int res = depth;
    int N = dungeons.size();
    for(int i = 0; i < N; i++){
        if(!visited[N]){
            int req = dungeons[i][0];
            int use = dungeons[i][1];
            if(k >= req){
                visited[N] = true;
                pf2(i,depth);
                pf2(use,req);
                pf2(k,k-use);
                int temp = solver(k-use,dungeons,depth+1);
                res = max(temp,res);
                visited[N] = false;
            }
        }
    }
    return res;
}

int solution(int k, vector<vector<int>> dungeons) {
    return solver(k,dungeons,0);
}

int main(){
   vector<vector<int>> vll;
   vector<int> v1;
   v1.pb(80);
   v1.pb(20);
   vector<int> v2;
   v2.pb(50);
   v2.pb(40);
   vector<int> v3;
   v3.pb(30);
   v3.pb(10);
   vll.pb(v1);
   vll.pb(v2);
   vll.pb(v3);

   cout << solution(80,vll) << '\n';
}
