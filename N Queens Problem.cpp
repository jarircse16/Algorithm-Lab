#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define PII pair<ll int, ll int>
#define fast_io ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define loop_in for(int i=0; i<n; i++)

bool solve();
bool is_safe(int row, int col);
void print();


ll board[100][100], n;


int main()
{
    fast_io
    printf("Enter board dimension: ");
    cin>>n;
    cout<<endl;
    solve();
}
bool solve()
{
    memset(board, 0, sizeof(board));

}

bool is_safe(int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void print()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<" "<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
