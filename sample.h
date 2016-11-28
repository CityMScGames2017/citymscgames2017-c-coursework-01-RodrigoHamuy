#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
using namespace std;
#include "city.hh"

class sample : public city {
	// DON'T CHANGE ANYTHING ABOVE THIS LINE!!! (You can add more includes)
private:
	vector<long double> data;
	bool allItemsAreTheSameValue {false};
	void checkItems(){
		if ( adjacent_find( data.begin(), data.end(), not_equal_to<long double>() ) == data.end() ){
			allItemsAreTheSameValue = true;
		}
	}
public:
	sample() {}
	sample(initializer_list<long double> const &data) : data(data) { checkItems(); }
	sample(vector<long double> const &data) : data(data) { checkItems(); }

	const long double *get_data() const{
		return data.data();
	}

	const long double minimum() const {
		if (allItemsAreTheSameValue){
			return *(data.begin());
		}
		return *(min_element(data.begin(), data.end()));
	}
	const long double maximum() const {
		if (allItemsAreTheSameValue){
			return *(data.begin());
		}
		return *(max_element(data.begin(), data.end()));
	}
	const long double range() const {
		if (allItemsAreTheSameValue){
			return 0;
		}
		return maximum() - minimum();
	}
	const long double midrange() const {
		if (allItemsAreTheSameValue){
			return *(data.begin());
		}
		return (maximum() + minimum())*0.5;
	}
	const long double mean() const {
		if (allItemsAreTheSameValue){
			return *(data.begin());
		}
		return accumulate(data.begin(), data.end(), 0.0)/data.size();
	}
	const long double variance() const {
		if (allItemsAreTheSameValue){
			return 0;
		}
		long double meanValue = mean();
		long double value{ 0 };
		for (const auto i : data) {
			value += (i - meanValue)*(i - meanValue);
		}
		return value / data.size();
	}
	const long double std_deviation() const {
		if (allItemsAreTheSameValue){
			return 0;
		}
		return sqrtl(variance());
	}
	const long double median() const {
		if (allItemsAreTheSameValue){
			return *(data.begin());
		}
		auto temp = data;
		sort(temp.begin(), temp.end());
		if (temp.size() % 2 == 0){
			return (temp[(temp.size() / 2) - 1] + temp[temp.size() / 2]) / 2.0;
		}
		else{
			return temp[temp.size() / 2];
		}
	}

	ostream &print(ostream &out) const{
		out << "<" << data.size() << ": ";
		for (auto i : data) {
			out << i << " ";
		}
		out << ">";
		return out;
	}
	friend ostream &operator << (ostream &out, const sample &test) {
		test.print(out);
		return out;
	}
	friend istream &operator >> (istream &in, sample &newSample) {
		string token;
		long double vectorItem;
		vector<long double> *initValues = &(newSample.data);
		initValues->clear();

		in >> token;
		// Assert input starts with <{size}:
		// where {size} is the size of the array.
		if (
			(token.substr(0,1) != "<") ||
			(token.substr(token.length()-1, token.length()) != ":")
			){
			in.setstate(std::ios_base::failbit);
		}else{
			// Extract the array size
			token = token.substr(1, token.length() - 2);
			unsigned int length = stoi(token);

			// Extract all the numbers in the array
			for (unsigned int i = 0; i < length; i++){
				in >> vectorItem;
				initValues->push_back(vectorItem);
			}
			in >> token;
			// Assert input ends with ">"
			if (token.substr(0,1) != ">"){
				in.setstate(std::ios_base::failbit);
			}else{
				newSample.checkItems();
			}
		}
		return in;
	}
};

/* With normal (non-generic) code, the source (.cc) includes the header (.h). */
#endif
