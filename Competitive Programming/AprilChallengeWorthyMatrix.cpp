#include<iostream>
#define int long long
using namespace std;

int32_t main(){
    int t;cin>>t;
    while(t--){
        
        int n,m,k;
        cin>>n>>m>>k;
        int a[n+1][m+1];
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]+=a[i][j-1];
            }
        }
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                a[i][j]+=a[i-1][j];
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int res=0;
        for(int part=1;part<=n;part++){
            for(int i=1;i<=n-part+1;i++){
                int low=1;
                int high=m-part+1;
                int mid;
                int p;
                int flag=0;
               
                while(low<=high){
                    mid=(high+low)/2;
                    
                    int sum=a[i+part-1][mid+part-1]-a[i+part-1][mid-1]-a[i-1][mid+part-1]+a[i-1][mid-1];
                    if(sum>=k*part*part){
                        
                        high=mid-1;
                        p=mid;
                        flag=1;
                    }else{
                        low=mid+1;
                    }
                }
               
                if(flag==1){
                    res+=(m-part-p+2);
                }
            }
        }
        cout<<res<<endl;
    }
}