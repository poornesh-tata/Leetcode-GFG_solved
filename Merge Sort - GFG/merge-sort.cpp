//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int v[], int start, int mid, int end)
    {
         // Your code here
        vector<int> temp;
        int left = start; int right = mid +1;
        while(left<=mid and right<=end)
        {
            if (v[left] <= v[right]) {
                temp.push_back(v[left]);
                left++;
            }
            else {
                temp.push_back(v[right]);
                right++;
            }
        }
         while (left <= mid) {
            temp.push_back(v[left]);
            left++;
        }
        while (right <= end) {
            temp.push_back(v[right]);
            right++;
        }
        for (int i = start; i <= end; i++) {
            v[i] = temp[i - start];
        }
    }
    public:
    void mergeSort(int arr[], int start, int end)
    {
        //code here
        if(start==end) return ;
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends