#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> srcVec{ 5, 3, 7, 2, 1 };
	
	// Lambda expression. 
	// We don't need to store it in a variable, but we will.
	// Notice it's just like a function.
	// Capture any variables in this scope inside of the [].
	// Put any parameters in the ().
	auto srcLambda = [](int i) 
		{ 
		return i > 2;
		};

	// Use STL's count_if algorithm.
	int count = count_if(srcVec.begin(), srcVec.end(), srcLambda);

	// Output the result.
	std::cout << count << std::endl;
	
	return 0;
	}