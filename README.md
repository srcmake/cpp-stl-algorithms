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

And if you want the index of that element (if your container uses indices, like a vector), then you can subtract the iterator's position from an iterator point to the beginning of the container.

```
int index = it - srcVector.begin();
```

Remember, iterators are just pointers to the elements in a collection. (And if you don't know about pointers, read [this tutorial](https://www.srcmake.com/home/cpp-pointers).)

---
---

# C++ STL Algorithms

---
---

# Figure Something Out About Data

Need to do something with the data in your container? Look here.

---


### all_of

Check if every element in the range satisfies the condition. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that does something with the element of the container.
* Returns a bool. True if all elements satisfied the condition, false otherwise.

```
std::vector<int> v{ 5, 3, 7, 9, 4 };

auto lambda = [](int i) { return i > 1; };

bool allGreaterThanOne = std::all_of(v.begin(), v.end(), lambda); // true
```

---

### any_of

Check if any element in the range satisfies the condition. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that does something with the element of the container.
* Returns a bool. True if any element satisfied the condition, false otherwise.

```
std::vector<int> v{ 5, 3, 7, 9, 4 };

auto lambda = [](int i) { return i > 8; };

bool anyGreaterThanEight = std::any_of(v.begin(), v.end(), lambda); // true
```

---

### none_of

Check if none of the elements in the range satisfies the condition. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that does something with the element of the container.
* Returns a bool. True if all elements fail the condition, false if any element passes the condition.

```
std::vector<int> v{ 5, 3, 7, 9, 4 };

auto lambda = [](int i) { return i > 10; };

bool noneGreaterThanTen = std::none_of(v.begin(), v.end(), lambda); // true
```

---

### for_each

Does something for each item in a range. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that does something with the element of the container.
* Returns void.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

auto lambda = [](int i) { std::cout << i << " "; };

std::for_each(v.begin(), v.end(), lambda); // Prints each element in the container.
```

---

### find

Find an item in a given range.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and an item that you want to find.
* Returns an iterator to the first element in the range that is equal to the item we specified.

```
std::vector<int> v{ 5, 3, 7, 9, 4 };
	
std::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
```

---

### find_if

Find the first item that satisfies a condition.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that returns a bool.
* Returns an iterator to the first element in the range that satisfies the lambda's condition.

```
std::vector<int> v{ 5, 3, 7, 9, 4 };
	
auto lambda = [](int i) { return i > 6; };

std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), lambda); 

int firstElementGreaterThanSix = *it; // 7
```

---

### find_if_not

Find the first item that does not satisfy a condition.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that returns a bool.
* Returns an iterator to the first element in the range that does not satisfy the lambda's condition.

```
std::vector<int> v{ 5, 3, 7, 9, 4 };
	
auto lambda = [](int i) { return i > 6; };

std::vector<int>::iterator it = std::find_if_not(v.begin(), v.end(), lambda); 

int firstElementLessThanSix = *it; // 5
```

---

### find_end

For a range, find the last occurence of a sequence in that range. (Ex. Get the last "oo" in "moo_cookies".)

* Pass in an iterator to the beginning of the first range, and an iterator to the end of the first range, and an iterator to the beginning of the sequence, and an iterator to the end of the sequence,
* Returns an iterator to the first item of the sequence.


```
std::string s = "moo_cookies";
std::string t = "oo";

std::string::iterator it = std::find_end(s.begin(), s.end(), t.begin(), t.end()); // Points to the 'o' after the 'c'
```

---

### find_first_of

For a range, find the first occurence of a sequence in that range. (Ex. Get the first "oo" in "moo_cookies".)

* Pass in an iterator to the beginning of the first range, and an iterator to the end of the first range, and an iterator to the beginning of the sequence, and an iterator to the end of the sequence,
* Returns an iterator to the first item of the sequence.


```
std::string s = "moo_cookies";
std::string t = "oo";

std::string::iterator it = std::find_first_of(s.begin(), s.end(), t.begin(), t.end()); // Points to the 'o' after the 'm
```

---

### adjacent_find

Find the first occurrence of two consecutive elements that match in a range. (Ex. The "cc" in "accentt".)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns an iterator to the first item in the match.

```
std::string s = "accentt";

