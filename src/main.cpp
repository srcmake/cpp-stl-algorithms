#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	auto lambda = [](int i) { std::cout << i << " "; };
	
	
	
	std::vector<int> v{ 1, 2, 3, 4 };
	
	std::shuffle(v.begin(), v.end());

	// v is { 1 4 2 3 }
	
	
	std::for_each(v.begin(), v.end(), lambda);
	std::cout << std::endl;
	
	std::cout << std::endl;

	return 0;
	}