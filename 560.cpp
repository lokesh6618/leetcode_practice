#include <bits/stdc++.h>

using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int first = 0;
    int second = 1;
    int count = 0;
    vector<int> preSums(nums.size(), 0);
    unordered_map<int, int> psMap;

    preSums[0] = nums[0];

    for(int i = 1; i < preSums.size(); i++){
        preSums[i] = preSums[i-1] + nums[i];
    }

    for(auto item : preSums){
        cout << item << " , ";
    }

    cout << endl;

    for(int j = 0; j < preSums.size(); j++){
        psMap[preSums[j]]++;
        
        if(preSums[j] == k){
            count++;
        }else{
            int val = preSums[j] - k;

            if(psMap.find(val) != psMap.end()){
                count += psMap.find(val)->second;
            }
        }
    }

    cout << "map" << endl;

    for(auto item : psMap){
        cout << item.first << " , " << item.second << endl;
    }

    return count;
}

int main()
{   
    vector<int> nums1 = {-1,-1,1};
    int k = 0;
    auto result = subarraySum(nums1, k);

    cout << result << endl;
    cout << "done testing" << endl;
    return 0;
}