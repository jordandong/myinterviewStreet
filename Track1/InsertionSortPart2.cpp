/*
In Insertion Sort Part 1, you sorted one element into an array. Using the same approach repeatedly, can you sort an entire unsorted array?

Guideline: You already can place an element into a sorted array. How you can you use that code to build up a sorted array, one element at a time? Note that the first element is already “sorted” since there’s nothing to its left that is smaller than it.

In this challenge, don’t print every time you move an element. Instead, print the array every time an element is “inserted” into the array in (what is currently) its correct place. Since the first element is already “sorted”, begin printing from the second element and on.

Input Format
There will be two lines of input:

s - the size of the array
ar - the list of numbers that makes up the array
Output Format
On each line, output the entire array every time an item is inserted into its place.

Constraints
1<=s<=1000 
1<=x<= 1000 , x ∈ ar

Sample Input

6
1 4 3 5 6 2
Sample Output

1 4 3 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 2 3 4 5 6 
Explanation
Insertion Sort checks the ‘4’ first and doesn’t need to move it, so it just prints out the array. Next, the 3 is inserted next to the 4 and the array is printed out. This continues one element at a time until the entire array is sorted.

Task
The method insertionSort takes in one parameter: ar, an unsorted array. Use an Insertion Sort Algorithm to sort the entire array.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/* Head ends here */

void insertionSort(vector <int>  ar) {
    int n = ar.size();
    for(int i=1;i<n;i++){
        int curr = ar[i];
        for(int j=i-1;j>=0;j--){
            if(ar[j]>curr){
                ar[j+1]=ar[j];
                if(j==0)
                    ar[j]=curr;
            }
            else{
                ar[j+1]=curr;
                j=-1;
            }
        }
        for(int t=0;t<n;t++)
            cout<<ar[t];
        cout<<endl;
    }
}


/* Tail starts here */
int main() {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }
    insertionSort(_ar);
    return 0;
}
