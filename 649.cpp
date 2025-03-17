#include <bits/stdc++.h>

using namespace std;

string predictPartyVictory(string senate) {
    int n = senate.length();

    queue<int> r_index, d_index;

    for(int i = 0; i < n; i++){
        if(senate[i] == 'R'){
            r_index.push(i);
        }else{
            d_index.push(i);
        }
    }

    while(r_index.empty() || d_index.empty()){
        int r_first = r_index.front();
        int d_first = d_index.front();
        r_index.pop();
        d_index.pop();

        if(r_first < d_first){
            r_index.push(r_first + n);
        }else{
            d_index.push(d_first + n);
        }
    }

    return r_index.empty() ? "Dire" : "Radiant";
}

int main()
{   
    string senate = "DRRDRD";

    cout << predictPartyVictory(senate) << endl;
    cout << "done testing" << endl;
    return 0;
}


// vector<pair<char,bool>> current_status;
// current_status.push_back({senate[0], true});

// for(int i = 1; i < senate.length(); i++){
//     auto& last_element = current_status.back();
//     cout << last_element.first << " " ;
//     if(last_element.first == senate[i]){
//         cout << "first : " << senate[i] << endl;
//         current_status.push_back({senate[i], true});
//     }else{
//         cout << "Second : " << senate[i] << endl;

//         if(last_element.second){
//             last_element.second = false;
//         }else{
//             current_status.push_back({senate[i], true});
//         }
//     }
// }

// for(auto item : current_status){
//     cout << item.first << " : " << item.second << endl;
// }
