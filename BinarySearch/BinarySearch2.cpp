// Because the recursion in the function recursive_binary_1 is tail recursion,
// it is easy to eliminate it and make an iterative version.

#include <iostream>
#include <vector>

using namespace std;
typedef int Key;
enum Error_code {success, not_present};

Error_code binary_search_1(const vector<int> &the_vector, const Key &target, int &position) {
	int bottom = 0;
	int top = the_vector.size() - 1;
	while (bottom < top) {
		int mid = (bottom + top) / 2;
		if (target > the_vector[mid]) {
			bottom = mid + 1;
		} else {
			top = mid;
		}
	}
	if (bottom > top) return not_present;
	if (bottom == top) {
		position = bottom;
		if (the_vector[bottom] == target) return success;
		else return not_present;
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
        if (binary_search_1(v, target, position) == 0)
            cout << "The position is " << position << endl;
        else
            cout << "Not found" << endl;
    } while (target != -2);
    return 0;
 }
