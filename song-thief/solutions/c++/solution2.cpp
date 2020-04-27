#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int>a(n);
    vector<int>ans(n,0);

    for(int i=0;i<n;i++)cin>>a[i];

    vector<vector<int> > mi( n , vector<int> (n, 0));
    vector<vector<int> > ma( n , vector<int> (n, 0));

    for(int i=0;i<n;i++)
    {
        int minimum=a[i];
        int maximum=a[i];
        for(int j=i;j<n;j++)
        {
            maximum=max(maximum,a[j]);
            minimum=min(minimum,a[j]);
            mi[i][j]=minimum;
            ma[i][j]=maximum;
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            if((a[i]<mi[i+1][j-1]&&a[j]<mi[i+1][j-1]) || (a[i]>ma[i+1][j-1] && a[j]>ma[i+1][j-1]))
            {

                int c;
                if(i>0)c=max(ans[i-1]+1,ans[j-1]);
                else c=max(1,ans[j-1]);
                ans[j]=max(c,ans[j]);

            }else{
                ans[j]=max(ans[j],ans[j-1]);
            }
        }
    }


    cout<<ans[n-1]<<"\n";

    return 0;
}
