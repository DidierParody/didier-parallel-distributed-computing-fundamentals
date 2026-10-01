# Sessions - Execution Results

This file shows the output of every exercise in this folder after running it on my machine.

## Machine and compiler

| Item | Value |
|---|---|
| CPU | AMD Ryzen 5 7520U (4 cores / 8 threads) |
| OS | Windows 11 Home |
| Compiler | GCC 16.1.0 (MinGW-w64) |
| Compile command | `gcc -g -fopenmp file.c -o file.exe` |
| Date | 30-09-2026 |

---

## 01 - C basic

| Exercise | Input | Output |
|---|---|---|
| cb_01_calculator | `10`, `5`, `+` | `10 + 5 = 15` |
| cb_02_temperature_converter | `25` | `Fahrenheits: 77` |
| cb_03_area_perimeter | base `5`, height `3` | `Area: 15 m^2`, `Perimeter: 16 m` |
| cb_04_fizz_buzz | - | 47 lines of `Fizz` / `Buzz` / `FizzBuzz` (numbers are skipped) |
| cb_05_prime_numbers | - | 25 primes: `2 3 5 7 11 ... 89 97` |
| cb_06_switch_menu | option `1` (8, 2), option `4` (8, 2), option `5` | `8 + 2 = 10`, `8 / 2 = 4`, exit |
| cb_07_revert_array | `1` to `10` | `10 9 8 7 6 5 4 3 2 1` |
| cb_08_max_and_min | - | `0 1 2 3 4`, `the minor is: 0`, `the largest is: 4` |
| cb_09_palindrome_string | - (word `Didier`) | `They are not the same` |
| cb_10_vowels_counter | `Hello World` | `Total vowels: 3` |
| cb_11_prime_factorial | - (number `5`) | `The number 5 is prime`, Fibonacci: `0 1 1 2 3` |
| cb_12_swap | - (x = 52, y = 23) | `x = 23`, `y = 52` |
| cb_13_array_sum | - | `Array sum: 150` |
| cb_14_person__struct | - | `Alice, 25` / `Bob, 30` / `Charlie, 22` |
| cb_15_dinamic_array | size `3`, elements `4 5 6` | `Array elements: 4 5 6` |

## 02 - C exercises (pointers)

| Exercise | Output |
|---|---|
| cb_01_pointer_array_fill | `[1,2,3,4,5,6,7,8,9,10,` |
| cb_02_pointer_sum | `result = 55` |
| cb_03_show_matrix | `1 2 3` / `4 5 6` / `7 8 9` |
| cb_04_swap | Before: `a = 1 b = 2`, After: `a = 2 b = 1` |
| cb_05_charecter_string | `h`, `i` and `\0` with their memory addresses (addresses change on every run) |

Note: in `cb_01_pointer_array_fill` the closing `]` is never printed, because `i == size` is never true inside the loop.

---

## 03 - OpenMP

### Formulas

- **Ts** = sequential time
- **Tp** = parallel time
- **Speedup (S)** = Ts / Tp
- **Efficiency (E)** = S / p, where p = 8 threads (OpenMP default on this machine)

Each program was run **5 times** and the tables use the **average**. The time measured is only the main calculation (not the array filling).

### Raw times (seconds)

| Run | omp_01 Ts | omp_01 Tp | omp_02 Ts | omp_02 Tp | omp_03 Ts | omp_03 Tp |
|---|---|---|---|---|---|---|
| 1 | 0.209 | 0.059 | 0.312 | 0.577 | 8.213 | 2.277 |
| 2 | 0.206 | 0.053 | 0.250 | 0.500 | 9.004 | 2.582 |
| 3 | 0.205 | 0.063 | 0.311 | 0.724 | 8.927 | 2.854 |
| 4 | 0.220 | 0.064 | 0.280 | 0.614 | 8.977 | 2.549 |
| 5 | 0.215 | 0.064 | 0.291 | 0.644 | 8.980 | 2.582 |
| **Average** | **0.2110** | **0.0606** | **0.2888** | **0.6118** | **8.8202** | **2.5688** |

### Results

| Exercise | Size | Ts (s) | Tp (s) | Speedup | Efficiency |
|---|---|---|---|---|---|
| omp_01 - Sum of array | N = 100,000,000 | 0.2110 | 0.0606 | 3.48 | 43.5 % |
| omp_02 - Scalar product | N = 100,000,000 | 0.2888 | 0.6118 | 0.47 | 5.9 % |
| omp_03 - Matrix multiplication | 1000 x 1000 | 8.8202 | 2.5688 | 3.43 | 42.9 % |

### Program outputs

| Exercise | Output |
|---|---|
| omp_01 sequential / parallel | `Sum: 987459712` (same in both) |
| omp_02 (1 thread / 8 threads) | `Sum = 20049330185600` (same in both) |
| omp_03 sequential / parallel | `Result C[0][0]: 2000` (same in both) |

### Notes

- **omp_01** and **omp_03** get a speedup of about **3.4x** with 8 threads. The efficiency is around 43 % because the CPU has only 4 real cores (8 threads come from hyper-threading) and the array sum is limited by memory speed.
- **omp_02** does not have a sequential file, so **Ts** was taken by running the same program with `OMP_NUM_THREADS=1`.
- **omp_02** is **slower** in parallel (speedup < 1). The `#pragma omp parallel for` is inside another `#pragma omp parallel` block, so **each of the 8 threads repeats the whole loop** instead of sharing it. Using only `#pragma omp parallel for reduction(+:sum)` (without the outer block) should fix it.
- The sums in **omp_01** and **omp_02** are not the real math values because the numbers are too big for an `int` (overflow). The sequential and parallel versions still print the same value, so the time comparison is fair.
- **omp_03** parallel prints one line per row (`Thread X is calculating row Y`) inside the timed part, which adds a little time to Tp.
