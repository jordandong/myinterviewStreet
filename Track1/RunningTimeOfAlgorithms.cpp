/*
In the previous challenges, you created an insertion sort algorithm and saw that it was correct. Insertion Sort is a simple sorting algorithm that works well with small or mostly-sorted data. However, it takes a long time to sort large unsorted data. To see why, we will need to analyze its running time.

Running Time of Algorithms
The running time of an algorithm for a specific input is the number of operations executed, which will usually correlate with the actual time it takes to run. We usually want to know how many operations an algorithm will take in proportion to the size of its input. (We call the size of the input N.)

For example, the first two input files for InsertionSort were small, so it was able to quickly sort them. But the next two files were larger and it took more time. What is the proportion of the running time of InsertionSort to the size of the Input? To answer this question, we need to examine the InsertionSort algorithm.

Analysis of Insertion Sort
For each element V in an array of N numbers, InsertionSort shifts everything to the right until it can insert V into the array.

How long would does all that shifting take?
In the best case, where the array was already sorted, no element will need to be moved, so the algorithm will just run through the array once and return the sorted array. This would run in direct proportion to the size of the input, so we can say it will N time.

However, we usually focus on the worst-case running-time (computer scientists are pretty pessimistic). The worst case for Insertion Sort is if the array is in reverse order. To insert each number, the algorithm will need to shift over that number to the beginning of the array. Sorting the entire array of N numbers will therefore take 1+2+…+(N-1) operations, which is almost N2/2. Computer scientists just round that up to N2 and say that insertion sort is a “N2 time” algorithm.



What this means
As the size of an input (N) increases, Insertion Sort’s running time will increase by the sqaure of N. So Insertion Sort can work well for small inputs, but becomes unreasonably slow for large inputs. For large inputs, people use sorting algorithms that have better running times, which we will examine later.

Challenge
Can you modify your previous Insertion Sort code to keep track of the number of shifts it makes when sorting? The only thing you should print is the number of shifts your insertion sort makes to completely sort each test case. A shift is whenever an element is moved over in the array. (Do not shift an element if it is not necessary.)

Input Format
The first line contains N, the number of elements to be sorted. The next line contains N integers a[1],a[2]…,a[N].

Output Format
Output the number of shifts it takes.

Sample Input
5
2 1 3 1 2

Sample Output
4

Explanation
The first ‘1’ is shifted once. The ‘3’ stays where it is. The next ‘1’ gets shifted twice. The final ‘2’ gets shifted once. The total number of shifts is 4.

Task
For this problem, you can copy over your code from InsertionSort and modify it to keep track of the number of shifts instead of printing the array.
*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int insertionSortCount(vector <int>  ar) {
    int n = ar.size();
    int count=0;
    for(int i=1;i<n;i++){
        int curr = ar[i];
        for(int j=i-1;j>=0;j--){
            if(ar[j]>curr){
                ar[j+1]=ar[j];
                count++;
                if(j==0)
                    ar[j]=curr;
            }
            else{
                ar[j+1]=curr;
                j=-1;
            }
        }
    }
    return count;
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
    cout<<insertionSortCount(_ar);
    return 0;
}
