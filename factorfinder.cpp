#include "factorfinder.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>

std::vector<int> FactorFinder::primes;
bool FactorFinder::primesFound = false;

FactorFinder::FactorFinder()
{
}

void FactorFinder::findAllFactors(int number, std::vector<int> &outFactorList) {
	if (!primesFound) findPrimes();
	for (int p: primes) {
		while (number%p == 0) {
			number /= p;
			outFactorList.push_back(p);
		}
	}
}

void FactorFinder::findFactors(int number, int &outFactorA, int &outFactorB) {
	if (!primesFound) findPrimes();

	std::vector<int> allFactors;
	findAllFactors(number, allFactors);

	outFactorA = 1;
	outFactorB = 1;

	for (int factor: allFactors) {
		if (outFactorA == 1) {
			outFactorA *= factor;
			continue;
		} else if (outFactorB == 1) {
			outFactorB *= factor;
			continue;
		}

		if (rand()%2 == 0)
			outFactorA *= factor;
		else
			outFactorB *= factor;
	}
}

void FactorFinder::findPrimes(int max) {
	primes.push_back(2);

	for (int i=3; i<max; i++) {
		bool isPrime = true;
		for (int p: primes) {
			if (p > sqrt(i)) break;
			if (i%p==0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(i);
		}
	}

	primesFound = true;
}

void FactorFinder::showAllPrimes() {
	for (int p: primes) {
	}
}

bool FactorFinder::isPrime(int number) {
	if (!primesFound) findPrimes();
	int root = ceil(sqrt(number));
	for (int prime: primes) {
		if (number%prime == 0) return false;
		if (prime > root) break;
	}
	return true;
}

int sdfasdfadsfasdfasdf() {
//	int main() {
	srand(time(0));
	FactorFinder factorFinder;
	int number = 3072;
	int a(0),b(0);

	factorFinder.findFactors(number,a,b);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}