std::string::iterator it = std::adjacent_find(s.begin(), s.end()); // Points to the first 'c'
```

---

### count

Count the number of times an item appears in the range. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and the item we want to count.
* Returns an integer.

```
std::vector<int> v{ 5, 3, 7, 9, 3, 4 };
	
int countOfThree = std::count(v.begin(), v.end(), 3); // 2
```

---

### count_if

Count the number of occurrences satisfying the lambda function.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and a lambda function that returns true or false.
* Returns an integer.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

auto lambda = [](int i) { return i > 2; };

int count = count_if(v.begin(), v.end(), lambda);
```

---

### mismatch

Finds the first occurrence where two rangers differ. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and an iterator to the beginning of the second range.
* Returns a `pair` of iterators to the positions where the ranges occur.

```
std::vector<int> v1{ 5, 3, 7, 9 };
std::vector<int> v2{ 5, 3, 2, 9 };
	
std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::mismatch(v1.begin(), v1.end(), v2.begin());

int element1 = *p.first; // 7
int element2 = *p.second; // 2
```

---

### equal

Check if the elements in two ranges are equal. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and an iterator to the beginning of the second range.
* Returns a bool. True if the elements are equal, false otherwise.

```
std::vector<int> v1{ 5, 4, 6 };
std::vector<int> v2{ 5, 4, 6 };

bool isEqual = std::equal(v1.begin(), v1.end(), v2.begin()); // true
```

---

### is_permutation

Check if a range is a permutation of another. 

A "permutation" is if the items in one range can be rearranged to form the other range. (Ex. "dog" can be rearranged to form "god".)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and an iterator to the beginning of the second range.
* Returns a bool. True if the elements are permutations, false otherwise.


```
std::vector<char> v1{ 'g', 'o', 'd' };
std::vector<char> v2{ 'd', 'o', 'g' };
	
bool isPermutation = std::is_permutation(v1.begin(), v1.end(), v2.begin()); // true
```

---

### search

Check if a range contains a certain sequence. (Ex. Does "this" contain "is"?)

* Pass in an iterator to the beginning of the first range, and an iterator to the end of the first range, and an iterator to the beginning of the second range (sequence), and an iterator to the end of the second range (sequence).
* Returns an iterator to the first item in the range that begins the sequence. 

```
std::vector<char> v1{ 't', 'h', 'i', 's' };
std::vector<char> v2{ 'i', 's' };
	
std::vector<char>::iterator it = std::search(v1.begin(), v1.end(), v2.begin(), v2.end()); // Points to the 'i' in v1
```

---

### search_n

Search a range for a certain number of a specific item. (Ex. Find two 'e's in a row in the word 'esteem'.)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and the count of the number of the item we need to find, and the item we're trying to find.
* Returns an iterator to the first item in the range that begins the sequence. 

```
std::vector<char> v{ 'e', 's', 't', 'e', 'e', 'm' };
	
std::vector<char>::iterator it = std::search_n(v.begin(), v.end(), 2, 'e'); // Points to the 'e' after the 't'.
```

---

### lexicographical_compare

Lexographically compare two items to find out which is 'smaller'. 

* Pass in an iterator to the beginning of the first range, and an iterator to the end of the first range, an iterator to the beginning of the second range, and an iterator to the end of the second range.
* Returns a bool. True if the first range is lexographically less than the second range.

```
std::string s = "abc";
std::string t = "def";

bool sIsSmaller = std::lexicographical_compare(s.begin(), s.end(), t.begin(), t.end()); // true
```

---

# Do Work On Data

Do some work involving some data.

---

### copy

Copy the elements from one range into another. 

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, and an iterator to the beginning of the copy range.
* Returns an iterator to the element after the last one we wrote to in the copy range.

```
std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(4);

std::vector<int>::iterator it = std::copy(v1.begin(), v1.end(), v2.begin());
// Points to the element after 4 in v2.

// v2 is { 1 2 3 4 }
```

---

### copy_n

Copy the first n elements from one range into another. 

* Pass in an iterator to the beginning of the first range, an int representing how many elements to copy, and an iterator to the beginning of the copy range.
* Returns an iterator to the element after the last one we wrote to in the copy range.

```
std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(2);

std::vector<int>::iterator it = std::copy_n(v1.begin(), 2, v2.begin());
// Points to the element after 2 in v2.

// v2 is { 1 2 }
```

---

### copy_if

Copy elements from one range into another if the condition we specify is met. 

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, an iterator to the beginning of the copy range, and a lambda function that returns a bool.
* Returns an iterator to the element after the last one we wrote to in the copy range.

