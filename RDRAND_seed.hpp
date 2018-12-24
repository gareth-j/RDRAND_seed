#include <cstdio>
#include <assert.h>
#include <immintrin.h>
#include <cpuid.h>

class RDRAND_seed
{
	using rd64_type = long long unsigned int;

public:
	RDRAND_seed() 
	{
		// May not be the nicest way
		assert(supports_rdrand());
		
		// Check we don't just get a zero
		rd64_type temp;		
		unsigned int temp32;
		assert(_rdrand32_step(&temp32) != 0 and _rdrand64_step(&temp) != 0);
	}

	template <typename Iter>
	void generate(Iter begin, Iter end)
	{
		for(; begin != end; ++begin)
			*begin = get_rand32();

	}

	template <typename Iter>
	void generate64(Iter begin, Iter end)
	{
		for(; begin != end; ++begin)
			*begin = get_rand64();

	}

	uint32_t get_rand32()
	{
		return static_cast<uint32_t>(get_rdrand32());
	}

	uint64_t get_rand64()
	{
		return static_cast<uint64_t>(get_rdrand64());
	}

	uint32_t operator()()
	{
		return get_rand32();
	}

private:
	unsigned int get_rdrand32()
	{
		unsigned int rand;
		_rdrand32_step(&rand);
		return rand;
	}

	rd64_type get_rdrand64()
	{
		rd64_type rand;
		_rdrand64_step(&rand);
		return rand;
	}

	bool supports_rdrand()
	{	
		// For comparison with bit 30 of the ECX register
		const unsigned int flag_RDRAND = (1 << 30);
		// Hold information from the registers
		unsigned int eax, ebx, ecx, edx;
		// Returns cpuid data for cpuid leaf 1
		__get_cpuid(1, &eax, &ebx, &ecx, &edx);

		// Bitwise AND what we get from the ecx register and the RDRAND flag
		return ((ecx & flag_RDRAND) == flag_RDRAND);
	}
};

