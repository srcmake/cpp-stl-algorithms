#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	auto lambda = [](int i) { std::cout << i << " "; };
	//std::string s = "abcmopxyz";
	//std::string t = "mop";

	//bool containsMop = std::includes(s.begin(), s.end(), t.begin(), t.end()); // true
	
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	auto lambdaReturnNine = []() { return 9; };

	std::generate_n(v.begin(), 3, lambdaReturnNine); 
	
	// v is now { 9 9 9 4 5 }

	/*
	std::vector<int> v1{ 1, 2, 3, 4 };
	std::vector<int> v2{ 5, 6, 7, 8 };

	std::vector<int>::iterator it = std::swap_ranges(v1.begin(), v1.end(), v2.begin());
	// Points to the element after 4 in v2.

	// v1 is { 5 6 7 8 }
	// v2 is { 1 2 3 4 }
	*/
	//auto lambdaIsEven = [](int i) { return i % 2 == 0; };
	std::for_each(v.begin(), v.end(), lambda);
	std::cout << std::endl;
	//std::for_each(res.begin(), res.end(), lambda);
	//std::vector<int>::iterator it
	//it--;
	/*
	std::for_each(v1.begin(), v1.end(), lambda);
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), lambda);
	std::cout << std::endl;
	std::cout << *it << std::endl;
	*/
	//std::cout << isPartitioned << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;
	std::cout << std::endl;

	return 0;
	}