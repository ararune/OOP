#include <iostream>
#include <iomanip>
using namespace std;
// A program for addition, subtraction, multiplication and transposing a matrix
struct Matrix {
    int row;
    int column;
    float** matrix;

    void createMatrix(int row, int column) {
        this->row = row;
        this->column = column;
        this->matrix = new float* [this->row];
        for (int i = 0; i < this->row; i++) 
            this->matrix[i] = new float[this->column];
    }
    void generateMatrix(int a, int b) {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->column; j++)
                this->matrix[i][j] = float(a + (rand() % (b - a + 1)));
    }
    void printMatrix()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                cout << right << setfill('0') << fixed << setprecision(4) << this->matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void inputMatrix()
    {
        int i, j;
        cout << "Input matrix : " << endl;
        for (i = 0; i < this->row; i++)
        {
            for (j = 0; j < this->column; j++)
            {
                cin >> this->matrix[i][j];
            }
        }
    }
};

Matrix addMatrices(Matrix m1, Matrix m2) {
    if (m1.row == m2.row && m1.column == m2.column) {
        Matrix m3;
        m3.createMatrix(m1.row, m1.column);
        cout << "\nThe sum of matrices : \n";
        for (int i = 0; i < m3.row; i++)
            for (int j = 0; j < m3.column; j++)
                m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        return m3;
    }
    else
    {
        cout << "\nMatrices don't have the same dimensions";
        exit(1);
    }

}
Matrix subtractMatrices(Matrix m1, Matrix m2) {
    if (m1.row == m2.row && m1.column == m2.column) {
        Matrix m3;
        m3.createMatrix(m1.row, m1.column);
        cout << "\nThe difference between matrices : \n";
        for (int i = 0; i < m3.row; i++)
            for (int j = 0; j < m3.column; j++)
                m3.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
        return m3;
    }
    else
    {
        cout << "\nMatrices don't have the same dimensions";
        exit(1);
    }

}
Matrix multiplyMatrices(Matrix m1, Matrix m2) {
    if (m1.column == m2.row) {
        Matrix m3;
        m3.createMatrix(m1.row, m1.column);

        for (int i = 0; i < m1.row; ++i)
        {
            for (int j = 0; j < m2.column; ++j)
            {
                m3.matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < m1.row; i++)
            for (int j = 0; j < m2.column; j++)
                for (int k = 0; k < m2.row; k++)
                    m3.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];

        cout << "\nThe product of multiplied matrices : " << endl;
        for (int i = 0; i < m1.row; i++)
        {
            for (int j = 0; j < m2.column; j++)
            {
                cout << m3.matrix[i][j] << " ";
            }
            cout << endl;
        }
        return m3;
    }
    else
    {
        cout << "\nThe matrices cannot be multiplied" << endl;
        exit(1);
    }
}
Matrix transposeMatrix(Matrix m1) {
    Matrix mT;
    mT.createMatrix(m1.row, m1.column);
    cout << "\nThe transposed matrix : \n";
    for (int i = 0; i < mT.row; i++)
        for (int j = 0; j < mT.column; j++)
            mT.matrix[j][i] = m1.matrix[i][j];
    return mT;
}



int main()
{
    srand(time(NULL));
    Matrix m1, m2, m3, m4, mprod;
    int a, b;
    cout << "Enter lower limit : ";
    cin >> a;
    cout << "Enter upper limit : ";
    cin >> b;


    m1.createMatrix(2, 2);
    m1.inputMatrix();
    cout << "Input matrix : \n";
    m1.printMatrix();

    m4 = transposeMatrix(m1);
    m4.printMatrix();

    m2.createMatrix(2, 3);
    m2.generateMatrix(a, b);
    cout << "\nGenerated matrix :\n ";
    m2.printMatrix();

    mprod = multiplyMatrices(m1, m2);

    m3 = addMatrices(m1, m2);
    m3.printMatrix();

    m3 = subtractMatrices(m1, m2);
    m3.printMatrix();

}
