#include <bits/stdc++.h>

using namespace std;

void printVector(const vector<int>& nums){
	for(auto num : nums){
		cout << num << " , ";
	}

	cout << endl;
}

int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	printVector(nums);

	vector<int> preSum(n + 1, 0);
	preSum[1] = nums[0];


	for(int i = 1; i < n; i++){
		preSum[i+1] = preSum[i] + nums[i];
	}
	printVector(preSum);
	
	int i = 0;
	int j = n;

	int max_sum = 0;

	int actual_max = 0;

	int current_sum = 0;

	while(i<j){
		current_sum = preSum[j] - preSum[i];
		if(current_sum < max_sum){
			i++;
		}else{
			j--;
			max_sum = current_sum;
		}

		actual_max = max(actual_max, max_sum);

	}

	return actual_max;
}

int main()
{   
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums) << endl;
    cout << "done testing" << endl;
    return 0;
}