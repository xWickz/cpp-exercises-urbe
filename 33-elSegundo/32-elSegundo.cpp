#include <iostream>
#include <vector>
using namespace std;

/*
 * Dado un listado de números, encuentra el SEGUNDO más grande
*/

int findSecondLargest(const vector<int>& nums) {
    if (nums.size() < 2) {
        throw invalid_argument("El listado debe contener al menos dos números.");
    }

    int first = INT_MIN;
    int second = INT_MIN;

    for (int num : nums) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num < first) {
            second = num;
        }
    }

    if (second == INT_MIN) {
        throw invalid_argument("No hay un segundo número más grande distinto.");
    }

    return second;
}

int main() {

    vector<int> numbers = {12, 35, 1, 10, 34, 1};
    cout << "El segundo número más grande es: " << findSecondLargest(numbers) << endl;
    
    return 0;
}