#include <bits/stdc++.h>
using namespace std;

void merge(vector<long long>& A, long long start, long long mid, long long end)
{
    long long n1 = (mid - start + 1);
    long long n2 = (end - mid);
    long long L[n1], R[n2];
    for (long long i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (long long j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    long long i = 0, j = 0;
    for (long long k = start; k <= end; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

long long mergesort_and_count(vector<long long>& A, long long start, long long end)
{
    if (start < end) {
        long long mid = (start + end) / 2;
        long long count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
        long long j = mid + 1;
        for (long long i = start; i <= mid; i++) {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(A, start, mid, end);
        return count;
    }
    else
        return 0;
}

long long reversePairs(vector<long long>& nums)
{
    return mergesort_and_count(nums, 0, nums.size() - 1);
}
int main(){
    
    long long n;
    cin>>n;
    vector<long long>a(n);
    for(long long i=0;i<n;i++)cin>>a[i];
    
    cout<<reversePairs(a)<<"\n";
}
