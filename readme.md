## Initial setup

```bash
cmake -S . -B build/
cmake --build build
```

## Running

```bash
./build/day1-1 /path/to/input.txt
```

## Recompiling

```bash
cd build
make
```

## Debugging

```bash
camke -DCMAKE_BUILD_TYPE=Debug -S . -B build-debug/
cmake --build build-debug

# Then, to debug e.g. day 1, part 2
lldb ./build-debug/day1-2
```