```
std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(2);

auto lambdaIsEven = [](int i) { return i % 2 == 0; };

std::vector<int>::iterator it = std::copy_if(v1.begin(), v1.end(), v2.begin(), lambdaIsEven);
// Points to the element after 4 in v2.

// v2 is { 2 4 }
```

---

### copy_backward

Copy the elements from one range into another, starting from the back elements and going to the front.

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, and an iterator to the end of the copy range.
* Returns an iterator to the element after the last one we wrote to in the copy range (which is the beginning of the copy range).

```
std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(4);

std::vector<int>::iterator it = std::copy_backward(v1.begin(), v1.end(), v2.end());
// Points to the 1 in v2.

// v2 is { 1 2 3 4 }
```

---

### move

Move the elements from one range into another. The elements in the original range are valid, but may not be what they were before the move.

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, and an iterator to the beginning of the move range.
* Returns an iterator to the element after the last one we wrote to in the move range.

```
std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(4);

std::vector<int>::iterator it = std::move(v1.begin(), v1.end(), v2.begin());
// Points to the element after 4 in v2.

// v1 is { 1 2 3 4 } (It just happens to be unchanged.)
// v2 is { 1 2 3 4 }
```

---

### move_backward

Move the elements from one range into another, starting from the back elements and going to the front. The elements in the original range are valid, but may not be what they were before the move.

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, and an iterator to the end of the move range.
* Returns an iterator to the element after the last one we wrote to in the move range (which is the beginning of the move range).

```
std::vector<int> v1{ 1, 2, 3, 4 };
std::vector<int> v2(4);

std::vector<int>::iterator it = std::move_backward(v1.begin(), v1.end(), v2.end());
// Points to the 1 in v2.

// v1 is { 1 2 3 4 } (It just happens to be unchanged.)
// v2 is { 1 2 3 4 }
```

---

### swap

Swaps the values of two items. 

* Pass in the first and the second item.
* Returns void.

```
int a = 5;
int b = 10;

std::swap(a, b); // Now a = 10 and b = 5.
```

---

### swap_ranges

TODO

---

### iter_swap

TODO

---

### transform

TODO

---

### replace

TODO

---

### replace_if

TODO

---

### replace_copy

TODO

---

### replace_copy_if

TODO

---

### fill

TODO

---

### fill_n

TODO

---

### generate

TODO

---

### generate_n

TODO

---

### remove

TODO

---

### remove_if

TODO

---

### remove_copy

TODO

---

### remove_copy_if

TODO

---

### unique

TODO

---

### unique_copy

TODO

---

### reverse

TODO

---

### reverse_copy

TODO

---

### rotate

TODO

---

### rotate_copy

TODO

---

### random_shuffle

TODO

---

### shuffle

TODO

---

# Partitioned

Operate on partioned data, which is split in half based on a certain condition.

---

### is_partitioned

Check if the data in a range is partitioned according to a condition you specify. (Ex. Are the odd elements separated from the even elements?)

* Pass in an iterator to the beginning of the range, an iterator to the end of the range, and a lambda that returns a bool.
* Returns a bool. True if the data is in the beginning all return true and the data afterward all return false. Returns false otherwise.

```
std::vector<int> v{ 5, 3, 1, 8, 4, 6 };

auto lambdaIsOdd = [](int i) { return i % 2 != 0; };

bool isPartitioned = std::is_partitioned(v.begin(), v.end(), lambdaIsOdd); // true
```

Note that if the data is all false and then all true, `is_partitioned` will return false. Make sure your lambda will return "true" for the front data. For example..

```
std::vector<int> v{ 5, 3, 1, 8, 4, 6 };

auto lambdaIsEven = [](int i) { return i % 2 == 0; };

bool isPartitioned = std::is_partitioned(v.begin(), v.end(), lambdaIsEven); // false
```

isPartitioned is false even though the data is clearly partitioned. That's because the first partition returns false and the second partition returns true. 

---

### partition

Rearranges the elements in a range so that the first group returns true for the condition you specify. (Ex. Move all odd elements to the front.)

* Pass in an iterator to the beginning of the range, an iterator to the end of the range, and a lambda that returns a bool.
* Returns an iterator to the first element of the second partition. 

