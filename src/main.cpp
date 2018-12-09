#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v1{ 5, 1, 3, 7, 6, 2, 9, 4 };
	std::vector<int> v2(6); // Initialize v2 with 6 elements.

	std::vector<int>::iterator itStart = v1.begin() + 1;
	std::vector<int>::iterator itEnd = v1.end() - 1;

	std::partial_sort_copy(itStart, itEnd, v2.begin(), v2.end());

	// v2 ends up as { 1, 2, 3, 6, 7, 9}
	// 5 and 4 are skipped since they aren't in range, and the rest are sorted.
	

	//std::vector<int>::iterator it
	auto lambda = [](int i) { std::cout << i << " "; };
	std::for_each(v2.begin(), v2.end(), lambda);

	//std::cout << sIsSmaller << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;

	return 0;
	}