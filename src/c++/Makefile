# Copyright (C) 2013 Tudor Berariu
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

.PHONY: build clean run

CC=gcc
CCFLAGS=-Wall -std=c++0x -Ofast -g3
LIBS=
LIBSTD=-lstdc++
LIB=$(LIBS) $(LIBSTD)

EXEC=hopfield
SRC=$(wildcard *.cc)
OBJS=$(patsubst %.cc,%.o,$(SRC))

$(OBJS): %.o: %.cc
	$(CC) $(CCFLAGS) -c $+ -o $@ $(LIB)

$(EXEC): %: $(OBJS)
	$(CC) $(CCFLAGS) $+ -o $@ $(LIB)

build: $(EXEC)

run: build
	./$(EXEC)

clean:
	find . -name '*~' -print0 | xargs -0 rm -f
	rm -rf $(OBJS) $(EXEC)