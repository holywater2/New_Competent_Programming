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
    for(int i = 0; i < n; i++){
        while(j > 0 && N[i] != M[j]){
            j = pi[j-1];
        }
        if(N[i] == M[j]){
            if(j == m-1){
                res.push_back(i-j);
                j = pi[j];
            } else{
                j++;
            }
        }
    }
    return res;
}

int main(){
    string N, M;
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin,N);
    getline(cin,M);
    vector<int> res2 = compare(N,M);
    cout << res2.size() << '\n';
    for(int i = 0; i < res2.size(); i++){
        cout << res2[i]+1 << ' ';
    }
    cout << '\n';
}