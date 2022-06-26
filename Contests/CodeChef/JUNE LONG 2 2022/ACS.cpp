#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int t;
cin>>t;
while(t--){
    int score,ans;
    cin>>score;
    ans=(score/100)+(score%100);
    if(ans>10)ans=-1;
    cout<<ans<<endl;

}
return 0;
}