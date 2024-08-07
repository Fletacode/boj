#include<bits/stdc++.h>

using namespace std;

vector<pair<int,char>> v;

int first_role(){

    int temp = v[0].first + 1;

    for (int i = 1; i < 5; i++){
        if (temp != v[i].first){
            return 0;
        }
        temp++;
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (v[i].second != v[j].second){
                return 0;
            }
        }
    }


    return v[v.size()-1].first + 900;

}

int second_role(){
    for (int i = 0; i < v.size(); i++){
        bool flag = true;
        int num = -1;
        for (int j = 0; j < v.size(); j++){
            if (j == i) continue;
            if (num == -1) num = v[j].first;
            else if (num != v[j].first){
                flag = false;
            }

        }

        if (flag) return 800 + v[0].first;

    }

    return 0;

}

int third_role(){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size(); j++){
            if (i == j ) continue;

            bool flag = true;
            

            if (v[i].first == v[j].first){
                int ans = v[j].first;
                int num = -1;
                for (int k = 0; k < v.size(); k++){
                    if (k == i || j == k) continue;

                    if (num == -1) num = v[k].first;
                    else if (num != v[k].first){
                        flag = false;
                    }


                }

                if (flag) return ans + (num*10) + 700;
            }

            

        }
    }

    return 0;
}

int four_role(){
    for (int i = 0; i < v.size()-1; i++){
        if (v[i].second != v[i+1].second){
            return 0;
        }
    }

    return 600 + v[v.size()-1].first;
}

int five_role(){

    int temp = v[0].first + 1;

    for (int i = 1; i < v.size(); i++){
        if (temp != v[i].first){
            return 0;
        }
        temp++;
    }

    return 500 + v[v.size()-1].first;

}

int six_role(){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size(); j++){
            if (i == j ) continue;

            bool flag = true;
            
        
            int num = -1;
            for (int k = 0; k < v.size(); k++){
                if (k == i || j == k) continue;

                if (num == -1) num = v[k].first;
                else if (num != v[k].first){
                    flag = false;
                }


            }

            if (flag) return 400 + num;
            

            

        }
    }

    return 0;
}

int seven_role(){

    int ans = 0;

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size(); j++){
            if (i == j ) continue;

            if (v[i].first == v[j].first){

                for (int k = 0; k  <v.size(); k++){
                    for (int o = 0; o < v.size(); o++){
                        if (k == o) continue;
                        if (k == i || k == j) continue;
                        if (o == j || o == i) continue;

                        if (v[k].first == v[o].first){
                            int temp = max(v[i].first, v[k].first) * 10 + 
                                min(v[i].first, v[k].first) + 300;
                            ans = max(ans, temp );
                        }

                    }
                }


            }
        
        }
    }



    return ans;
}

int eight_role(){

    int ans = 0;

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size(); j++){
            if (i == j) continue;
            if (v[i].first == v[j].first){
                ans = max(ans, 200 + v[i].first);
            }
        }
    }

    return ans;

}

int nine_role(){

    return v[v.size()-1].first + 100;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char c;
    int n;

    for (int i = 0; i < 5; i++){
        cin >> c >> n;
        v.push_back({n,c});
    }

    sort(v.begin(), v.end());

    int ans = 0;

    if (first_role()){
        ans = max(ans, first_role());
    }else if (second_role()){
        ans = max(ans, second_role());
    }else if (third_role()){
        ans = max(ans, third_role());
    }else if (four_role()){
        ans = max(ans, four_role());
    }else if (five_role()){
        ans = max(ans, five_role());
    }else if (six_role()){
        ans = max(ans, six_role());
    }else if (seven_role()){
        ans = max(seven_role(), ans);
    }else if (eight_role()){
        ans = max(eight_role(), ans);
    }else{
        ans = max(ans, nine_role());
    }


    cout << ans;


}