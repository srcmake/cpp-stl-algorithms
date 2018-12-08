#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v{ 1, 2, 3, 0, 5 };

	std::vector<int>::iterator it = std::is_sorted_until(v.begin(), v.end()); 

	


	//auto lambda = [](int i) { std::cout << i << " "; };
	//std::for_each(v.begin(), v.end(), lambda);

	std::cout << *it << std::endl;

	return 0;
	}