#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <getopt.h>
#include "tokenize.hpp"
#include "stats.hpp"
#include "timer.hpp"

using namespace std;
using namespace logprof;

static void usage() {
    cerr << "Usage: logprof <file> [--delimiter ',' ] [--latency-col 3] [--top 5]\n";
}

int main(int argc, char** argv) {
    string file;
    char delim = ',';
    int latency_col = 3;
    int top = 5;

    const option longopts[] = {
        {"delimiter", required_argument, nullptr, 'd'},
        {"latency-col", required_argument, nullptr, 'l'},
        {"top", required_argument, nullptr, 't'},
        {0,0,0,0}
    };

    int idx, ch;
    while ((ch = getopt_long(argc, argv, "", longopts, &idx)) != -1) {
        switch (ch) {
            case 'd': delim = optarg[0]; break;
            case 'l': latency_col = stoi(optarg); break;
            case 't': top = stoi(optarg); break;
            default: usage(); return 1;
        }
    }
    if (optind >= argc) { usage(); return 1; }
