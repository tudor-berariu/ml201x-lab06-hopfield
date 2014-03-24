#!/usr/bin/python

# Copyright (C) 2014 Tudor Berariu
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

from random import random

WIDTH = 12                      # The width of a pattern
HEIGHT = 10                     # The height of a pattern
N = WIDTH * HEIGHT;             # The number of cells in a pattern
ALL = 10                        # The number of all different patterns

VALUE_OF = {'_' : -1, 'x' : 1}
CHAR = {-1 : '_', 1 : 'x'}


def read_digits(digits_no):
    """Returns the first digits_no patterns from file 'digits'
    as 120 character long lists of 1 and -1"""
    digits_no = min(digits_no, ALL)
    patterns = []
    with open('digits', 'r') as f:
        for d in range(digits_no):
            p = [map(lambda c : VALUE_OF[c], f.readline().rstrip())
                 for i in range(HEIGHT)]
            patterns.append(reduce(lambda l1, l2 : l1 + l2, p))
            f.readline()
    return patterns

def print_digit(digit):
    """Prints a digit (a 120 character long list of -1 and 1)"""
    for l in range(HEIGHT):
        print ''.join(map(lambda x : CHAR[x], digit[l*WIDTH:(l+1)*WIDTH]))

def add_noise(digit, noise):
    """Adds noise to a pattern"""
    return map(lambda x : -x if random() < noise else x, digit)

def compute_weights(patterns):
    """Computes the weights of a Hopfield network given a set of patterns"""
    pass

def converge(weights, pattern):
    """Recovers a learned pattern from a given one [with noise]"""
    pass

def compute_accuracy(patterns, noise):
    """Computes the accuracy of a Hopfield network
    for a given set of patterns and a noise coefficient"""
    pass

if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        digits_no = int(sys.argv[1])
    else:
        digits_no = 10

    digits = read_digits(digits_no)
    print_digit(add_noise(digits[0], 0.1))
