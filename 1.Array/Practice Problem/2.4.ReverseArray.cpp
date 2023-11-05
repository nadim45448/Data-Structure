#include <iostream>
using namespace std;

int main()
{
  int row, col;
  cout << "Enter the row,col size of the matrix: ";
  cin >> row >> col;

  int matrix[row][col], reversed_matrix[row][col];

  // Read the elements of the matrix
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> matrix[i][j];
    }
  }

  // Reverse the matrix
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col / 2; j++)
    {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][col - j - 1];
      matrix[i][col - j - 1] = temp;
    }
  }

  // Display the reversed matrix
  cout << "The reversed matrix is: " << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
