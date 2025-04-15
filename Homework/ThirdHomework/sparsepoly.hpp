#pragma once
#include <iostream>
#include <vector>

#define MAX_DEGREE 101
using namespace std;

class SparsePoly
{
    int numTerms;
    vector<int> exponents;
    vector<float> coefficients;

public:
    // ������
    SparsePoly()
    {
        numTerms = 0;
    }

    // ���׽� �Է� �Լ�
    void read()
    {
        int count;
        float coeff;
        int exp;

        exponents.clear();
        coefficients.clear();

        cout << "���� ������ �Է��ϼ���: ";
        cin >> count;


        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << "��° ���� ����� ������ �Է��ϼ��� (��� ����): ";
            cin >> coeff >> exp;
            if (coeff != 0.0f)
            {
                coefficients.push_back(coeff);
                exponents.push_back(exp);
            }
        }
        numTerms = exponents.size();
    }


    // ���׽� ��� �Լ�
    void display(const char* str)
    {
        cout << str << ": ";
        for (int i = 0; i < numTerms; i++)
        {
            if (i != 0)
                cout << " + ";
            cout << coefficients[i] << " * x^" << exponents[i];
        }
        cout << endl;
    }

    // ���׽� ���� �Լ�
    void add(const SparsePoly& a, const SparsePoly& b)
    {
        exponents.clear();
        coefficients.clear();
        numTerms = 0;

        int i = 0, j = 0;

        while (i < a.numTerms && j < b.numTerms)
        {
            if (a.exponents[i] > b.exponents[j])
            {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                i++;
            }
            else if (a.exponents[i] < b.exponents[j])
            {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                j++;
            }
            else
            {
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0.0f)
                {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sum);
                }
                i++;
                j++;
            }
            numTerms = exponents.size();
        }

        while (i < a.numTerms)
        {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            i++;
            numTerms++;
        }

        while (j < b.numTerms)
        {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            j++;
            numTerms++;
        }
    }
};
