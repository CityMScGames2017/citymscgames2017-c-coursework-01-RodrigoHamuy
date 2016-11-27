#include <iostream>
#include "samplet.h"

using namespace std;

int main_test(int argc, char *argv[]) {
	/* an empty samplet object - initialise with a vector once
	 * you have defined the samplet constructor that takes a
	 * vector
	 */
	samplet<int> a_samplet; // = { 7, 11, 2, 13, 3, 5 };
	cout << "\tBefore city_test_generic()\n";
	city_test_generic(a_samplet);
	cout << "\tAfter city_test_generic()\n";
	/* Place your code for testing samplet after this line. */
    /* Place your code for testing samplet after this line. */
    samplet<int>  s;
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

	return 0;
}
