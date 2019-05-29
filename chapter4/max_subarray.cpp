// returns the continous sub array whose sum is max
#include <iostream>
#include <limits>
using namespace std;

struct sub_arr_parameters
{
	int l, r, sum;
};

sub_arr_parameters Find_crossing_array(int Array[], int mid, int l, int r){
	int i = mid;
	int sum = 0;
	int max_suml = numeric_limits<int>::lowest();
	int max_l = mid; 
	while(i != l-1){
		sum += Array[i];
		if(sum > max_suml){
			max_l = i;
			max_suml = sum;
		}
		i--;
	}

	i = mid + 1;
	sum = 0;
	int max_sumr = 0;
	if ( i != r){
		max_sumr = numeric_limits<int>::lowest();
	}
	int max_r = mid; 
	while(i != r){
		sum += Array[i];
		if(sum > max_sumr){
			max_r = i;
			max_sumr = sum;
		}
		i++;
	}

	sub_arr_parameters ans;
	ans.l = max_l;
	ans.r = max_r;
	ans.sum = max_sumr + max_suml;
	return ans;
}

// INVARIANT: The answer is either in the left half, right half or crossing the middle of the input subarray
sub_arr_parameters Find_sub_array(int Array[], int l, int r){
	sub_arr_parameters ans, a1, a2, a3;
	if(l == r){
		ans.l = l;
		ans.r = r;
		ans.sum = Array[l];
		return ans;
	}
	else{
		int mid = (l + r)/2;
		a1 = Find_sub_array(Array, l, mid);
		a2 = Find_sub_array(Array, mid+1, r);
		a3 = Find_crossing_array(Array, mid, l, r);

		if(a1.sum >= a2.sum && a1.sum >= a3.sum){
			return a1;
		}
		else if(a2.sum >= a3.sum && a2.sum >= a1.sum){
			return a2;
		}
		else{
			return a3;
		}
	}
}

int main(){
	int n;
	cout << "Array length: \n";
	cin >> n;
	int Array[n];
	cout << "Input array elements: ";
	for(int i = 0; i < n; i++){
		cin >> Array[i];
	}

	sub_arr_parameters ans = Find_sub_array(Array, 0, n);
	cout << "The max sub array is from " << ans.l + 1 << " to " << ans.r + 1 << " and the max sum is " << ans.sum << endl;
}