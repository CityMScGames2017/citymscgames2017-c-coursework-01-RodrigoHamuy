#include <iostream>
#include "sample.h"

using namespace std;

int main_test(int argc, char *argv[]) {
    /* an empty sample object - initialise with a vector once
    * you have defined the sample constructor that takes a
    * vector
    */

    /* Place your code for testing sample after this line. */
    sample a_sample { 7, 11, 2, 13, 3, 5};
    cout << "\tBefore city_test()\n";
    city_test(a_sample);
    cout << "\tAfter city_test()\n";

    sample s { 7, 11, 2, 13, 3, 5};
    cout << s << endl
    << "min: " << s.minimum() << endl
    << "max: " << s.maximum() << endl
    << "range: " << s.range() << endl
    << "midrage: " << s.midrange() << endl
    << "median: " << s.median() << endl
    << "mean: " << s.mean() << endl
    << "variance: " << s.variance() << endl
    << "std_deviation: "<< s.std_deviation() << endl;

    istringstream iss("<6: 7 11 2 13 3 5 > <2: 1.18973e+4932 1.18973e+4932 >");
    cin.rdbuf(iss.rdbuf());
    while(cin >> s || !cin.eof())
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
