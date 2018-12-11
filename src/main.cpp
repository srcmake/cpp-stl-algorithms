#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	//std::string s = "abcmopxyz";
	//std::string t = "mop";

	//bool containsMop = std::includes(s.begin(), s.end(), t.begin(), t.end()); // true
	
	std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(4);

std::vector<int>::iterator it = std::copy_backward(v1.begin(), v1.end(), v2.end());
// Points to the 1 in v2.

// v2 is { 1 2 3 4 }

	//auto lambdaIsEven = [](int i) { return i % 2 == 0; };

	//it--;
	//std::vector<int>::iterator it
	auto lambda = [](int i) { std::cout << i << " "; };
	std::for_each(v1.begin(), v1.end(), lambda);
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), lambda);
	std::cout << std::endl;
	std::cout << *it << std::endl;
	//std::cout << isPartitioned << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;
	std::cout << std::endl;

	return 0;
	}