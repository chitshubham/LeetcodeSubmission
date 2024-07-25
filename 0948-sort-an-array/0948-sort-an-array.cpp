class Solution {
public:
void heapify(vector<int>& arr ,int n ,int i )
{
    int largest=i;
    int leftchild=2*i+1;
    int rightchild=2*i+2;

    if(leftchild<n && arr[largest]<arr[leftchild] )
    {
        largest=leftchild;

    }
    if(rightchild<n && arr[largest] <arr[rightchild])
    {
        largest=rightchild;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(vector<int>&arr,int n)
{
    int t=n-1;
    while(t>=0)
    {
        swap(arr[t],arr[0]);
        heapify(arr,t,0);
        t--;
    }


}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2; i>=0;i-- )
        {
            heapify(nums,n,i);
        }
        heapSort(nums,n);
        return nums;
    }
};