```
std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };

auto lambdaIsOdd = [](int i) { return i % 2 != 0; };

std::vector<int>::iterator it = std::partition(v.begin(), v.end(), lambdaIsOdd);

// v is now { 1 7 3 5 4 6 2 }
```

---

### stable_partition

Rearranges the elements in a range so that the first group returns true for the condition you specify. (Ex. Move all odd elements to the front.) Order is preserved.

* Pass in an iterator to the beginning of the range, an iterator to the end of the range, and a lambda that returns a bool.
* Returns an iterator to the first element of the second partition. 

```
std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };

auto lambdaIsOdd = [](int i) { return i % 2 != 0; };

std::vector<int>::iterator it = std::stable_partition(v.begin(), v.end(), lambdaIsOdd);

// v is now { 1 3 5 7 2 4 6 }
```

---

### partition_copy

For a range, copies the data which is true for a condition we specify into some range, and copies the data that is false into some other range. 

* Pass in an iterator to the beginning of the original range, an iterator to the end of the original range, an iterator to the beginning of the "true" range, an iterator to the end of the "false" range, and a lambda that returns a bool.
* Returns a `pair` of iterators to the element after the last entered element for each of the copy ranges.

```
std::vector<int> v1{ 1, 2, 3, 4, 5, 6, 7 };
std::vector<int> v2(7);
std::vector<int> v3(7);

auto lambdaIsOdd = [](int i) { return i % 2 != 0; };

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::partition_copy(v1.begin(), v1.end(), v2.begin(), v3.begin(), lambdaIsOdd);

// v2 is now { 1 3 5 7 0 0 0 } (The zeroes are from initialization.)
// v3 is now { 2 4 6 0 0 0 0 } (The zeroes are from initialization.)
```

---

### partition_point

Get the first element in a partitioned range that returns false for a given condition. (The element that begins the partition.)

* Pass in an iterator to the beginning of the range, an iterator to the end of the range, and a lambda that returns a bool.
* Returns an iterator to the element. 

```
std::vector<int> v{ 5, 3, 1, 8, 4, 6 };

auto lambdaIsOdd = [](int i) { return i % 2 != 0; };

std::vector<int>::iterator it = std::partition_point(v.begin(), v.end(), lambdaIsOdd);
// Points to 8
```

---

# Sorting

Sorting data.

---

### sort

Sort the elements in a container for the given range.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns void.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::sort(v.begin(), v.end()); 

// v is now { 1, 2, 3, 5, 7 }.
```

---

### stable_sort

Sort the elements in a container for the given range, but the sort is stable.

A "stable" sort means that for equal elements, an element that was ahead of another before the sort will be ahead after the sort. 

```
std::vector<int> v{ 5, 3, 7, 3, 2, 1 }; // { 5, 3a, 7, 3b, 2, 1 }

std::stable_sort(v.begin(), v.end()); 

// v is now { 1, 2, 3a, 3b, 5, 7 }
```

Stable sort is best used for objects.

---

### partial_sort

For a position in a range, make sure all the elements from the beginning of the range up to that position are the smallest elements in the range and are sorted. (The rest of the elements (which are up to the position until the end of the range) aren't in any specific order.)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and an iterator to the position we want to partially sort for.
* Returns void.

```
std::vector<int> v{ 5, 1, 3, 7, 6, 2, 9, 4 };

std::vector<int>::iterator it = v.begin() + 3;

std::partial_sort(v.begin(), v.end(), it);

// v ends up as { 1, 2, 3, 4, 5, 6, 7, 9}
```

In the code example, v ends up fully sorted, but only the first three elements are guaranteed to be sorted.

---

### partial_sort_copy

Copies the items from a range into a second range, in sorted order.

* Pass in an iterator to the beginning of the first range, and an iterator to the end of the first range, and an iterator to the beginning of the range we want to copy into, and an iterator to the end of the range we want to copy into,
* Returns an iterator to the item after where we finished writing to in the copy range.

```
std::vector<int> v1{ 5, 1, 3, 7, 6, 2, 9, 4 };
std::vector<int> v2(6); // Initialize v2 with 6 elements.

std::vector<int>::iterator itStart = v1.begin() + 1;
std::vector<int>::iterator itEnd = v1.end() - 1;

std::partial_sort_copy(itStart, itEnd, v2.begin(), v2.end());

