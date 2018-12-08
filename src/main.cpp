#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v1{ 5, 3, 7, 9 };
	std::vector<int> v2{ 5, 3, 2, 9 };
	
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::mismatch(v1.begin(), v1.end(), v2.begin());

	int element1 = *p.first; // 7
	int element2 = *p.second; // 2



	

	//std::vector<int>::iterator it
	//auto lambda = [](int i) { std::cout << i << " "; };
	//std::for_each(v.begin(), v.end(), lambda);

	//std::cout << countOfThree << std::endl;
	std::cout << element1 << " " << element2 << std::endl;

	return 0;
	}