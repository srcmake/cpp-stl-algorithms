# C++ STL Algorithms Cheat Sheet

The C++ Standard Template Library provides algorithms for functions that are commonly needed for container objects. 

Now, I'm sure you're a gr8 coder and all and could write your own functions, but you should probably use the Standard Committee's functions whenever possible. They're very efficient, both memory and space wise, especially if you use STL containers. 

The rest of this README is going to contain short explanations of each STL algorithm, as well as very concise sample code showing how to use the algorithms. Star/bookmark this repository and use it as a reference.

## Base Code and C++ version

For the sake of testing this code, we'll specify a very basic C++ file that our code would run in. Note that we include `vector`, because that's the container the examples will use, we're including `iostream` for `cout`, and we including `algorithm` for the actual STL algorithms.

#### main.cpp

```
#include <iostream>
#include <vector>
#include <algorithm> 

int main()
	{
	// INSERT STD:ALGORITHM HERE
	
	return 0;
	}
```

We'll use a simple makefile to compile and run, specifying C++11.

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

// Use STL's count_if algorithm.
int count = count_if(srcVec.begin(), srcVec.end(), srcLambda);

std::cout << count << std::endl;
```

(Most people actually put the lambda expression on one line; I just exaggerated the curly braces for emphasis in this one example.)

Got it? Good. We'll be using lambda expressions a lot.

## Iterators

Iterators are special pointers that point to a specific place in a collection. 

For example, a `stack` data structure can't have it's items indexed by elements like a `vector` could, but we still might want to access a specific element in the stack once we find it. Well...that's what an iterator is. It just points to an element in a collection.

For example, the following code creates an iterator (special pointer) to the first element in a vector named 'srcVector'.

```
std::vector<int>::iterator it = srcVector.begin();
```

If you want to access the next element, you could increment the iterator.

```
it++;
```

And if you want to access the element that the iterator is pointing too, you can dereference it.

```
int element = *it;
```

Remember, iterators are just pointers to the elements in a collection. (And if you don't know about pointers, read [this tutorial](https://www.srcmake.com/home/cpp-pointers).)

---
---

# C++ STL Algorithms

---
---

# Figure Something Out About Data

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
### count
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

---

# Modify The Data

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

---

# Divide

### is_partition
### partition
### stable_partition
### partition_copy
### partition_point

---

# Sorting

### sort
### stable_sort
### partial_sort
### partial_sort_copy
### is_sorted
### is_sort_until
### nth_element

---

# Binary Search

These algorithms are about binary searching O(log N) a sorted range for a value.

### lower_bound

Returns an iterator for the lower bound of an element in a range. 

"Lower bound" means the first element that is not less than the element we're searching for. 

For example, for vector [3, 3, 4, 4, 4, 5, 7], lower_bound(4) points to the very first 4 (at index 2).
lower_bound(6) points to 7, since that's the first element not less than 6.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want, and the element you want to search for. 
* Returns an iterator to the element. (Or to the container's end if the element doesn't exist.)

```
std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 4);

int index = it - v.begin(); // 2
```

### upper_bound

Returns an iterator for the upper bound of an element in a range. 

"Upper bound" means the first element that is greater than the element we're searching for. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want, and the element you want to search for. 
* Returns an iterator to the element. (Or to the container's end if the element doesn't exist.)

```
std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), 4);

int index = it - v.begin(); // 5
```

### equal_range

Finds the starting index and ending index for an element in a range. (Meaning if we have duplicates of an item in a container, and we want to find out the range of where those items are.)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want, and the element you want to search for. 
* Returns an `pair` of iterators of the element type.

```
std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::equal_range(v.begin(), v.end(), 4);

std::vector<int>::iterator startIterator = p.first;
std::vector<int>::iterator endIterator = p.second;

int startIndex = startIterator - v.begin(); // 2
int endIndex = endIterator - v.begin(); // 5
```

### binary_search

Returns true if an element exists in a sorted range. Returns false otherwise. Does a binary search to find the item.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want, and the element you want to search for. 
* Returns a bool. 

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::sort(v.begin(), v.end());

bool twoExists = std::binary_search(v.begin(), v.end(), 2); // true
```
---

# Merge

### merge
### inplace_merge
### includes
### set_union
### set_intersection
### set_difference
### set_symmetric_difference

---

# Heap

### push_heap
### pop_heap
### make_heap
### sort_heap
### is_heap
### is_heap_until

---

# Min and Max

These algorithms are related to finding the minimum/maximum element in a range, or when comparing two items.

### min

Compares two items and returns the smaller one.

* Pass in two items (`int`s, for example) as parameters.
* Returns the item's type. 

```
int m = std::min(5, 2); // 2
```

### max

Compares two items and returns the larger one.

* Pass in two items (`int`s, for example) as parameters.
* Returns the item's type. 

```
int m = std::max(5, 2); // 5
```

### minmax

Kind of useless in my opinion. Not even going to post the implementation. see `minmax_element` for something useful.

### min_element

Returns an iterator to the smallest element for a given range. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want. 
* Returns an iterator of the type of the collection.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::vector<int>::iterator it = std::min_element(v.begin(), v.end());
```

### max_element

Returns an iterator to the largest element for a given range. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want. 
* Returns an iterator of the type of the collection.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::vector<int>::iterator it = std::max_element(v.begin(), v.end());
```

### minmax_element

Returns a `pair` of iterators to the smallest and the largest elements for a given range. (The smallest is the first item, and the largest is the second item.)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range you want. 
* Returns an `std::pair` of iterators of type of the collection.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::minmax_element (v.begin(), v.end());

int smallest = *p.first; // 1
int largest = *p.second; // 7
```

---

### References

* [cplusplus.com's list of STL algorithms.](http://www.cplusplus.com/reference/algorithm/)

* [Jonathan Boccara's CppCon Talk about the STL Algorithms.](https://www.youtube.com/watch?v=2olsGf6JIkU&t=7s)

### Notes

* I'm purposely not using the `auto` keyword in this documentation, but use it in your real code.

* Note that I say "range" a lot, but specifically use `vector.begin()` and `vector.end()` most of the time. Remember that your range can be anywhere in the container you want, it doesn't have to be the whole container.

* If you see a problem or if an example is used incorrectly or doesn't work, feel free to raise a pull request, create an issue, or message me on one of the platforms mentioned above. This is meant to be a very very short guide and easy to use, and so some details may be purposely omitted. (Or maybe I'm just a scrub and I don't know how to code LUL.)