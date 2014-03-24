// Copyright (C) 2014 Tudor Berariu
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <random>

constexpr size_t WIDTH=12;
constexpr size_t HEIGHT=10;
constexpr size_t N = WIDTH * HEIGHT;
constexpr size_t ALL=10;

using Pattern = std::array<char, N>;
using Weights = std::array<std::array<float, N>, N>;


// Returns the first @digits_no patterns from file 'digits'
// as 120 long char arrays containing -1 and 1;
std::vector<Pattern> read_digits(const size_t digits_no) {
  std::vector<Pattern> digits = std::vector<Pattern>();
  digits.reserve(ALL);

  std::ifstream digits_file("digits", std::ifstream::in);

  for(size_t d = 0; d < digits_no; d++) {
    Pattern p;
    for (size_t l = 0; l < HEIGHT; l++) {
      for (size_t c = 0; c < WIDTH; c++) {
	p[l * WIDTH + c] = digits_file.get() == 'x' ? 1 : - 1;
      }
      digits_file.get();
    }
    digits_file.get();
    digits.push_back(p);
  }
  digits_file.close();
  return digits;
}

// Print pattern @p to stdout
void print_digit(const Pattern& p) {
  for (size_t l = 0; l < HEIGHT; l++) {
    for (size_t c = 0; c < WIDTH; c++) {
      std::cout << (p.at(l * WIDTH + c) == 1 ? 'x' : '_');
    }
    std::cout << std::endl;
  }
}

// Returns a new pattern by adding noise to the original pattern
Pattern add_noise(const Pattern& original_p, const float noise) {
  std::random_device rd;
  std::default_random_engine e(rd());
  std::uniform_real_distribution<float> rand_float(0.0, 1.0);

  Pattern p;
  for (size_t i = 0; i < N; i++) {
    p[i] =  (rand_float(e) < noise ? -1 : 1) * original_p.at(i);
  }
  return p;
}

// Computes the weights of a Hopfield network given a set of patterns
Weights compute_weights(const std::vector<Pattern>& patterns) {
  Weights w;
  return w;
}

// Recovers a learned pattern from a given image (with noise)
Pattern converge(const Weights& weights, const Pattern p) {
  return p;
}

// Computes the accuracy of a Hopfield network
// for a given set of patterns and a noise coefficient
float compute_accuracy(const std::vector<Pattern>& patterns,
		       const float noise) {
  return 0.0f;
}

int main(int argc, char* argv[]) {
  size_t digits_no = ALL;
  if (argc > 1) {
    digits_no = std::stoul(argv[1]);
  }

  std::vector<Pattern> patterns = read_digits(digits_no);
  print_digit(add_noise(patterns[0], 0.1));
  return 0;
}
