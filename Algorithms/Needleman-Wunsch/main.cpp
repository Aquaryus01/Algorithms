#include <iostream>
#include <cstring>

using namespace std;


void create_borders(int mat[100][100], int n, int m){
/*
    Description: Create borders for matrix
    In:          Matrix mat, int n, int m
    Out:         None
    Result:      Modified matrix with borders
*/
    for(int i=1; i<=n; i++)
        mat[i][0] = -i;

    for(int i=1; i<=m; i++)
        mat[0][i] = -i;
}

int maximum_value(int a, int b, int c){
    /*
    Description: Maximum of 3 value
    In:          int a, int b, int c
    Out:         int
    Result:      Maximum from 3 value
*/
    return max(max(a,b),c);
}

void needleman_wunsch(int mat[100][100], char s1[100], char s2[100]){
    /*
    Description: Complete the matrix using Needleman Wunsch algorithm
    In:          Matrix mat, string s1, string s2
    Out:         Modified matrix
    Result:      Modified matrix using Needleman Wunsch algorithm
*/
    int n = strlen(s1);
    int m = strlen(s2);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            int approach;

            if(s1[i-1]==s2[j-1]){
                approach = 1;
            }
            else{
                approach = -1;
            }

            mat[i][j] = maximum_value(mat[i-1][j-1]+approach, mat[i][j-1]+approach, mat[i-1][j]+approach);
        }
}

void read(char s1[100], char s2[100]){
    cout<<"First string:\n";
    cin.getline(s1, 100);
    cout<<"Second string:\n";
    cin.getline(s2, 100);
}

void show_matrix(int mat[100][100], int n, int m){
    /*
        Description: show matrix
        In:          matrix mat, int n, int m
        Out:         nothing
        Result:      show matrix
    */
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    char s1[100];
    char s2[100];
    int mat[100][100], n, m;

    read(s1, s2);

    n= strlen(s1);
    m= strlen(s2);

    create_borders(mat, n, m);
    needleman_wunsch(mat, s1, s2);
    show_matrix(mat, n, m);
}
