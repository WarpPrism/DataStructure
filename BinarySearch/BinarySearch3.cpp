// Check at each stage to see if the target has be found.
// And this method is the best one
#include <iostream>
#include <vector>

using namespace std;
typedef int Key;
enum Error_code {success, not_present};

Error_code recursive_binary_2(const vector<int> &the_vector, const Key &target,
	                          int bottom, int top, int &position) {
	if (bottom <= top) {
		int mid = (bottom + top) / 2;
		if (the_vector[mid] == target) {
			position = mid;
		    // cout << position << endl;
			return success;
		}
		if (the_vector[mid] > target) {
			return recursive_binary_2(the_vector, target, bottom, mid - 1, position);
		}
		if(the_vector[mid] < target) {
			return recursive_binary_2(the_vector, target, mid + 1, top, position);
		}
	} else {
		return not_present;
	}
}

int main() {
    int testarr[101];
    for (int i = 0; i <= 100; i++) {
        testarr[i] = 2 * i - 1; // odd numbers
    }
    cout << "We have constructed an array of odd numbers(-1 ~ 199)" << endl;
    vector<int> v(testarr, testarr + 101);
    int target, position;
    do {
        cout << "Now Please input the target you want to search.(End with -2)" << endl;
        cin >> target;
        if (recursive_binary_2(v, target, 0, 100, position) == 0)
            cout << "The position is " << position << endl;
        else
            cout << "Not found" << endl;
    } while (target != -2);
    return 0;
 }
