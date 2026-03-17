class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty())return nums;
        Merge_sort(nums,0,nums.size()-1);
        return nums;
    }
private:
void Merge(vector<int>& A,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int* left_array=new int[n1];
    int* right_array=new int[n2];
    for(int i=0;i<n1;i++)
    {
        left_array[i]=A[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        right_array[j]=A[q+j+1];
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if( left_array[i]<=right_array[j] )
        {
            A[k]=left_array[i];
            i++;
        }
        else
        {
            A[k]=right_array[j];
            j++;
        }
        k++;
    }
    while(i<n1)A[k++]=left_array[i++];
    while(j<n2)A[k++]=right_array[j++];
    
    delete[] right_array;
    delete[] left_array;
    return;
}

void Merge_sort(vector<int>&A,int p,int r)
{
    if(p>=r)return;
    int q=(p+r)/2;
    Merge_sort(A,p,q);
    Merge_sort(A,q+1,r);
    Merge(A,p,q,r);
}

};