#include <iostream>
#include <math.h>

using namespace std;

long long gcd(long long a, long long b) {
  if (a == 0) return b;
  else if (b == 0) return a;
  if (a < b) return gcd(a, b % a);
  else return gcd(b, a % b);
}

void decimalToFraction(double number) {
  // Fetch integral value of the decimal.
  double intVal = floor(number);

  // Get the fractional part of the decimal.
  double frac = number - intVal;

  // Multiply the fractional part by 10^9 to get a large integer.
  long long fracInt = (long long)(frac * 1000000000);

  // Calculate the GCD of the fractional part and 10^9.
  long long gc = gcd(fracInt, 1000000000);

  // The numerator is the fractional part divided by the GCD.
  long long numerator = fracInt / gc;

  // The denominator is 10^9 divided by the GCD.
  long long denominator = 1000000000 / gc;

  // Print the irreducible fraction.
  cout << intVal << " / " << denominator << endl;
}

int main() {
  double number = 0.33;
  decimalToFraction(number);
  return 0;
}

