#include <bits/stdc++.h>

using namespace std;

int NumberCompare(string firstNumber, string secondNumber)
{
    while(firstNumber[0] == 48)
    {
        firstNumber.erase(0, 1);
    }
    while(secondNumber[0] == 48)
    {
        secondNumber.erase(0, 1);
    }

    int fristLength = firstNumber.size();
    int secondLength = secondNumber.size();

    if(fristLength > secondLength)
    {
        return 1;
    }
    else if(fristLength < secondLength)
    {
        return -1;
    }
    else
    {
        for(int i=0 ; i<fristLength ; i++ )
        {
            if(firstNumber[i] > secondNumber[i])
            {
                return 1;
            }
            else if(firstNumber[i] < secondNumber[i])
            {
                return -1;
            }
        }
    }

    return 0;
}

string SingleDigitMultiplication(string number, int mulplier)
{
    if(mulplier == 0) return "";

    int i = number.size() -1;
    int tmp, carry = 0;
    while( i >= 0)
    {
        tmp = (number[i]-48)*mulplier + carry;
        number[i] = (tmp%10) + 48;
        carry = tmp / 10;
        i--;
    }

    if(carry > 0)
    {
        string tmp;
        tmp.push_back(carry+48);
        number.insert(0,tmp);
    }

    return number;
}

string Subtraction(string num1, string num2)
{
    string result;
    string tmp;

    for(int i = num2.size() ; i < num1.size() ; i++ )
    {
        num2.insert(0,"0");
    }

    for( int i = num1.size() -1 ; i >= 0 ; i--)
    {
        tmp.clear();
        if(num1[i] < num2[i])
        {
            tmp.push_back(num1[i]+10-num2[i]+48);
            num1[i-1]--;
            result.insert(0,tmp);
        }
        else
        {
            tmp.push_back(num1[i]-num2[i]+48);
            result.insert(0,tmp);
        }
    }

    while(result[0] == 48)
    {
        result.erase(0, 1);
    }

    return result;
}

void Division(string num1, string num2)
{
    string tmp, result , red;
    int i=0;

    while(i < num1.size())
    {
        tmp.push_back(num1[i]);
        if(NumberCompare(tmp, num2) >= 0)
        {
            break;
        }
        i++;
    }

    string tmp2;
    while(i < num1.size())
    {
        int k;
        for( k = 0 ; k<=10 ; k++)
        {
            tmp2 = SingleDigitMultiplication(num2, k);
            if(NumberCompare(tmp2, tmp) > 0)
            {
                result.push_back(k+47);
                break;
            }
        }
        tmp = Subtraction(tmp, SingleDigitMultiplication(num2, k-1));
        i++;
        tmp.push_back(num1[i]);
    }

    cout << result << endl;
    cout << tmp << endl;

}

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    Division(num1, num2);

    return 0;
}
