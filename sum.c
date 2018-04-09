// C++ program to find the smallest number that can be
// formed from given sum of digits and number of digits.
#include <iostream>
using namespace std;

// Prints the smallest possible number with digit sum 's'
// and 'm' number of digits.
void findSmallest(int m, int s)
{
    int arr[m];
	if(s==0){
	    std::cout << "not possible" << std::endl;
	}
	else{
	    if(s>9*m)
	    {
	         std::cout << "not possible" << std::endl;
	    }
	    else if(s==9*m){
	        for(int l=m-1;l>=0;l--){
	            arr[l]=9;
	        }
	    }
	    else{
	    	int flag=0;
	        for(int l=m-1;l>=0;l--){
	            if(s>9){
	                arr[l]=9;
	                s-=9;
	            }
	            else{
	                if(l==0)
	                {
	                	if(flag==0)
	                	{
	                		arr[l]=s;
	                	}
	                   else{
	                   		arr[l]=1;
	                   }
	                }
	                else{
	                    if(flag==0)
	                	{
	                	arr[l]=s-1;
	                	flag=1;
	                	}else{
	                	    arr[l]=0;
	                	}
	                }
	            }
	                
	            }
	        }
	        for(int l=0;l<m;l++){
	            cout << arr[l] ;
	        }
	        cout << endl;
	    }
}

// Driver code
int main()
{
	int s = 25, m = 6;
	findSmallest(m, s);
	return 0;
}
