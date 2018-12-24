#include <iostream>
#include <vector>
#include <random>

#include "RDRAND_seed.hpp"

int main()
{
	RDRAND_seed seeder;

	// The Mersenne-Twister needs a lot of seeding
	std::vector<uint32_t> seed_vec(std::mt19937::state_size);

	std::cout << "\nState size of the Mersenne-Twister: " << std::mt19937::state_size << "\n\n";

	seeder.generate(seed_vec.begin(), seed_vec.end());

	// Copy the values into the seed_seq object
	std::seed_seq seq(seed_vec.begin(), seed_vec.end());

	// See the MT generator
	std::mt19937 generator(seq);

	// Get some random numbers!
	std::cout << "Some random numbers...\n";
	for(int i = 0; i < 10; ++i)
		std::cout << generator() << "\n";
}