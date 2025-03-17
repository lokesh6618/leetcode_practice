#include <bits/stdc++.h>

using namespace std;

string removeStars(string s) {
    string result = "";

    for(auto item : s){
        if(result.size() > 0 && item == '*'){
            result.pop_back();
        }else if(item != '*'){
            result.push_back(item);
        }
    }

    return result;
}

int main()
{   
    string s = "leet**cod*e";

    auto result = removeStars(s);

    cout << result << endl;
    cout << "done testing" << endl;
    
    return 0;
}