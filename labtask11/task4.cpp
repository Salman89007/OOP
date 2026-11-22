#include <iostream>
#include <iomanip>
using namespace std;

class Polynomial
{
private:
    double *coeffs;
    int degree;

public:
    Polynomial(int deg, const double *initCoeffs)
    {
        degree = deg;
        coeffs = new double[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            coeffs[i] = initCoeffs[i];
        }
    }

    Polynomial(const Polynomial &rhs)
    {
        degree = rhs.degree;
        coeffs = new double[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            coeffs[i] = rhs.coeffs[i];
        }
    }

    ~Polynomial()
    {
        delete[] coeffs;
    }

    Polynomial &operator=(const Polynomial &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        delete[] coeffs;

        degree = rhs.degree;
        coeffs = new double[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            coeffs[i] = rhs.coeffs[i];
        }

        return *this;
    }

    Polynomial operator+(const Polynomial &rhs)
    {
        int maxDegree;

        if (degree > rhs.degree)
        {
            maxDegree = degree;
        }
        else
        {
            maxDegree = rhs.degree;
        }

        double *tempCoeffs = new double[maxDegree + 1];

        for (int i = 0; i <= maxDegree; i++)
        {
            double a = 0.0;
            double b = 0.0;

            if (i <= degree)
            {
                a = coeffs[i];
            }

            if (i <= rhs.degree)
            {
                b = rhs.coeffs[i];
            }

            tempCoeffs[i] = a + b;
        }

        Polynomial temp(maxDegree, tempCoeffs);

        delete[] tempCoeffs;

        return temp;
    }

    Polynomial operator-(const Polynomial &rhs)
    {
        int maxDegree;

        if (degree > rhs.degree)
        {
            maxDegree = degree;
        }
        else
        {
            maxDegree = rhs.degree;
        }

        double *tempCoeffs = new double[maxDegree + 1];

        for (int i = 0; i <= maxDegree; i++)
        {
            double a = 0.0;
            double b = 0.0;

            if (i <= degree)
            {
                a = coeffs[i];
            }

            if (i <= rhs.degree)
            {
                b = rhs.coeffs[i];
            }

            tempCoeffs[i] = a - b;
        }

        Polynomial temp(maxDegree, tempCoeffs);

        delete[] tempCoeffs;

        return temp;
    }

    Polynomial operator*(double scalar)
    {
        double *tempCoeffs = new double[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            tempCoeffs[i] = coeffs[i] * scalar;
        }

        Polynomial temp(degree, tempCoeffs);

        delete[] tempCoeffs;

        return temp;
    }

    friend Polynomial operator*(double scalar, const Polynomial &p)
    {
        double *tempCoeffs = new double[p.degree + 1];

        for (int i = 0; i <= p.degree; i++)
        {
            tempCoeffs[i] = p.coeffs[i] * scalar;
        }

        Polynomial temp(p.degree, tempCoeffs);

        delete[] tempCoeffs;

        return temp;
    }

    double operator()(double x) const
    {
        double result = 0.0;
        double power = 1.0;

        for (int i = 0; i <= degree; i++)
        {
            result += coeffs[i] * power;
            power *= x;
        }

        return result;
    }

    friend ostream &operator<<(ostream &out, const Polynomial &p)
    {
        bool first = true;

        for (int i = p.degree; i >= 0; i--)
        {
            if (p.coeffs[i] == 0)
            {
                continue;
            }

            if (!first)
            {
                if (p.coeffs[i] > 0)
                {
                    out << " + ";
                }
                else
                {
                    out << " - ";
                }
            }
            else
            {
                if (p.coeffs[i] < 0)
                {
                    out << "-";
                }
            }

            double value = p.coeffs[i];

            if (value < 0)
            {
                value = -value;
            }

            out << value;

            if (i == 1)
            {
                out << "x";
            }
            else if (i > 1)
            {
                out << "x^" << i;
            }

            first = false;
        }

        if (first)
        {
            out << "0";
        }

        return out;
    }
};

int main()
{
    double c1[] = {-5, 2, 3};
    Polynomial P1(2, c1);

    double c2[] = {6, 0, 2, 4};
    Polynomial P2(3, c2);

    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;

    Polynomial P3 = (2.0 * P1) + P2;

    cout << "P3: " << P3 << endl;

    double result = P3(3.0);

    cout << "P3(3.0) = " << result << endl;

    Polynomial P4 = P1 - P2;
    cout << "P1 - P2: " << P4 << endl;

    Polynomial P5 = P1 * 3.5;
    cout << "P1 * 3.5: " << P5 << endl;
    return 0;
}
