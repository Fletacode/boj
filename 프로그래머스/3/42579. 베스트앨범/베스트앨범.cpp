#include <bits/stdc++.h>

using namespace std;

vector<pair<int, string>> total_v;
map<string,int> total_m;
map<string, vector<pair<int,int> > > m; //cnt,idx

void make_total(vector<string> &genres, vector<int> &plays) {
    
    for (int i = 0; i < genres.size(); i++){
        total_m[genres[i]] += plays[i];
        //vector<pair<int,int>> temp;
        //m[genres[i]] = temp;
    }
    
    int idx = 0;
    
    for (int i = 0; i < genres.size(); i++){
        m[genres[i]].push_back({plays[i],idx++});
    }
    
    for (auto iter = total_m.begin(); iter != total_m.end(); iter++) {
        total_v.push_back({(*iter).second,(*iter).first});
    }
    
} 

void sort_fun(){
    sort(total_v.begin(), total_v.end(), greater<>());
    
}

bool compare(pair<int,int> p1, pair<int,int> p2) {
    if (p1.first > p2.first) return true;
    else if (p1.first < p2.first) return false;
    else{
        if (p1.second < p2.second) return true;
        else {
            return false;
        }
    }
    
}

void sort_m_fun(){
    for (int i = 0; i < total_v.size(); i++){
        string key =  total_v[i].second;
        sort(m[key].begin(), m[key].end(),compare);
    }
}


void print_total_v(){
    for (int i = 0; i < total_v.size(); i++){
        cout << total_v[i].first << " " << total_v[i].second;
    }
}

void print_m(){
    for (auto iter = m.begin(); iter != m.end(); iter++){
        
        for(pair<int,int> i : (*iter).second) {
            cout << i.first << " " << i.second << " ";
        }
        cout << "\n";
    }
}

vector<int> get_ans(){
    vector<int> ans;
    
    
    for (int i = 0; i < total_v.size(); i++){
        string key =  total_v[i].second;
        if (m[key].size() == 1) {
            ans.push_back(m[key][0].second);
        } else {
            ans.push_back(m[key][0].second);
            ans.push_back(m[key][1].second);
        }
        
    }
    
    return ans;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    make_total(genres, plays);
   
    sort_fun();
    sort_m_fun();
    //print_total_v();
    
    //print_m();
    

    return get_ans();
}