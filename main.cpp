#include <iostream>
#include <cmath>

class solution {
public:
  int countDigitOne(int n) {
    int result = 0;
    int numDigits = getNumDigits(n);
    int firstDigit = getFirstDigit(n);
    if (numDigits == 1) {
      if (firstDigit >= 1)
	result = 1;
    }
    else if (numDigits > 1){
      int remainder = n - firstDigit*pow(10, numDigits-1);
      for (int k = numDigits-1; k>0 ; k--)
	result += numOnesWithNDigits(k);
      if (firstDigit > 1)
	result += pow(10, numDigits-1)+(firstDigit-1)*numOnesWithNDigits(numDigits-1);
      else
	result += remainder+1;

      result += countDigitOne(remainder);
    }
    return result;
  }

private:
  int numOnesWithNDigits(int numDigits) {
    int result;
    if (numDigits == 1)
      result = 1;
    else if (numDigits == 2)
      result = pow(10, numDigits-1)+pow(9, numDigits-1);
    else
      result = pow(10, numDigits-1)+9*numOnesWithNDigits(numDigits-1);
    return result;
  }
  
  int getNumDigits(int n) {
    int result = 0;
    while (n > 0){
      result++;
      n /= 10;
    }      
    return result;
  }

  int getFirstDigit(int n) {
    while (n/10 > 0)
      n /= 10;
    return n;
  }
};

int main() {
  int num = 99;

  solution soln;
  auto result = soln.countDigitOne(num);

  std::cout << "The total number of digit 1 in all the non-negative integers less than or equal to " << num << " is:" << std::endl;
  std::cout << result << std::endl;

  return 0;
}