// v2 ends up as { 1, 2, 3, 6, 7, 9}
// 5 and 4 are skipped since they aren't in range. v2 is in sorted order.
```

---

### is_sorted

Check whether a given range is sorted. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns a bool. True if the range is sorted, false if it's not sorted.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

bool isSorted = std::is_sorted(v.begin(), v.end()); // false
```

---

### is_sort_until

Finds the first element in a range that isn't sorted. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns an iterator to the first unsorted element.

```
std::vector<int> v{ 2, 3, 4, 1, 5 };

std::vector<int>::iterator it = std::is_sorted_until(v.begin(), v.end()); // Points to the 1
```

---

### nth_element

For the position that you specify in a range, places the element at that position that would be there if the range was sorted. ("What would the nth element be if this range was sorted" without actually sorting the entire range.)

* Pass in an iterator to the beginning of the range, an iterator to the position we want to find out about, and an iterator to the end of the range.
* Returns void. (The range is edited, though.)

```
std::vector<int> v{ 5, 3, 7, 9, 4 };
	
// v sorted would be { 3, 4, 5, 7, 9 }

std::vector<int>::iterator it = v.begin() + 1; // 2nd element in v.

std::nth_element(v.begin(), it, v.end());

int element = v[1]; // 4
```

---

# Binary Search

These algorithms are about binary searching O(log N) a sorted range for a value.

---

### lower_bound

Returns an iterator for the lower bound of an element in a range. 

"Lower bound" means the first element that is not less than the element we're searching for. 

For example, for vector [3, 3, 4, 4, 4, 5, 7], lower_bound(4) points to the very first 4 (at index 2).
lower_bound(6) points to 7, since that's the first element not less than 6.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and the element you want to search for. 
* Returns an iterator to the element. (Or to the container's end if the element doesn't exist.)

```
std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 4);

int index = it - v.begin(); // 2
```

---

### upper_bound

Returns an iterator for the upper bound of an element in a range. 

"Upper bound" means the first element that is greater than the element we're searching for. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and the element you want to search for. 
* Returns an iterator to the element. (Or to the container's end if the element doesn't exist.)

```
std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), 4);

int index = it - v.begin(); // 5
```

---

### equal_range

Finds the starting index and ending index for an element in a range. (Meaning if we have duplicates of an item in a container, and we want to find out the range of where those items are.)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and the element you want to search for. 
* Returns an `pair` of iterators of the element type.

```
std::vector<int> v{ 3, 3, 4, 4, 4, 5, 7 };

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::equal_range(v.begin(), v.end(), 4);

std::vector<int>::iterator startIterator = p.first;
std::vector<int>::iterator endIterator = p.second;

int startIndex = startIterator - v.begin(); // 2
int endIndex = endIterator - v.begin(); // 5
```

---

### binary_search

Returns true if an element exists in a sorted range. Returns false otherwise. Does a binary search to find the item.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range, and the element you want to search for. 
* Returns a bool. 

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::sort(v.begin(), v.end());

bool twoExists = std::binary_search(v.begin(), v.end(), 2); // true
```
---

# Sorted Data Operations

Is your data sorted? If yes, then do these efficient operations on them.

---

### merge

Given two sorted ranges, combine them to form one larger sorted range. 

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, an iterator to the beginning of the second range, an iterator to the end of the second range, and an iterator to the beginning of the resulting range that you want to place all of the data into.
* Returns an iterator to the end of the resulting range after placing the last item into it.

```
std::vector<int> v1{ 1, 3, 5, 9 };
std::vector<int> v2{ 2, 4, 6, 7 };
std::vector<int> v3(8);

std::vector<int>::iterator it = std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); 
// Points to v3.end()

// v3 is { 1, 2, 3, 4, 5, 6, 7, 9 }
```

---

### inplace_merge

Given two consecutive sorted ranges (in the same container), do an in-place merge to sort the entire range.

* Pass in an iterator to the beginning of the first sorted range, an iterator to the beginning of the second sorted range, and an iterator to the end of the second sorted range.
* Returns void.

```
std::vector<int> v{ 6, 7, 8, 1, 2, 3 };

std::inplace_merge(v.begin(), v.begin()+3, v.end());

