TARGETS = check-prime-plain check-prime-optimized prime-numbers-sieve-plain prime-numbers-sieve-eratosthenes prime-numbers-sieve-eratosthenes-optimized prime-numbers-sieve-euler prime-numbers-sieve-euler-optimized primality-test-fermat primality-test-miller-rabin

CXXFLAGS = -Wall -Wextra -Werror -O2 -g -std=c++14

ifeq ($(CXX), g++)
    CXXFLAGS += -fmax-errors=10
else ifeq ($(CXX), clang++)
    CXXFLAGS += -ferror-limit=10
endif

all:$(TARGETS)

$(TARGETS):%:%.o
	$(CXX) -o $@ $<

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGETS)
