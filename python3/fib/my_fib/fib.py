#!/usr/bin/python3
"""
This python module has only one function
fib(a,b=None)

"""

def fib(a, b=None):
    """
    Parameters
    ----------
    a, b: integer
    returns i-th number between a, b
    index: 0, 1, 2, 3...
    value: 1, 1, 2, 3....
    """
    _counter = 0
    _f1, _f2 = 0, 1
    if b is None:
        b = a
        a = 0
    while True:
        if _counter > b-1:
            return
        if _counter >= a:
            yield _f2
        _f1, _f2 = _f2, _f2 + _f1
        _counter += 1
