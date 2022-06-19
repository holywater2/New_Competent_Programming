#include <iostream>
#include <vector>
#include <string>  
#include <queue>
#include <algorithm>
#include <cstring>  // memset(a,0,sizeof(a));

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

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N;
    for(; N > 0; N /= 10){
        int temp = 1;
        for(int j = 0; j < 5; j++)
            temp *= (N%10);
        M += temp;
    }
    cout << M << '\n';
}
