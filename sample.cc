#include <iostream>
#include "sample.h"

using namespace std;

int main_test(int argc, char *argv[]) {
    /* an empty sample object - initialise with a vector once
    * you have defined the sample constructor that takes a
    * vector
    */
    sample a_sample; // = { 7, 11, 2, 13, 3, 5};
    cout << "\tBefore city_test()\n";
    city_test(a_sample);
    cout << "\tAfter city_test()\n";
    /* Place your code for testing sample after this line. */
    sample s;
    while (cin >> s)
        cout << s << endl
            << "min: " << s.minimum() << endl 
            << "max: " << s.maximum() << endl
            << "range: " << s.range() << endl 
            << "midrage: " << s.midrange() << endl
            << "median: " << s.median() << endl 
            << "mean: " << s.mean() << endl
            << "variance: " << s.variance() << endl 
            << "std_deviation: "<< s.std_deviation() << endl;
    if (cin.bad()) cerr << "\nBad input\n\n";
    return(0);
}

