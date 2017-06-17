#!/usr/bin/python3
"""
i wrote a lazy test for fib generator
"""
from my_fib import fib

def test1():
    """
    test 1 a simple test
    """
    _fib_list = [1, 1, 2, 3, 5, 8, 13, 21]
    return all([_fib_list[i] == x for i, x in enumerate(fib(len(_fib_list)))])

def test2():
    """
    test 2 a simple test
    """
    _fib_list = [2, 3, 5, 8, 13, 21]
    return all([_fib_list[i] == x for i, x in enumerate(fib(2, 8))])

def main():
    """
    i wrote a lazy test for fib generator
    """
    if test1():
        print("test1 passed")

    if test2():
        print("test2 passed")


if __name__ == "__main__":
    main()
