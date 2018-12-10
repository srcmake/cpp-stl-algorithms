#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	//std::string s = "abcmopxyz";
	//std::string t = "mop";

	//bool containsMop = std::includes(s.begin(), s.end(), t.begin(), t.end()); // true
	
	std::vector<int> v{ 5, 3, 1, 8, 4, 6};

	auto lambdaIsOdd = [](int i) { return i % 2 != 0; };

	std::vector<int>::iterator it = std::partition_point(v.begin(), v.end(), lambdaIsOdd);
	// Points to 8

	//it--;
	//std::vector<int>::iterator it
	//auto lambda = [](int i) { std::cout << i << " "; };
	//std::for_each(v.begin(), v.end(), lambda);
	std::cout << std::endl;
	std::cout << *it << std::endl;
	//std::cout << isPartitioned << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;
	std::cout << std::endl;

	return 0;
	}