// v is now { 1, 2, 3, 6, 7, 8 }
```

---

### includes

Check if a given a sorted range contains a second (sorted) range (that you specify). (Ex. Does "abcmopxyz" contain "mop"?)

* Pass in an iterator to the beginning of the first sorted range, an iterator to the end of the first sorted range. an iterator to the beginning of the second sorted range, and an iterator to the second sorted range. 
* Returns a bool. True if the first range contains the second range, false if it doesn't.

```
std::string s = "abcmopxyz";
std::string t = "mop";

bool containsMop = std::includes(s.begin(), s.end(), t.begin(), t.end()); // true
```

---

### set_union

Given two sorted ranges, creates a new sorted range from the elements that exist in either range. (The union.)

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, an iterator to the beginning of the second range, an iterator to the end of the second range, and an iterator to the beginning of the resulting range that you want to place all of the data into.
* Returns an iterator to the element after the last element we placed in the resulting range.

```
std::vector<int> v1{ 1, 2, 3 };
std::vector<int> v2{ 1, 1, 2, 4 };
std::vector<int> v3(7);

std::vector<int>::iterator it = std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
// Points to the element after 4 in v3.

// v3 is { 1 1 2 3 4 0 0 } (Zeroes were from the initialization)
```

Notice that there are only two 1's in the resulting range. `set_union` will take the maximum number of an element from one range; it won't just add them. 

---

### set_intersection

Given two sorted ranges, created a new sorted range from the elements that exist in both ranges. (The intersection.)

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, an iterator to the beginning of the second range, an iterator to the end of the second range, and an iterator to the beginning of the resulting range that you want to place all of the data into.
* Returns an iterator to the element after the last element we placed in the resulting range.

```
std::vector<int> v1{ 1, 2, 3 };
std::vector<int> v2{ 1, 1, 2, 4 };
std::vector<int> v3(7);

std::vector<int>::iterator it = std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
// Points to the element after 2 in v3.

// v3 is { 1 2 0 0 0 0 0 } (Zeroes were from the initialization)
```

---

### set_difference

Given two sorted ranges, created a new sorted range from the elements that exist in the first range that don't exist in the second range. (The difference.)

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, an iterator to the beginning of the second range, an iterator to the end of the second range, and an iterator to the beginning of the resulting range that you want to place all of the data into.
* Returns an iterator to the element after the last element we placed in the resulting range.

```
std::vector<int> v1{ 1, 2, 3 };
std::vector<int> v2{ 1, 1, 2, 4 };
std::vector<int> v3(7);

std::vector<int>::iterator it = std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
// Points to the element after 3 in v3.

// v3 is { 3 0 0 0 0 0 0 } (Zeroes were from the initialization)
```

---

### set_symmetric_difference

Given two sorted ranges, created a new sorted range from the elements that exist in one of the ranges but doesn't exist in the other range. (The symmetric difference.)

* Pass in an iterator to the beginning of the first range, an iterator to the end of the first range, an iterator to the beginning of the second range, an iterator to the end of the second range, and an iterator to the beginning of the resulting range that you want to place all of the data into.
* Returns an iterator to the element after the last element we placed in the resulting range.

```
std::vector<int> v1{ 1, 2, 3 };
std::vector<int> v2{ 1, 1, 2, 4 };
std::vector<int> v3(7);

std::vector<int>::iterator it = std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
// Points to the element after 4 in v3.

// v3 is { 1 3 4 0 0 0 0 } (Zeroes were from the initialization)
```

Notice the 1 in v3. That's there because v2 has an extra 1 that v1 does not have. 

---

# Heap

Algorithms regarding heap data structures.

A "heap" is a binary tree that always has maximum element as the root node (top of the tree). It's used in priority queues. (It can also have the min element as the root.)

---

### make_heap

Rearranges the items in a range so that they form a heap.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns void.

```
std::vector<int> v{ 1, 2, 3, 4 };

std::make_heap(v.begin(), v.end());

// v is now { 4 2 3 1 }
```

---

### push_heap

If the first elements of a range are a heap, but the last item isn't, then `push_heap` will place that last item into it's correct position.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns void.

```
std::vector<int> v{ 4, 2, 3, 1 }; // v is already a heap.

v.push_back(5); // v is no longer a heap.

std::push_heap(v.begin(), v.end());

// v is now { 5 4 2 3 1 }, which is a heap.
```

---

### pop_heap

Given a range for a heap, places the max element at the end of the range, and rearranges the rest of the elements to be a heap again.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns void.

```
std::vector<int> v{ 5, 4, 2, 3, 1 }; // v is a heap.

