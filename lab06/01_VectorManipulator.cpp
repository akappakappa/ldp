#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<double> manipulate_vector(const vector<double> &input_vector)
{
    vector<double> sorted = input_vector;       // alg: STL sort
    vector<double> reversed = input_vector;     // alg: reverse
    double sum;                                 // alg: accumulate
    double first_half = 0;                      // alg: for
    int positive_or_zero;                       // alg: count_if

    sort(sorted.begin(), sorted.end());
    reverse(reversed.begin(), reversed.end());
    sum = accumulate(input_vector.begin(), input_vector.end(), 0.0);
    for (int i = 0; i < input_vector.size() / 2; i++)
        first_half += input_vector.at(i);
    positive_or_zero = count_if(input_vector.begin(), input_vector.end(), [](int i){return i >= 0;});

    // preparing output
    sorted.insert(sorted.end(), reversed.begin(), reversed.end());
    sorted.push_back(sum);
    sorted.push_back(first_half);
    sorted.push_back((double)positive_or_zero);

    return sorted;
}

int main()
{
    vector<double> a{0, 1, 4, 5, -2, -6, 3, -1, -9, 7}; // 10 elements
    vector<double> b = manipulate_vector(a);

    for (int i = 0; i < b.size(); i++)
        cout << b.at(i) << " ";
    cout << endl;
    
    return 0;
}