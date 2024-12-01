#include <iostream>
#include <vector>
#include <algorithm>

int mergeAndCount(std::vector<int>& arr,int left,int right) {
    int mid=arr.size()-1;
    int n1=mid-left+1;
    int n2=right-mid;
    std::vector<int> L(n1),R(n2);

    std::copy(arr.begin()+left,arr.begin()+mid+1,L.begin());
    std::copy(arr.begin()+mid+1,arr.begin()+right+1,R.begin());

    int i=0,j=0,k=left;
    int inv_count=0;
    while(i<n1&&j<n2)
        {
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        } else
        {
            arr[k]=R[j];
            inv_count+=(n1-i);
            j++;
        }
        k++;
    }
    while(i<n1)
        {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
        {
        arr[k]=R[j];
        j++;
        k++;
    }
    return inv_count;
}

int mergeSortAndCount(std::vector<int>& arr,int left,int right) {
    int inv_count=0;
    if(left<right) {
        int mid=left+(right-left)/2;
        inv_count+=mergeSortAndCount(arr,left,mid);
        inv_count+=mergeSortAndCount(arr,mid+1,right);
        inv_count+=mergeAndCount(arr,left,right);
    }
    return inv_count;
}

int main() {
    std::vector<int> arr={1,3,5,2,4,6};
    int n=arr.size();
    int result=mergeSortAndCount(arr,0,n-1);
    std::cout<<result;
    return 0;
}