std::pop_heap(v.begin(), v.end());

// v is now { 4 2 3 1 5 }. (The first 4 elements are a heap.)
```

---

### sort_heap

If a range is a heap, rearrange it into sorted order.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns void.

```
std::vector<int> v{ 5, 4, 2, 3, 1 }; // v is a heap.

std::sort_heap(v.begin(), v.end());

// v is now { 1 2 3 4 5 }.
```

---

### is_heap

Check if a range is a heap. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns a bool. True if the range is a heap, false if it's not a heap.

```
std::vector<int> v{ 5, 4, 2, 3, 1 }; // v is a heap.

bool isHeap = std::is_heap(v.begin(), v.end()); // true
```

---

### is_heap_until

Find the first place in a range that makes the range fail being a heap.

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range.
* Returns an iterator to the first element that makes the range fail being a heap.

```
std::vector<int> v{ 5, 4, 2, 3, 1, 200 };

std::vector<int>::iterator it = std::is_heap_until(v.begin(), v.end()); // Points to 200
```

---

# Min and Max

These algorithms are related to finding the minimum/maximum element in a range, or when comparing two items.

---

### min

Compares two items and returns the smaller one.

* Pass in two items (`int`s, for example) as parameters.
* Returns the item's type. 

```
int m = std::min(5, 2); // 2
```

---

### max

Compares two items and returns the larger one.

* Pass in two items (`int`s, for example) as parameters.
* Returns the item's type. 

```
int m = std::max(5, 2); // 5
```

---

### minmax

Kind of useless in my opinion. Not even going to post the implementation. see `minmax_element` for something useful.

---

### min_element

Returns an iterator to the smallest element for a given range. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range. 
* Returns an iterator of the type of the collection.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::vector<int>::iterator it = std::min_element(v.begin(), v.end());
```

---

### max_element

Returns an iterator to the largest element for a given range. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range. 
* Returns an iterator of the type of the collection.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::vector<int>::iterator it = std::max_element(v.begin(), v.end());
```

---

### minmax_element

Returns a `pair` of iterators to the smallest and the largest elements for a given range. (The smallest is the first item, and the largest is the second item.)

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range. 
* Returns an `std::pair` of iterators of type of the collection.

```
std::vector<int> v{ 5, 3, 7, 2, 1 };

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::minmax_element (v.begin(), v.end());

int smallest = *p.first; // 1
int largest = *p.second; // 7
```

---

# Permutations

Permute data into it's next transformation.

### next_permutation

Rearranges the items in the specified range into the next lexographically greater permutation. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range. 
* Returns a bool. True if the range was transformed, false otherwise (if there was no such possible permutation).

```
std::string s = "abc";

std::next_permutation(s.begin(), s.end());

// s is now "acb"
```

---

### prev_permutation

Rearranges the items in the specified range into the previous lexographically ordered permutation. 

* Pass in an iterator to the beginning of the range, and an iterator to the end of the range. 
* Returns a bool. True if the range was transformed, false otherwise (if there was no such possible permutation).

```
std::string s = "acb";

std::prev_permutation(s.begin(), s.end());

// s is now "abc"
```

---

# End Notes

### References

* [cplusplus.com's list of STL algorithms.](http://www.cplusplus.com/reference/algorithm/)

* [Jonathan Boccara's CppCon Talk about the STL Algorithms.](https://www.youtube.com/watch?v=2olsGf6JIkU)

### Notes

* The `auto` keyword was purposely not used often in this documentation, but use it in your real code.

* Note that I say "range" a lot, even though I specifically use `vector.begin()` and `vector.end()` most of the time. Remember that your range can be anywhere in the container you want.

* If you see a problem or if an example is used incorrectly or doesn't work, feel free to raise a pull request, create an issue, or message me on one of the platforms mentioned above. This is meant to be a very very short guide and easy to use, and so some details may be purposely omitted. (Or maybe I'm just a scrub and I don't know how to code LUL.)

### Todo

* Make a custom comparator example for stable_sort.
* Make a note that nth_element has the parameter ordering weird. 
* Maybe make a section explaining pairs?
* Change some of the vector examples to strings.
* Make note about possible changes because of inconsistencies in words/code.
* Make note about typos or incorrect information.

Category types?
1. Figure something out about container/range.
2. Modify the container/range.
2. Find one data point. (If get iterator back then it's this.)