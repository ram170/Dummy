#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define row 20
#define col 20
int n,m;
void uprow(int mat[][m],int *r,int *c,int *it)
{
    //printf("%d\n",mat[1][1]);
    int i;
    //printf("%d %d\n",*c,n-(*it));
    for(i=*c;i<n-(*it);i++)
    {
        //printf("%d ",i);
        printf("%d ",mat[*r][i]);
        ++*c;
    }
    --*c;
    //printf("\n\n%d %d\n",*r,*c);
}
void downcol(int mat[][m],int *r,int *c,int *it)
{
    int i;
    for(i=(*r)+1;i<n-(*it);i++)
    {
        //printf("%d %d",i,*c);
        printf("%d ",mat[i][*c]);
        //printf("here");
        ++*r;
    }
    //*r=(*r)-1;
    //printf("\n%d %d\n",*r,*c);
}
void downrow(int mat[][m],int *r,int *c,int *it)
{
    int i;
    for(i=(*c)-1;i!=(*it)-1;i--)
    {
        printf("%d ",mat[*r][i]);
        --*c;
    }
    //*c=(*c)-1;
}
void upcol(int mat[][m],int *r,int *c,int *it)
{
    int i;
    for(i=(*r)-1;i!=(*it);i--)
    {
        //printf("\n%d %d\n",i,(*it)-1);
        printf("%d ",mat[i][*c]);
        --*r;
    }
    //++*r;
}
/*void print(int mat[][m])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
        //scanf("%d",&mat[i][j]);
        printf("%d ",mat[i][j]);
        }
}*/
int main()
{
    int i,j,it=0,r=0,c=0,l;
    scanf("%d%d",&n,&m);
    int mat[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
        scanf("%d",&mat[i][j]);
        //printf("%d ",mat[i][j]);
        }
    //print(mat);
    l=ceil(n/2);
    for(i=0;i<l;i++)
    {
        uprow(mat,&r,&c,&it);
        //printf("\n%d %d\n",r,c);
        downcol(mat,&r,&c,&it);
        //printf("\n%d %d\n",r,c);
        downrow(mat,&r,&c,&it);
        //printf("\n%d %d\n",r,c);
        upcol(mat,&r,&c,&it);
        //printf("\n%d %d\n",r,c);
        it+=1;
        c=c+1;
        if(l%2!=0 && i==l-1)
            uprow(mat,&r,&c,&it);
    }
}
