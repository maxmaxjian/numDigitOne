/*
 * source.cpp
 *
 *  Created on: Aug 3, 2016
 */

#include <iostream>
#include <cmath>

class solution {
  public:
    int countDigitOne(int n) {
        int result = 0;
        int firstDigit = getFirstDigit(n);
        int numDigits = getNumDigits(n);
        if (numDigits == 1) {
            if (firstDigit >= 1)
                result = 1;
        }
        else if (numDigits > 1) {
            int remainder = n - firstDigit*pow(10, numDigits-1);

            for (int k = 1; k < numDigits; k++)
                result += numOneInNDigitNumbers(k);
            
            if (firstDigit > 1) {
                int sum = 0;
                for (int k = 1; k < numDigits; k++)
                    sum += numOneInNDigitNumbers(k);
                result += pow(10, numDigits-1)+(firstDigit-1)*sum;
            }
            else
                result += remainder+1;

            result += countDigitOne(remainder);
        }
        return result;
    }
	
  private:
    int numOneInNDigitNumbers(int numDigits) {
        int result;
        if (numDigits == 1)
            result = 1;
        else if (numDigits == 2)
            result = pow(10, numDigits-1) + pow(9, numDigits-1);
        else {
            result = pow(10, numDigits-1);
            int sum = 0;
            for (int k = 1; k < numDigits; k++)
                sum += numOneInNDigitNumbers(k);
            result += 9*sum;
        }
        return result;
    }
	
    int getNumDigits(int n) {
        int numDigits = 0;
        while (n > 0) {
            numDigits++;
            n /= 10;
        }
        return numDigits;
    }
	
    int getFirstDigit(int n) {
        while (n/10 > 0)
            n /= 10;
        return n;
    }
};

class answer
{
  public:
    int countDigitOne(int n) {
        int res = 0;
        int m = 0;
        for (long long i = 1; i <= n; i*=10) {
            int d = n%(i*10)/i;
            res += d*m + (d==1)*(n%i+1)+(d>1)*i;
            m = m*10+i;
        }
        return res;
    }
};

int main()
{
    int num = 10000;
    solution soln;
	
    std::cout << "The number of digit one in the number " << num << " is:\n";
    std::cout << soln.countDigitOne(num) << std::endl;

    answer ans;
    std::cout << "The answer is:" << std::endl;
    std::cout << ans.countDigitOne(num) << std::endl;
}
