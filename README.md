# RDRAND_seed
A small tool to get random numbers from the RDRAND hardware RNG present in Intel CPUs 

### Usage
```
make
./example
```

This will run a short program that checks for the presence of the RDRAND instruction in the CPU. 
If available it will seed a standard library Mersenne-Twister PRNG using 624 32-bit
integers taken from the RDRAND hardware RNG.

The program should output something like this:

```
State size of the Mersenne-Twister: 624

Some random numbers...
3882263927
2203886681
1130077512
3213924060
2486026337
598014046
645822272
2367677818
2388906600
4012953650
```

For use in other programs `-mrdrnd` must be added to the compiler flags.

### Requirements

An processor that has the RDRAND instruction. Intel CPUs from Ivy Bridge onwards are compatible.
