TARGETS = check-prime extrema-in-pair extrema-in-triple extrema-in-array summary-of-array summary-of-arithmetic-sequence summary-of-geometic-sequence init-two-sequences reverse-array rotate-array shuffle-array pseudo-vector binary-multiple estimate-square-root

CXXFLAGS = -Wall -Wextra -Werror -O2 -g -std=c++14

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    CXXFLAGS += -DLINUX
endif
ifeq ($(UNAME_S), Darwin)
    CXXFLAGS += -DDARWIN
endif

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
