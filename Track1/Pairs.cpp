/*Given N numbers [N<=10^5], count the total pairs of numbers that have a difference of K. [K>0 and K<1e9]

Input Format:

1st line contains N & K (integers).
2nd line contains N numbers of the set. All the N numbers are assured to be distinct.

Output Format:

One integer saying the no of pairs of numbers that have a diff K.

Sample Input #00:

5 2
1 5 3 4 2

Sample Output #00:

3

Sample Input #01:

10 1
363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793 

Sample Output #01:

0
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Pairs(vector<int> &data, int i, int j, int K, int &res){
    if(i>=j||data[i]+K>data[j])
        return;
    if(data[i]+ K==data[j]){
        res+=1;
        Pairs(data, i+1, j-1, K, res);
    }else{
        Pairs(data, i+1, j, K, res);
        Pairs(data, i, j-1, K, res);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N = 0;
    cin>>N;
    int K =0;
    cin>>K;
    vector<int> data(N,0);
    int  i = 0;
    while(i<N)
        cin>>data[i++];
    sort(data.begin(), data.end());
    int res = 0;
    Pairs(data, 0, N-1, K, res);
    cout<<res<<endl;
    
    
    return 0;
}


#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void Pairs(vector<int> &data, int K, int &res){
    int N = data.size();
    unordered_map<int, int> mp;
    for(int i=0; i<N; i++)
        mp[data[i]]=1;
    for(int i=0;i<N; i++){
        if(mp.find(data[i]+K)!=mp.end())
            res++;
    }
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N = 0;
    cin>>N;
    int K =0;
    cin>>K;
    vector<int> data(N,0);
    int  i = 0;
    while(i<N)
        cin>>data[i++];
    int res = 0;
    Pairs(data, K, res);
    cout<<res<<endl;
    
    return 0;
}

