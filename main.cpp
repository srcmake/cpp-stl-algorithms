#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> v{ 5, 3, 7, 2, 1 };

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::minmax_element (v.begin(), v.end());

	int smallest = *p.first;
	int largest = *p.second;
	

	std::cout << smallest << " " << largest << std::endl;

	return 0;
	}