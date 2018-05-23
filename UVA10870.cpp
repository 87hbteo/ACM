#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=10005;

const int N =20;

struct Mat{
    ll mat[N][N];
}s,f;
ll n,m;
int d;

Mat mul(Mat a,Mat b){
    Mat tmp;
    memset(tmp.mat,0,sizeof(tmp.mat));
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            for(int k=1;k<=d;k++){
                tmp.mat[i][j]=(tmp.mat[i][j]+a.mat[i][k]*b.mat[k][j]%m)%m;
            }
        }
    }
    return tmp;
}

Mat quick(ll k){
    Mat tmp;
    memset(tmp.mat,0,sizeof(tmp.mat));
    for(int i=0;i<=20;i++)
        tmp.mat[i][i]=1;
    while(k){
        if(k&1) tmp=mul(tmp,s);
        k>>=1;
        s=mul(s,s);
    }
    return tmp;
}
int main(){
    while(~scanf("%d%lld%lld",&d,&n,&m)&&!(!n&&!m&&!n)){
        memset(s.mat,0,sizeof(s.mat));
        memset(f.mat,0,sizeof(f.mat));
        for(int i=2;i<=d;i++){
            s.mat[i][i-1]=1;
        }
        for(int i=1;i<=d;i++){
            scanf("%lld",&s.mat[1][i]);
            s.mat[1][i]%=m;
        }
        for(int i=1;i<=d;i++){
            scanf("%lld",&f.mat[d-i+1][1]);
            f.mat[d-i+1][1]%=m;
        }
        if(n<=(ll)d){
            printf("%lld\n",f.mat[d-n+1][1]);
            continue;
        }
        f=mul(quick(n-d),f);
        printf("%lld\n",f.mat[1][1]);
    }
    return 0;
}
