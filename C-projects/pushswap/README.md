# push_swap

##### binary that out puts instructions for sorting a stack of numbers

```sh
git clone
make
./push_swap 43 2 1 22222 43 -123
```

### Tests
```sh
./push_swap 42 1 223 22222 11 -2  | ./checker_linux 42 1 223 22222 11 -2
./push_swap 22222 11 -2  | ./checker_linux 22222 11 -2
cd test
bash test_small_stac.sh
```

### My journey

1. Learned how to group `.o` files in to a single dir.
2. Learned about bitwise operators.
3. Learned about radix sort.
4. Wrote my own unit tester that tests small stacks of numbers.
5. Used open source unit tests.
6. Worked a lot with linked lists.
7. Learned to separate parts of code in respective dirs.
