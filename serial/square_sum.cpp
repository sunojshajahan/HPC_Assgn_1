#include <iostream>
#include <vector>
#include <time.h>

#define ORD (1 << 27) // array size

using namespace std;

double calculate_square_sum(const vector<double> &v);

int main()
{
    // create a vector with random noise
    vector<double> vec;
    double elmnt, r;
    srand(time(NULL));
    for (int i = 0; i < ORD; i++)
    {
        r = rand() % RAND_MAX;
        elmnt = double(r) / (RAND_MAX);
        vec.push_back(elmnt);
    }

    // calculate square and sum of each element in the vector
    double sum_of_squares = calculate_square_sum(vec);

    cout << scientific;
    cout << "Sum of squares: " << sum_of_squares << endl;

    return 0;
}

double calculate_square_sum(const vector<double> &v)
{
    double sum_of_squares = 0;
    for (int i = 0; i < v.size(); i++)
    {
        double square = v[i] * v[i];
        sum_of_squares += square;
    }
    
    cout << scientific;
    cout << "Sum of squares: " << sum_of_squares << endl;
    return sum_of_squares;
}