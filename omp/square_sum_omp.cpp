#include <iostream>
#include <vector>
#include <sys/time.h>
#include "omp.h"

#define ORD 1 << 15 // array size

using namespace std;
void get_square_sum(const vector<double> &v);

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

    // variables for timing
    struct timeval start_time, stop_time, elapsed_time;
    
    gettimeofday(&start_time, NULL); // start clock
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                // find vec avg
                get_square_sum(vec);
            }
        }
    }
    gettimeofday(&stop_time, NULL);                   // stop clock
    timersub(&stop_time, &start_time, &elapsed_time); // time diff
    cout << "Elapsed time: " << elapsed_time.tv_sec + elapsed_time.tv_usec / 1000000.0 << endl;

    return 0;
}

void get_square_sum(const vector<double> &v)
{
    double sum_of_squares = 0;
    for (int i = 0; i < v.size(); i++)
    {
        double square = v[i] * v[i];
        sum_of_squares += square;
    }
    cout << scientific;
    cout << "Sum of squares: " << sum_of_squares << endl;
}