#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::equal_range(v.begin(), v.end(), 4);

	std::vector<int>::iterator startIterator = p.first;
	std::vector<int>::iterator endIterator = p.second;

	int startIndex = startIterator - v.begin(); // 2
	int endIndex = endIterator - v.begin(); // 5

	

	std::cout << startIndex << " " << endIndex << std::endl;

	return 0;
	}