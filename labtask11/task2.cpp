
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Matrix
{
private:
    double **grid;
    int rows;
    int cols;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        grid = new double *[rows];

        for (int i = 0; i < rows; i++)
        {
            grid[i] = new double[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                grid[i][j] = 0.0;
            }
        }
    }

    Matrix(const Matrix &rhs)
    {
        rows = rhs.rows;
        cols = rhs.cols;

        grid = new double *[rows];

        for (int i = 0; i < rows; i++)
        {
            grid[i] = new double[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                grid[i][j] = rhs.grid[i][j];
            }
        }
    }

    // Destructor
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
    }

    Matrix &operator=(const Matrix &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        for (int i = 0; i < rows; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;

        rows = rhs.rows;
        cols = rhs.cols;

        grid = new double *[rows];

        for (int i = 0; i < rows; i++)
        {
            grid[i] = new double[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                grid[i][j] = rhs.grid[i][j];
            }
        }

        return *this;
    }

    double &operator()(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Invalid matrix index!");
        }

        return grid[r][c];
    }

    // Matrix Addition
    Matrix operator+(const Matrix &rhs)
    {
        if (rows != rhs.rows || cols != rhs.cols)
        {
            throw invalid_argument("Matrix dimensions do not match!");
        }

        Matrix temp(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.grid[i][j] = grid[i][j] + rhs.grid[i][j];
            }
        }

        return temp;
    }

    // Matrix Multiplication
    Matrix operator*(const Matrix &rhs)
    {
        if (cols != rhs.rows)
        {
            throw invalid_argument("Matrix dimensions are incompatible!");
        }

        Matrix temp(rows, rhs.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    temp.grid[i][j] += grid[i][k] * rhs.grid[k][j];
                }
            }
        }

        return temp;
    }

    friend ostream &operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                out << setw(10) << fixed << setprecision(2) << m.grid[i][j];
            }
            out << endl;
        }
        return out;
    }
};

int main()
{

    try
    {
        Matrix m1(2, 3);
        Matrix m2(3, 2);

        m1(0, 0) = 1;
        m1(0, 1) = 2;
        m1(0, 2) = 3;

        m1(1, 0) = 4;
        m1(1, 1) = 5;
        m1(1, 2) = 6;

        m2(0, 0) = 7;
        m2(0, 1) = 8;

        m2(1, 0) = 9;
        m2(1, 1) = 10;

        m2(2, 0) = 11;
        m2(2, 1) = 12;

        cout << "Matrix 1:" << endl;
        cout << m1 << endl;

        cout << "Matrix 2:" << endl;
        cout << m2 << endl;

        Matrix m3 = m1 * m2;

        cout << "Multiplication Result:" << endl;
        cout << m3 << endl;

        Matrix m4(2, 3);
        m4(0, 0) = 10;
        m4(0, 1) = 20;
        m4(0, 2) = 30;
        m4(1, 0) = 40;
        m4(1, 1) = 50;
        m4(1, 2) = 60;

        Matrix m5 = m1 + m4;

        cout << "Addition Result:" << endl;
        cout << m5 << endl;

        Matrix m6(2, 3);
        m6 = m1;

        cout << "Copied Matrix:" << endl;
        cout << m6 << endl;

        m6(0, 0) = 999;

        cout << "After modifying copied matrix:" << endl;

        cout << "Original Matrix:" << endl;
        cout << m1 << endl;

        cout << "Copied Matrix:" << endl;
        cout << m6 << endl;
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
