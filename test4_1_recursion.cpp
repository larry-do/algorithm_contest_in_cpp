//dùng đệ quy//nói thật cách này cực zồ//đéo thích
#include<iostream>
void toHop(int x[],int n,int k,int i);
int main(){
    int n=5,k=3;
    int x[n];
    x[0]=0;
    toHop(x,n,k,1);
}
void toHop(int x[],int n,int k, int i)
{

    for (int j=x[i-1]+1;j<=n-k+i;j++)
	{
        x[i]=j;
        if (i==k){
            for(int m=1;m<=k;m++)
                std::cout<<x[m]<<' ';
            std::cout<<std::endl;
        }
        else
            toHop(x,n,k,i+1);
	}
}
