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
    // 생성자
    SparsePoly()
    {
        numTerms = 0;
    }

    // 다항식 입력 함수
    void read()
    {
        int count;
        float coeff;
        int exp;

        exponents.clear();
        coefficients.clear();

        cout << "항의 개수를 입력하세요: ";
        cin >> count;


        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (계수 차수): ";
            cin >> coeff >> exp;
            if (coeff != 0.0f)
            {
                coefficients.push_back(coeff);
                exponents.push_back(exp);
            }
        }
        numTerms = exponents.size();
    }


    // 다항식 출력 함수
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

    // 다항식 덧셈 함수
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
