#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff;
    int max = 0;
    static int maxD;

    Polynomial()
    {
        this->degCoeff = new int[20];
        for (int i = 0; i < 20; i++)
            degCoeff[i] = 0;
    }

    Polynomial(Polynomial const &p)
    {
        maxD = p.max;
        int *newdeg = new int[maxD + 1];

        for (int i = 0; i <= maxD; i++)
            newdeg[i] = p.degCoeff[i];

        this->degCoeff = newdeg;
    }

    void setCoefficient(int deg, int coef)
    {
        degCoeff[deg] = coef;
        if (max < deg)
            max = deg;
    }

    int mDegree(Polynomial const &p) const
    {
        if ((this->max) > (p.max))
            return this->max;
        else
            return p.max;
    }

    Polynomial operator+(Polynomial const &p)
    {
        maxD = mDegree(p);
        Polynomial res;
        for (int i = 0; i <= maxD; i++)
        {
            res.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
        }
        return res;
    }

    Polynomial operator-(Polynomial const &p)
    {
        maxD = mDegree(p);
        Polynomial res;
        for (int i = 0; i <= maxD; i++)
        {
            res.degCoeff[i] = this->degCoeff[i] - p.degCoeff[i];
        }
        return res;
    }

    Polynomial operator*(Polynomial const &p)
    {
        maxD = (max + p.max);
        Polynomial res;
        for (int i = 0; i <= maxD; i++)
        {
            res.degCoeff[i] = 0;
        }
        for (int i = 0; i <= max; i++)
        {
            for (int j = 0; j <= p.max; j++)
            {
                res.degCoeff[i + j] += this->degCoeff[i] * p.degCoeff[j];
            }
        }
        return res;
    }

    void operator=(Polynomial const &p){
        maxD = p.max;
        int *newdeg = new int[maxD + 1];

        for (int i = 0; i <= maxD; i++)
            newdeg[i] = p.degCoeff[i];

        this->degCoeff = newdeg;
    }

    void print()
    {
        for (int i = 0; i <= maxD; i++)
        {
            if (degCoeff[i] != 0)
                cout << degCoeff[i] << "x" << i << " ";
        }
    }
};

int Polynomial ::maxD = 0;

int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice)
    {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}