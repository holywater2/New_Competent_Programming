#include<bits/stdc++.h>

using namespace std;

void print_vec_int(vector<int> pi) {
    for(int i = 0; i < pi.size(); i++){
        cout << i << " " << pi[i] << '\n';
    }
}

vector<int> pi_vec_gen(string s){
    vector<int> pi = vector<int>(s.size(),0);
    pi[0] = 0; int j = 0;
    for(int i = 1; i < s.size();i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> compare(string N, string M){
    vector<int> res;
    auto pi = pi_vec_gen(M);
    int n = (int)N.size(), m = (int)M.size(); 
    int j = 0;
    // i는 하나씩 앞으로 움직이는 건 고정
    for(int i = 0; i < n; i++){
        // Case 1: N[i] != M[j] -> j = pi[j-1];이 되면 됨
        // 근데 j = 0, 그니까 매칭 하기도 전에 틀리면 skip
        while(j > 0 && N[i] != M[j]){
            j = pi[j-1];
        }
        if(N[i] == M[j]){
            if(j == m-1){
                // (2) 만약에 M을 N의 substring으로 찾아냈으면? -> 그걸 더해 줌
                res.push_back(i-j);
                j = pi[j];
            } else{
                // (1) N[i] == M[j]니까, 같으면 j도 한칸 옮김
                j++;
            }
        }
        cout << i << ' ' << j << '\n';
    }
    return res;
}

int main(){
    string N, M;
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin,N);
    cin >> M;
    print_vec_int(pi_vec_gen(M));
    vector<int> res2 = compare(N,M);
    cout << res2.size() << '\n';
    for(int i = 0; i < res2.size(); i++){
        cout << res2[i]+1 << ' ';
    }
    cout << '\n';
}