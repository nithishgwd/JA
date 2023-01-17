selection

#include<stdio.h>
int main()
{
    int i,j,temp,min,n,a[100];
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {

                min=j;
            }

        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

insertion


#include<stdio.h>
int main()
{
    int i,j,temp,n,a[100];
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
       j=i-1;
    temp=a[i];
    while(j>=0&&a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
    }

    printf("Sorted the elements\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}

mergesort

#include<stdio.h>

void merge(int a[],int lb,int mid,int ub)
{
    int b[100],i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid&&j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            k++;j++;
        }
    }
    else{
         while(i<=mid)
        {
            b[k]=a[i];
            k++;i++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}
void mergeSort(int a,int lb,int ub)
{
    if(lb<ub)
    {

        int mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
  int main()
{
    int i,n,a[100];
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);

printf("Sorted quick the elements\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

quicksort

#include<stdio.h>

int partition(int a[],int lb,int ub)
{
    int start,end,temp,pivot;
    pivot=a[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while (a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
            temp=a[lb];
            a[lb]=a[end];
            a[end]=temp;
            return end;

}
void quickSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {

        int loc;
        loc=partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }
}
  int main()
{
    int i,j,temp,min,n,a[100];
    int flag;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);

printf("Sorted quick the elements\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}


