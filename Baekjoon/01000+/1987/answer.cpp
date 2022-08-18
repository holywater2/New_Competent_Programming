#include<bits/stdc++.h>
#include<iomanip>

#define inR(a,x,b) (a <= x && x < b)
using namespace std;

typedef pair<int,int> pii;

int R, C;

int board[20][20];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bitsmask(int cur, int pos){
    if((cur >> pos) & 1) return 0;
    else{
        return (cur | (1<<pos));
    }
}

int dfs(int x, int y, int pos, int depth){
    int res = depth;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inR(0,nx,R) && inR(0,ny,C)){
            int bits = bitsmask(pos,board[nx][ny]);
            // cout << "here " << x << ' ' << y << ' ' << pos << '\n';
            // cout << nx << ' ' << ny << ' ' << bits << '\n';
            if(bits != 0){
                res = max(dfs(nx,ny,bits,depth+1),res);
            }
        }
    }
    return res;
}

queue<pii> q;
queue<pii> pt;

int bfs(){
    q.push({1,bitsmask(0,board[0][0])});
    pt.push({0,0});
    int rmax = 0;
    while(!q.empty()){
        pii cur = q.front();
        pii cpt = pt.front();
        q.pop();
        pt.pop();
      //   cout << cpt.first << ' ' << cpt.second << '\n';
      //   cout << cur.first << ' ' << cur.second << '\n';
        rmax = max(rmax,cur.first);
        for(int i = 0; i < 4; i++){
            int nx = cpt.first + dx[i];
            int ny = cpt.second + dy[i];
            if(inR(0,nx,R) && inR(0,ny,C)){
                int bits = bitsmask(cur.second,board[nx][ny]);
                if(bits != 0){
                    q.push({cur.first+1,bits});
                    pt.push({nx,ny});
                }
            }
        }
    }
    return rmax;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    string inp;
    for(int i = 0; i < R; i++){
        cin >> inp;
        for(int j = 0; j < C; j++){
            board[i][j] = inp.at(j)-'A';
        }
    }
    cout << dfs(0,0,bitsmask(0,board[0][0]),1) << '\n';
}