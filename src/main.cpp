#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v1{ 1, 2, 3 };
	std::vector<int> v2{ 1, 1, 2, 4 };
	std::vector<int> v3(7);

	std::vector<int>::iterator it = std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	// Points to the element after 4 in v3.

	// v3 is { 1 3 4 0 0 0 0 } (Zeroes were from the initialization)

	//it--;

	//std::string s = "abcmopxyz";
	//std::string t = "mop";

	//bool containsMop = std::includes(s.begin(), s.end(), t.begin(), t.end()); // true
	

	// v is now { 1, 2, 3, 6, 7, 8 }




	it--;
	//std::vector<int>::iterator it
	auto lambda = [](int i) { std::cout << i << " "; };
	std::for_each(v3.begin(), v3.end(), lambda);
	std::cout << std::endl;
	std::cout << *it << std::endl;
	//std::cout << containsMop << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;
	std::cout << std::endl;

	return 0;
	}