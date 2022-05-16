#include <iostream>
#include <vector>
using namespace std;

vector<int> Create1DVector(vector<vector<vector<int>>>, int, int, int);
int convertIndex(int, int, int, int, int);



int main(int argc, char const* argv[])
{
    int n, m, p, random;
    //take sizes n,m and p from user
    cout << "Enter size of matrix : n(rows) m(columns)  p(depth): ";
    cin >> n >> m >> p;

    //validate input
    if (n <= 0 || m <= 0 || p <= 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    cout << "want to fill the matrix yourself (write 1) or have it filled randomly for you(write 2) " << endl;
    cin >> random;
    vector<vector<vector<int>>> matrix(n, vector<vector<int>>(m, vector<int>(p)));

    if (random == 1)
    {
        cout << "fill the matrix vertically " << endl;
        //create a matrix of size n*m*p and fill it with numbers vertically
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < p; k++)
                {
                    cin >> matrix[k][i][j];
                }
            }
        }
        //show the user the  matrix
        cout << "The matrix : " << endl;
        for (int k = 0; k < p; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << matrix[i][j][k] << " ";
                }
                cout << endl;
            }
        }

    }
    else if (random == 2)
    {
        //create a  matrix of size n*m*p and fill it with random numbers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < p; k++)
                {
                    matrix[i][j][k] = rand() % 1000;
                }
            }
        }
        //show the user the randomized matrix
        cout << "Matrix with random numbers from 0 to 999 : " << endl;
        for (int k = 0; k < p; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << matrix[i][j][k] << " ";
                }
                cout << endl;
            }
        }

    }
    else
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    //flatten the matrix
    vector<int> flat_matrix;
    flat_matrix = Create1DVector(matrix, n, m, p);

    //show the user the flattened matrix
    cout << "Flattened matrix : " << endl;
    for (int i = 0; i < flat_matrix.size(); i++)
    {
        cout << flat_matrix[i] << " ";
    }
    cout << endl;

    //Testing
    //Test the IndexTo1D function by asserting that the flattened matrix is the same as the original matrix
    //vector<vector<vector<int>>> matrix_test(n, vector<vector<int>>(m, vector<int>(p)));
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++)
    //    {
    //        for (int k = 0; k < p; k++)
    //        {
    //            matrix_test[i][j][k] = flat_matrix[convertIndex(i, j, k, n, m)];
    //        }
    //    }
    //}
    //cout << "Matrix Test : " << endl;
    ////print the test matrix
    //for (int k = 0; k < p; k++)
    //{
    //    for (int i = 0; i < n; i++)
    //    {
    //        for (int j = 0; j < m; j++)
    //        {
    //            cout << matrix_test[i][j][k] << " ";
    //        }
    //        cout << endl;
    //    }
    //}

    ////make sure that matrix test is equal to the original matrix
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++)
    //    {
    //        for (int k = 0; k < p; k++)
    //        {
    //            if (matrix[i][j][k] != matrix_test[i][j][k])
    //            {
    //                cout << "Error in matrix test" << endl;
    //                return 0;
    //            }
    //        }
    //    }
    //}
    //cout << "Matrix test passed" << endl;
    //cout << "press any key to exit" << endl;
    //return 0;
}

//create a 1D vector to store flattened matrix
//parameters:
//matrix: the matrix to be flattened
//return: a 1D vector containing the flattened matrix
vector<int> Create1DVector(vector<vector<vector<int>>> matrix, int n, int m, int p)
{
    vector<int> flat_vector(n * m * p);
    int index = 0;  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                index = convertIndex(i, j, k, n, m);
                flat_vector[index] = matrix[i][j][k];
                index++;
            }
        }
    }
    return flat_vector;
}

//convert 3D indexes (i,j,k) to 1D index y =  k*n*m + i*m + j
//parameters:
//i: row index
//j: column index
//k: layer index
//return: 1D index y
int convertIndex(int i, int j, int k, int n, int m)
{
    return k * n * m + i * m + j;
}