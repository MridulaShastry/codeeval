#include <iostream>

using namespace std;

int is_prime(int n)
{
  for(int i = 2; i <n; i++)
  {
    if(n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int sum_of_primes = 2;
  int number_of_primes = 1;
  int i = 3;
	while(number_of_primes < 1000)
  {
    if(is_prime(i))
    {
      sum_of_primes += i;
      number_of_primes++; 
    }
    i++;
  }

  cout << sum_of_primes << endl;
  return 0;
}