#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::string s = "acb";

	std::prev_permutation(s.begin(), s.end());

	// s is now "abc"
	

	//std::vector<int>::iterator it
	//auto lambda = [](int i) { std::cout << i << " "; };
	//std::for_each(v2.begin(), v2.end(), lambda);

	std::cout << s << std::endl;
	//std::cout << element1 << " " << element2 << std::endl;

	return 0;
	}