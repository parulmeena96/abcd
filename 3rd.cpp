#include<bits/stdc++.h>
using namespace std;
 
 
// Binary search 
int findInd(vector<int> &vect, int left, int right, int key) {
    while (right-left>1) {
    int mid = left + (right-left)/2;
    if (vect[mid] >= key)
        right = mid;
    else
        left = mid;
    }
 	
    return right;
}
 
// finds LCS between sorted list and original list
int LCS(int arr[], int n){
	vector<int> vect_seq(10001);
	vect_seq[0]=arr[0];
	int size=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<vect_seq[0])	vect_seq[0]=arr[i];
		else if(arr[i]>vect_seq[size-1])
		{
        	vect_seq[size]=arr[i];
        	size++;
		}
        else	vect_seq[findInd(vect_seq,-1,size-1,arr[i])]=arr[i];
		
	}
	//cout<<"out";
	return  size;
}
 
int main()
{
	int t,final;
	cin>>t;
	int arr[10001*2];	// stores the n numbers from arr[0] to arr[n-1] and arr[n] to arr[2n-1]
	while(t--){
		int n;
		final=0;	// stores max LIS possible
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			arr[n+i]=arr[i];
		}
		
		for(int i=0;i<n;i++){
			final=max(final,LCS(arr+i,n));	
			//cout<<i<<endl;
		}
		
		cout<<final<<endl;
	}
	
}