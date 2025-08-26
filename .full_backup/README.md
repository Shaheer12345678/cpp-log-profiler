# C++ Log Parser & Profiler

Command-line tool to parse large log files and compute stats:
- Top-K error messages by frequency
- Latency histogram (ms buckets)
- Simple RAII scoped timer to profile hot paths

## Build
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/logprof --help
```
## Run example
```bash
./build/logprof sample.log --top 5 --latency-col 3 --delimiter ','
```

## Tests
```bash
cmake -S . -B build -DENABLE_TESTS=ON
cmake --build build -j
ctest --test-dir build --output-on-failure
```

## Notes
- Uses `std::string_view` for zero-copy tokenization.
- Accepts CSV-like logs; adjust `--latency-col` to your column (0-based).


