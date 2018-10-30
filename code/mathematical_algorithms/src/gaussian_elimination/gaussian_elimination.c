#include<stdio.h>

int main()
{
    int i,j,k,n;
    printf("\n Input size n for Ax = B\n");
    scanf("%d",&n);
    float c,x[n],sum=0.0;
    float A[n][n];
    float  B[n];
    printf("\n Input array A\n");
    for(i=0; i<n; i++)
    {
    	for(j=0; j<n; j++)
    	{
    		scanf("%f", &A[i][j]);
    	}
    }
     printf("\n Input array B\n");
    for(i=0; i<n; i++)
    {
    	scanf("%f", &B[i]);
    }
    
    for(k=0; k<n; k++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=0; i<n; i++)
        {
            if(i>k)
            {
		            c=A[i][k]/A[k][k];
		            for(j=0; j<n; j++)
		            {
		                A[i][j]= A[i][j]-c*A[k][j];
		            }
					B[i]= B[i]-c*B[k]; 
			}  
        }
    }
    x[n-1]=B[n-1]/A[n-1][n-1];
    printf("%f\n",x[n-1]);
    /* this loop is for backward substitution*/
    for(i=n-2; i>=0; i--)
    {
        sum=0.0;
        for(j=i+1; j<n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(B[i]-sum)/A[i][i];
        printf("%f\n",x[i]);
    }
    printf("\nThe solution is: \n");
    for(i=0; i<n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
    return(0);
}
