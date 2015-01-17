 /* Simple? However, 
 The method dates back to 1946, but the first correct implementation appeared in 1962;
 Only five correct implementations out of twenty textbooks;
 90% professional programmers fail to code it correctly. */

// The forgetful version
// Forget the possibility that the key target might be found quickly
// and continue to subdivide the list until what remains has length 1
 
#include <iostream>
#include <vector> // list in STL doesn't have Retrieve operation,so we use vector here.

 using namespace std;
 typedef int Key;
 enum Error_code {success, not_present};

 Error_code recursive_binary_1(const vector<int> &the_vector, const Key &target ,
                               int bottom, int top, int &position) {
    if (bottom < top) {
        int mid = (bottom + top) / 2;
        if (the_vector[mid] < target) {
            return recursive_binary_1(the_vector, target, mid + 1, top, position);
        }
        else /*if (target < the_vector[mid])*/ {
            return recursive_binary_1(the_vector, target, bottom, mid, position);
        }
    }
    else if (bottom > top) {
        //cout << "Not found." << endl;
        return not_present;
    }
    else {
        position = bottom;
        if (the_vector[bottom] == target) {
            return success;
        } else {
            //cout << "Not found." << endl;
            return not_present;
        }
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
        if (recursive_binary_1(v, target, 0, 100, position) == 0)
            cout << "The position is " << position << endl;
        else
            cout << "Not found" << endl;
    } while (target != -2);
    return 0;
 }
