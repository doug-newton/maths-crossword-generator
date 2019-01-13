#ifndef FACTORFINDER_H
#define FACTORFINDER_H

#include <vector>

class FactorFinder {

	public:
		FactorFinder();

		void findFactors(int number, int &outFactorA, int &outFactorB);
		void findAllFactors(int number,std::vector<int> &outFactorList);

		void showAllPrimes();

		bool isPrime(int number);

	private:
		/*	Store all primes for later calculation
		 */
		static std::vector<int> primes;
		static bool primesFound;
		static void findPrimes(int max=1000);
};

#endif
