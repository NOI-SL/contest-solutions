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
   	vector<int>b(n);
   	
   	for(int i=0;i<n;i++)cin>>a[i];
   	for(int i=0;i<n;i++)cin>>b[i];
   	
   	sort(a.begin(),a.end());
   	sort(b.rbegin(),b.rend());
   	
   	int sum=a[0]+b[0];
   	
   	for(int i=1;i<n;i++)
   	{
   		if(a[i]+b[i]!=sum)
		   {
		   		cout<<-1<<"\n";
		   		return 0;
			}	
	}
	
	for(int i=0;i<n;i++)cout<<a[i]<<" "<<b[i]<<"\n";
   	
    return 0;
}
