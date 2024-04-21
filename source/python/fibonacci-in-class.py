#!/usr/bin/python3

class FibIterator(object):
    def __init__(self):
        self.a = 0
        self.b = 1

    def __next__(self):
        r = self.a
        self.a, self.b = self.b, self.a + self.b
        return r

class Fibonacci(object):
    def __init__(self):
        pass

    def make_list(self, maxn):
        l = []
        a, b = 0, 1
        while a <= maxn:
            l += (a, )
            if a == maxn or b > maxn:
                break
            a, b = b, a + b
        return l

    def __iter__(self):
        return FibIterator()

fib = Fibonacci()

print("Use make_list() to generate Fibonacci numbers less than 50:")
fibs = fib.make_list(50)
for x in fibs:
    print(x)

print("Use iter() and next() to generate Fibonacci numbers less than 50:")
it = iter(fib)
while True:
    x = next(it)
    if x > 50:
        break
    print(x)

print("Use `for x in iterable` statment to generate Fibonacci numbers less than 50:")
for x in fib:
    if x > 50:
        break
    print(x)

