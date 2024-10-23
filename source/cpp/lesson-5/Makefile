TARGETS = rectangle shapes template overload cout-flags cin-getline fstream strtoull array vector iterator transform sort areas-refactored find-longest-word primes amicable-pairs dn-on dn-on-optimized

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
	rm -f *.o test.* $(TARGETS)
