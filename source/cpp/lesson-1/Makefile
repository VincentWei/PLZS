TARGETS = empty arithmetic-operators hello-world ull-mode function numeric-types variables rounded-addition sqrt areas errors

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
