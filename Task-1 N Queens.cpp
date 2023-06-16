#include<bits/stdc++.h>
using namespace std;

int a[30], ans;
//row=index and column=value

void queen(int n);
int place(int pos);
void print_sol(int n);

int main()
{
    int i,n;
    printf("Enter dimension: ");
    cin>>n;
    ans = 0;
    queen(n);
    printf("\nTotal solutions = %d\n\n", ans);
}

void queen(int n)
{
    int k=1;
    a[k]=0;
    while(k!=0)
    {
        do
        {
            a[k]++;
        }
        while((a[k]<=n)&&!place(k));
        if(a[k]<=n)
        {
            if(k==n)
                print_sol(n);
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
            k--;
    }
}

int place(int pos)
{
    int i;
    for(i=1; i<pos; i++)
    {
        if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
            return 0;
    }
    return 1;
}

void print_sol(int n)
{
    int i, j;
    ans++;
    printf("\n\nSolution #%d:\n", ans);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i]==j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}
