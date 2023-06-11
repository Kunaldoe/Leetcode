//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int arr[], int n, int updates[], int k)
{
    int prefixSum[n] = {0}; // Initialize prefix sum array with zeros

    // Calculate prefix sum array
    for (int i = 0; i < k; i++) {
        int a = updates[i];
        prefixSum[a - 1]++; // Increment count of updates at index a-1
    }

    // Perform cumulative sum on the prefix sum array
    for (int i = 1; i < n; i++) {
        prefixSum[i] += prefixSum[i - 1];
    }

    // Add prefix sum values to the original array
    for (int i = 0; i < n; i++) {
        arr[i] += prefixSum[i];
    }
}

};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends