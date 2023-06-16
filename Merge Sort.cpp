#include<bits/stdc++.h>
using namespace std;

int a[40005], a2[40005], counter_quick=0, unit=1e5, counter_merge=0;
void quick_sort(int low, int high);
int partition(int low, int high);
void merge_sort(int left, int right);
void merge(int left, int mid, int right);

int main()
{
    int n, x;

    FILE *fout, *fin;
    fout = fopen("sort_i.in.txt", "w");
    fin = fopen("sort_i.in.txt", "r");
    srand (time(NULL));

    for(int i=0; i<40000; i++) // random number generation
    {
        x = rand()%1000;
        fprintf(fout, "%d\n", x);
    }

    cout<<"How many number you want to sort: ";
    cin>>n;
    cout<<endl;

    for(int i=0; i<n; i++) // input in array for quick sort
    {
        fscanf(fin, "%d", &a[i]);
    }
    for(int i=0; i<n; i++) // input in array for merge sort
    {
        fscanf(fin, "%d", &a2[i]);
    }

    quick_sort(0, n-1);
    merge_sort(0, n-1);

    /*cout<<"The sorted array by Quick sort is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"The sorted array by Merge sort is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a2[i]<<endl;
    }*/
    cout<<"For "<<n<<" elements, total number of step counted for Quick Sort: "<<counter_quick<<endl;
    cout<<"\nTime taken: "<<setprecision(5)<<counter_quick/(unit*1.00)<<" ms."<<endl;

    cout<<"For "<<n<<" elements, total number of step counted for Merge Sort: "<<counter_merge<<endl;
    cout<<"\nTime taken: "<<setprecision(5)<<counter_merge/(unit*1.00)<<" ms."<<endl;

}

void quick_sort(int low, int high)
{
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
    int i, j, pivot = a[high], temp;
    i = low-1;
    for(j=low; j<high; j++)
    {

        if(a[j]<pivot)
        {
            counter_quick++;
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = pivot;
    a[high] = temp;

    return i+1;
}

void merge_sort(int left, int right)
{
    if(left>=right)
    {
        return;
    }
    int mid = left + (right-left)/2;

    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
}

void merge(int left, int mid, int right)
{
    int i;
    int index_a, index_l, index_r;
    int size_left, size_right;

    size_left = mid - left +1;
    size_right = right - mid;

    int L[size_left], R[size_right];

    for(i=0; i<size_left; i++)
    {
        L[i] = a2[left+i];
    }

    for(i=0; i<size_right; i++)
    {
        R[i] = a2[mid+1+i];
    }

    index_l = 0;
    index_r = 0;

    for(index_a = left; index_l<size_left && index_r<size_right; index_a++)
    {
        counter_merge++;
        if(L[index_l]<R[index_r])
        {
            a2[index_a] = L[index_l];
            index_l += 1;
        }
        else
        {
            a2[index_a] = R[index_r];
            index_r += 1;
        }
    }

    while(index_l < size_left)
    {
        a2[index_a] = L[index_l];
        index_l += 1;
        index_a += 1;
    }
    while(index_r < size_right)
    {
        a2[index_a] = R[index_r];
        index_r += 1;
        index_a += 1;
    }
}

