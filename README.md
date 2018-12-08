# C++ STL Algorithms

The C++ Standard Template Library provides algorithms for functions that are commonly needed for container objects. 

Now, I'm sure you're a gr8 coder and all and could write your own functions, but you should probably use the Standard Committee's functions whenever possible. They're very efficient, both memory and space wise, especially if you use STL containers. 

The rest of this README is going to contain short explanations of each STL algorithm, as well as very concise sample code showing how to use the algorithms. Star/bookmark this repository and use it as a reference.

## Base Code and C++ version

For the sake of testing this code, we'll specify a very basic C++ file that our code would run in. 

#### main.cpp

```
#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	std::vector<int> srcVec{ 5, 3, 7, 2, 1 };
	
	// INSERT STD:ALGORITHM HERE
	
	return 0;
	}
```

We'll use a simple makefile, specifying C++11.

#### makefile

```
all:
	g++ main.cpp -std=c++11 -o run
	./run
```

And so to actually run this code, in a UNIX operating system, in the terminal, simply type `make` in the directory where your makefile and main.cpp are.


## Lambda Expressions

Lambda expressions are just functions that we can use to specify some functionality we need (duh). They're especially useful when working with STD algorithms because we can pass a lambda expression to an algorithm to tell the algorithm what to do. 

For example, "find out how many numbers in this vector are greater than 2" is very concise to code if you specify a lambda expression and then use an STL algorithm.

```
/* // Lambda expression. 
We don't need to store it in a variable, but we will. 
Otherwise we'd pass in directly in the algorithm call.
Capture any variables in this scope inside of the [].
Put any parameters in the (). 
*/
auto srcLambda = [](int i) 
	{ 
	return i > 2;
	};

// Use STD's count_if algorithm.
int count = count_if(srcVec.begin(), srcVec.end(), srcLambda);

std::cout << count << std::endl;
```

(Most people actually put the lambda expression on one line; I just exaggerated the curly braces for emphasis in this one example.)

Got it? Good. We'll be using lambda expressions a lot.

# C++ STL Algorithms

## Figure Something Out About Data

### all_of
### any_of
### none_of
### for_each
### find_
### find_if
### find_if_not
### find_end
### find_first_of
### adjacent_find
### count_
### count_if

Counts the number of occurrences satisfying the lambda function.

* Pass in the container's range, and a lambda function that returns true or false.
* Returns an integer.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

auto lambda = [](int i) { return i > 2; };

int count = count_if(v.begin(), v.end(), lambda);
```

### mismatch
### equal
### is_permutation
### search
### search_n

## Modify The Data

### copy
### copy_n
### copy_if
### copy_backward
### move
### move_backward
### swap
### swap_ranges
### iter_swap
### transform
### replace
### replace_if
### replace_copy
### replace_copy_if
### fill
### fill_n
### generate
### generate_n
### remove
### remove_if
### remove_copy
### remove_copy_if
### unique
### unique_xopy
### reverse
### reverse_copy
### rotate
### rotate_copy
### random_shuffle
### shuffle

## Divide

### is_partition
### partition
### stable_partition
### partition_copy
### partition_point


## Sorting

### sort
### stable_sort
### partial_sort
### partial_sort_copy
### is_sorted
### is_sort_until
### nth_element


## Binary Search

### lower_bound
### upper_bound
### equal_range
### binary_search


## Merge

### merge
### inplace_merge
### includes
### set_union
### set_intersection
### set_difference
### set_symmetric_difference


## Heap

### push_heap
### pop_heap
### make_heap
### sort_heap
### is_heap
### is_heap_until


## Min and Max

### min
### max
### minmax
### min_element
### max_element
### minmax_element


### References

* [cplusplus.com's list of STL algorithms.](http://www.cplusplus.com/reference/algorithm/)

* [Jonathan Boccara's CppCon Talk about the STL Algorithms.](https://www.youtube.com/watch?v=2olsGf6JIkU&t=7s)

### Note 

If you see a problem or if an example is used incorrectly or doesn't work, feel free to raise a pull request, create an issue, or message me on one of the platforms mentioned above. This is meant to be a very very short guide and easy to use, and so some details may be purposely omitted. 

Or maybe I'm just a scrub and I don't know how to code LUL.