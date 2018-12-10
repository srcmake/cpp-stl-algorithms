#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v{ 5, 4, 2, 3, 1, 200 };

	std::vector<int>::iterator it = std::is_heap_until(v.begin(), v.end()); // Points to 200

	// v is now { 1 2 3 4 5 }.

	//std::vector<int>::iterator it
	//auto lambda = [](int i) { std::cout << i << " "; };
	//std::for_each(v.begin(), v.end(), lambda);

	std::cout << *it << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;
	std::cout << std::endl;

	return 0;
	}