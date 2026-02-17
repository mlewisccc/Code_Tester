#include <iostream>
#include <vector>
#include "ISBNTester.h"
using namespace std;

struct ISBNTester  {
    // IMPLEMENT all the functions here

     // Miguel Implimented this function
    vector<int> ISBNTester::generateFirstNPrimeNumbers(int N) {

        // creates N prime numbers

        int count = 0;
        int num = 50;
        bool isPrime = true;

        vector<int> primeNumberVect;


        while (count < N) {

            // Prime Checker
            for (int i = 2; i < 10; i++) {
                if (num % i == 0) {
                    if (num != i)
                    {
                        isPrime = false;
                        break;
                    }
                }
            }

            // If prime append to vector
            if (isPrime) {
                primeNumberVect.push_back(num);
                count++;
            }

            // Reset for next iteration
            isPrime = true;
            num++;
        }


        return primeNumberVect;
    }

    // Jeff Implimented this function
    // Finds a random number in an integer vector
    int ISBNTester::getRandomNumberInVect(vector<int> primeVect, int N) {
        return primeVect[rand() % N];
    }

    // Jeff Implimented this function
    // Generates an integer vector with x amount of random primes from a list of the first N amount of primes
    vector<int> ISBNTester::generatePrimeNumbers(int N) {
        // Generates first N amount of primes and initializes the output vector
        vector<int> primeNumbers = generateFirstNPrimeNumbers(N);
        vector<int> generatedPrimes;

        // Seeds random
        srand(time(0));

        // x is the random amount of prime numbers to be selected from the prime number vector
        int x = (rand() % N) + 1;

        // adds an initial prime to the output vector to start
        generatedPrimes.push_back(getRandomNumberInVect(primeNumbers, N));

        // count for while statement that increments up to x
        int count = 1;

        // until we have found all x of prime numbers
        while (count < x) {
            // finds a new prime in prime vector
            int newPrime = getRandomNumberInVect(primeNumbers, N);

            // bool that tracks if the new prime exists in the output vector
            bool isInVector = false;

            // for every number in output vector
            for (int i = 0; i < generatedPrimes.size(); i++) {
                // Check if the new prime already exists in output vector
                if (newPrime == generatedPrimes[i]) {
                    isInVector = true;
                }
            }
            // if new prime does not exist in output vector then append it to the output vector and add 1 to count
            if (!isInVector) {
                generatedPrimes.push_back(newPrime);
                count++;
            }
        }
        return generatedPrimes;
    }



};

