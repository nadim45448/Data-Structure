#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the dimensions of the matrix: ";
    cin >> m >> n;

    int matrix[m][n];
    int unique_elements[m * n];
    int unique_element_count = 0;

    // Read the elements of the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Iterate over the matrix and replace all duplicate integers with -1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool is_duplicate = false;
            for (int k = 0; k < unique_element_count; k++)
            {
                if (matrix[i][j] == unique_elements[k])
                {
                    is_duplicate = true;
                    break;
                }
            }

            if (is_duplicate)
            {
                matrix[i][j] = -1;
            }
            else
            {
                unique_elements[unique_element_count++] = matrix[i][j];
            }
        }
    }

    // Copy the unique elements from the temporary array back to the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = unique_elements[j];
        }
    }

    // Display the matrix
    cout << "The matrix with duplicate integers replaced with -1 is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

  return 0;
}
