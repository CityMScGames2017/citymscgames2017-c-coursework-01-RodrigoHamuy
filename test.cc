#include <iostream>
#include <cassert>
#include <float.h>
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
    vector <string> results {"2", "1.18973e+4932"};
    auto result = results.begin();
    ostringstream expected;
    ostringstream currValue;

    while(iss >> s || !iss.eof()) {
        cout << s << endl
            << "min: " << s.minimum() << endl
            << "max: " << s.maximum() << endl
            << "range: " << s.range() << endl
            << "midrage: " << s.midrange() << endl
            << "median: " << s.median() << endl
            << "mean: " << s.mean() << endl
            << "variance: " << s.variance() << endl
            << "std_deviation: "<< s.std_deviation() << endl;

        expected << *result;
        currValue << s.minimum();
        assert(
            expected.str()== currValue.str() &&
            "Min is not what expected"
            );
        result++;
    }
    if (iss.bad()) cerr << "\nBad input\n\n";
    return(0);
}
