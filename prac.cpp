#include<bits/stdc++.h>
using namespace std;
int main(){
string a = "abdesdfrwssss";
char rep;
string ans;
ans+=a[0];
int i =0;
for(int j = 1;j<a.size();j++){
    if( rep!= a[j] && a[j]==a[j-1]){
         rep = a[j];
         i++;
         ans+= a[j];
    }
    else if(a[j-1]!=a[j]){
        i++;
        ans+= a[j];
        
    }
}
// int k = 0;
// while(k<=i){
//     cout<<a[k];
//     k++;
// }
cout<<ans<<" ";
}