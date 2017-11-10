#include<iostream>
using namespace std;
class matrix{
	private:
		int n;
		float **a,**b,**c;
	public:
		void khoitao();// khoi tao ma tran vuong cap n
		void xuat();// xuat ma tran
		void doi_line();// doi 2 hang
		void doi_column();// doi 2 cot
		void tong();
		void hieu();
		void tich();
		void chuyenvi();
		float dinhthuc();
		void nghichdao();
};
void matrix::khoitao()
{
	cin>>n;
	a=new float*[n];
	b=new float*[n];
	c=new float*[n];
	for(int i=0;i<n;i++)
		{
			a[i]=new float[n];
			for(int j=0;j<n;j++)
				{
					cin>>a[i][j];
				}
		}
	for(int i=0;i<n;i++)
		{
			b[i]=new float[n];
			for(int j=0;j<n;j++)
				{
					//cin>>b[i][j];
					b[i][j]=0;
				}
		}
	for(int i=0;i<n;i++)
		{
			c[i]=new float[n];
			for(int j=0;j<n;j++)
				{
					c[i][j]=0;
				}
		}
}
void matrix::xuat()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					cout<<b[i][j]<<" ";
				}
			cout<<endl;
		}
}
void matrix::doi_line()
{
	int i,j;
	cin>>i>>j;
	for(int k=0;k<n;k++)
		{
			int temp=a[i][k];
			a[i][k]=a[j][k];
			a[j][k]=temp;
		}
}
void matrix::doi_column()
{
	int i,j;
	cin>>i>>j;
	for(int k=0;k<n;k++)
		{
			int temp=a[k][i];
			a[k][i]=a[k][j];
			a[k][j]=temp;
		}
}
void matrix::tong()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					c[i][j]=a[i][j]+b[i][j];
				}
		}
}
void matrix::hieu()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					c[i][j]=a[i][j]-b[i][j];
				}
		}
}
void matrix::tich()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					c[i][j]=0;
					for(int k=0;k<n;k++)
						{
							c[i][j]+=a[i][k]*b[k][j];
						}
				}
		}
}
void matrix::chuyenvi()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					c[i][j]=a[j][i];
				}
		}
}
float matrix::dinhthuc()
{
	int det=1,k,i,j;
    for (i=0;i<n-1;i++)
    	{
        	if(a[i][i]==0)
			{
	        	k=i+1;
	        	while ((k<n)&&(a[k][i]==0))
	            	k++;
	        	if (k>(n-1))
	            	{
	                	det=0;
	               		break;
	            	}
	        	else
		            {
		            det=-det;
		            for (j=i;j<n;j++)
		                {
		                    float tmp=a[i][j];
		                   	a[i][j]=a[k][j];
		                   	a[k][j]=tmp;
		                }
		            }
			}
    for(k=i+1;k<n;k++)
        {
            float t=-a[k][i]/a[i][i];
            for (j=i;j<n;j++)
            a[k][j]+=t*a[i][j];
        }
	}
    for(i=0;i<n;i++)
        det *=a[i][i];
    return det;
}
void matrix::nghichdao()
{
	float k=(1/dinhthuc());
	cout<<k<<endl;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					b[i][j]=k*c[i][j];
				}
		}
}
int main()
{
	matrix matrix1;
	matrix1.khoitao();
//	matrix1.doi_line();
// 	matrix1.doi_column();
//	matrix1.tong();
//	matrix1.hieu();
//	matrix1.tich();
	matrix1.chuyenvi();
//	matrix1.dinhthuc();
	matrix1.nghichdao();
	matrix1.xuat();
	return 0;
}
