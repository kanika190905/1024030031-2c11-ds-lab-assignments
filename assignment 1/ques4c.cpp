#include<iostream>
using namespace std;

void input(int mat[100][100], int rows, int cols) {
    cout << "enter elements:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}
void transpose(int mat[100][100], int trans[100][100], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
}
void display(int mat[100][100], int rows, int cols) {
    cout << "matrix\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int mat[100][100], trans[100][100];
    int rows, cols;
	cout << "enter number of rows and columns  ";
    cin >> rows >> cols;
	input(mat, rows, cols);
    transpose(mat, trans, rows, cols);
    cout << "\ntransposed matrix:\n";
    display(trans, cols, rows); 

    return 0;
}

