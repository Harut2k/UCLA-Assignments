#include <iostream>
#include <cassert>


//true if positive. 
bool somePredicate(double x)
{
	return x > 0;
}




//returns true if all are true, returns false if any are false OR is given 0 elements to examine.
bool allTrue(const double a[], int n)
{
	if (n <= 0)
		return false;
	if (n == 1)
		return somePredicate(a[0]);
	return somePredicate(a[n-1]) ? allTrue(a, n - 1) : false; 
}


// Return true if the somePredicate function returns true for at
// least one of the array elements, false otherwise.


bool anyTrue(const double a[], int n)
{
	if (n <= 0)
		return false;
	if (n == 1)
		return somePredicate(a[0]);
	return somePredicate(a[n-1]) ? true : anyTrue(a, n - 1);
}



// Return the number of elements in the array for which the
// somePredicate function returns true.
int countTrue(const double a[], int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return somePredicate(a[0]);
	else
		return somePredicate(a[n-1]) + countTrue(a, n - 1);
}



// Return the subscript of the first element in the array for which
// the somePredicate function returns true.  If there is no such
// element, return -1.
int firstTrue(const double a[], int n)
{
	if (n <= 0 )
		return -1;
	if (n == 1)
		return somePredicate(a[0]) - 1;
	int pos = firstTrue(a, n - 1);
	return (somePredicate(a[n - 1]) && pos == -1) ? n - 1 : pos;
}





// Return the subscript of the smallest element in the array (i.e.,
// return the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the function is told to examine no 
// elements, return -1.



int positionOfMin(const double a[], int n)
{
	if (n <= 0)
		return -1;
	if (n == 1)
		return 0;
	int pos = positionOfMin(a, n - 1);
	return a[n-1] < a[pos] ? n - 1 : pos;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20


bool includes(const double a[], int n, const double b[], int m)
{
	if (n == 0)
		return (m == 0);
	if (a[n-1] == b[m-1])
		return includes(a, n - 1, b, m - 1);
	else
		return includes(a, n - 1, b, m);
}

int main()
{
	return 0;
}