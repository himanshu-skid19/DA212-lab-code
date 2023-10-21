#include <iostream>
#include <limits.h>
using namespace std;

void merge(int arr[],int s,int e,int m);
void mergesort(int arr[], int s, int e)
{
    if(s<e)
    {
    int m=(s+e)/2;
    mergesort(arr,s,m);
    cout<<"hi"<<s<<" "<<m<<"\n";
    mergesort(arr,m+1,e);
    cout<<"hiB"<<m+1<<" "<<e<<"\n";
    merge(arr,s,e,m);
    }
}
void merge(int arr[],int s,int e,int m)
{
    cout<<s<<" "<<e<<" "<<m<<"\n";
    int n1=m-s+1;
    int n2=e-m;
    int S[n1+1];
    int E[n2+1];
    for(int i=0;i<n1;i++)
    {
        S[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++)
    {
        E[i]=arr[m+1+i];
    }
    S[n1]=INT_MAX;
    E[n1]=INT_MAX;
    int i=0;
    int j=0;
    for(int k=s;k<=e;k++)
    {
        if(S[i]<=E[j])
        {
            arr[k]=S[i];
            i++;
        }
        else
        {
            arr[k]=E[j];
            j++;
        }

    }
     for (int l = 0; l < 7; l++) {
        std::cout << arr[l] << " ";
    }
    cout<<"\n";
}
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
