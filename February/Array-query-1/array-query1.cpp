#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,op;cin>>n>>m>>op;
    assert(n > 0 && m > 0 && op < 2);
    vector<int>arr(n),brr(m);
    for (int i = 0;i<n;++i){
        cin>>arr[i];
        assert(arr[i] > 0);
    }
    for (int i = 0;i<m;++i){
        cin>>brr[i];
        assert(brr[i] > 0);
    }
    //n<=1e3,m <=1e6
    //1<=arr[i],brr[j]<=10000
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    int q;cin>>q;
    if (op == 0){
        vector<int>cnt(10001,0);
        for (int i = 0;i<m;++i){
            cnt[brr[i]]++;
        }
        vector<int>nx(20001,0);
        for (int i = 1;i<=20000;++i){
            nx[i]+=nx[i - 1];
            for (int j = 0;j<n;++j){
                if (arr[j] > i)break;
                if (i - arr[j] > 10000)continue;
                nx[i]+=cnt[i - arr[j]];
            }    
        }
        auto kth = [&](int k){
            int left = 2,right = 20000;
            int pos = -1,poscnt = 0;
            while(left <= right){
                int mid = (left + right)>>1;
                if (nx[mid] >= k){
                    pos = mid;
                    poscnt = nx[mid];
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            return make_pair(pos,poscnt);
        };
        for (int i = 0;i<q;++i){
            int x,y;cin>>x>>y;
            if (x > y)swap(x,y);
            auto u = kth(x),v = kth(y);
            if (u == v){
                cout<<0<<'\n';
                continue;
            }
            x = u.second;
            y = v.second - (nx[v.first] - nx[v.first - 1] - 1);
            cout<<max(0,y - x - 1)<<'\n';
        }
    }
    else{
        //O(n * log(2e8))
        auto kth = [&](int k){
            int left = 2,right = 2e8;
            int pos = -1,poscnt = 0;
            while(left <= right){
                int mid = (left + right)>>1;
                int j = 0;
                int cnt = 0;
                for (int i = n - 1;i>=0;--i){
                    while(j < m && arr[i] + brr[j] <= mid){
                        ++j;
                    }
                    cnt+=j;    
                }
                if (cnt >= k){
                    pos = mid;
                    poscnt = cnt;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            return make_pair(pos,poscnt);
        };
    //O(q * n * log(2e8) + q * n * log(m))
        for (int i = 0;i<q;++i){
            int x,y;cin>>x>>y;
            if (x > y)swap(x,y);
            auto u = kth(x),v = kth(y);
            //cout<<u<<" "<<v<<'\n';
            if (u == v){
                cout<<0<<'\n';
                continue;
            }
            x = u.second;
            y = v.second;
            int cnt = 0;
            int p = 0;
            for (int j  = n - 1;j>=0;){
                while(p < m && v.first - arr[j] > brr[p]){
                    ++p;
                }
                int cur = 0;
                while(p < m && v.first - arr[j] == brr[p]){
                    ++p;
                    cur++;
                }
                int tt = j;
                while(arr[tt] == arr[j]){
                    --tt;
                }
                cnt+=cur * (j - tt);
                j = tt;
            }
            y-=(cnt - 1);
            cout<<max(0,y - x - 1)<<'\n';
        }
    }
    return 0;
}