#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
using namespace std;
#define F first
#define S second

map<char, pair<int, int>> letra(char t[5][5]){
    map<char, pair<int, int>> d;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            d[t[i][j]] = {i, j};
        }
    }
    return d;
}

int dist(pair<int, int> a, pair<int, int> b){
   return max(abs(a.first - b.first), abs(a.second - b.second));
} 

int menordist(pair<int, int> lh, pair<int, int> rh, string word, map<char, pair<int, int>> pos){
    size_t n = word.length();
    vector<string> comb;
    vector<int> distancias;

    for(int i = 0; i < (1 << n); i++){
        comb.push_back(bitset<10000>(i).to_string().substr(10000 - n));
    }

    pair <int, int> lhoriginal = lh;
    pair <int, int> rhoriginal = rh;

    for(size_t i = 0; i < comb.size(); i++){
        lh = lhoriginal;
        rh = rhoriginal;
        int distancia = 0;
        for(size_t j = 0; j < n; j++){
            char l = word[j];
            if(comb[i][j] == '0'){
                distancia += dist(lh, pos[l])+1;
                lh = pos[l];
            }
            else{
                distancia += dist(rh, pos[l])+1;
                rh = pos[l];
            }
            
        }
        distancias.push_back(distancia);
    }

    auto it = min_element(distancias.begin(), distancias.end());
    
    for(int i=0; i < distancias.size(); ++i)
        cout << distancias[i] << ' ' << comb[i] << endl;
    cout << endl;
    
    return *it;
}

int main(){
    char tab[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> tab[i][j];
        }
    }
    char l, r;
    cin >> l >> r;
    string s;
    cin >> s;

    map<char, pair<int, int>> pos;
    pos = letra(tab);

    pair<int, int> lh = pos[l];
    pair<int, int> rh = pos[r];

    cout << lh.F << ' ' << lh.S << endl;
    cout << rh.F << ' ' << rh.S << endl;

    cout << menordist(lh, rh, s, pos);
}