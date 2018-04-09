// C++ program to find minimum sum of two numbers
// formed from all digits in a given array.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of two numbers formed
// from all digits in a[]
int minSum(int arr[], int n)
{
	string num1="";
	string num2="";
	int i;
	priority_queue<int,std::vector<int> , greater<int>> pq;
	for(i=0;i<n;i++){
        pq.push(arr[i]);	    
	}
	int flag=0;
	while(!pq.empty()){
        if(flag==0)
        {
            int x=pq.top();
            pq.pop();
            num1+=(48+x);
            flag=1;
        }
        else{
            int x=pq.top();
            pq.pop();
            num2+=(48+x);
            flag=0;
        }
        cout << num1 << " " << num2 << endl;
	}
	cout << num1 << " " << num2 << endl;
	return stoi(num1)+stoi(num2);
}

int main()
{
	int arr[] = {6, 8, 4, 5, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<minSum(arr, n)<<endl;
	return 0;
}
// Contributed By: Harshit Sidhwa

