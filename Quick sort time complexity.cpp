#include<bits/stdc++.h>
using namespace std;



int a[40005], counter=0, unit=1e5;
vector <int> vec;
int partition(int low, int high);
void quick_sort(int low, int high);

int main()
{
    int n, x;

    FILE *fout, *fin;
    fout = fopen("QuickSort Data.txt", "w");
    fin = fopen("QuickSort Data.txt", "r");
    srand (time(NULL));

    clock_t start, end;

    for(int i=0; i<40000; i++)
    {
        x = rand()%1000;
        fprintf(fout, "%d\n", x);
    }

    cout<<"How many number you want to sort: ";
    cin>>n;
    cout<<endl;

    for(int i=0; i<n; i++)
    {
        fscanf(fin, "%d", &a[i]);
    }

    start = clock();
    quick_sort(0, n-1);
    end = clock();
    double time_taken = 1000*((double)(end-start)/(double)(CLOCKS_PER_SEC));
    //cout<<"The sorted array is: "<<endl;
    /*for(int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }*/
    cout<<"For "<<n<<" elements, total number of step counted: "<<counter<<endl;
    //counter = 0;
    cout<<"\nTime taken: "<<setprecision(5)<<counter/(unit*1.00)<<" ms."<<endl;

}

void quick_sort(int low, int high)
{
    counter++;
    if(low>=high)
    {
        return;
    }

    int p = partition(low, high);

    quick_sort(low, p-1);
    quick_sort(p+1, high);
}

int partition(int low, int high)
{
    counter++;
    int i, j, pivot = a[high], temp;
    i = low-1;
    for(j=low; j<high; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        counter++;
    }
    temp = a[i+1];
    a[i+1] = pivot;
    a[high] = temp;

    return i+1;
}





