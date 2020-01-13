
#include <sstream>
using namespace std;

// #include "fmt/format.h"
#include "benchmark/benchmark.h"

const int LOOP = 1000;
const string Data { "1234567890 "};


// void fmt_memorybuffer(benchmark::State &state) 
// {
// 	fmt::memory_buffer buff;
// 	for (auto _ : state) {
// 		buff.clear();
// 		for (int i = 0; i < LOOP; ++i) {
// 			buff.append(Data.c_str(), Data.c_str() + Data.size());
// 		}
// 	}
// }
// BENCHMARK(fmt_memorybuffer);

void string_append(benchmark::State &state) 
{
	string s{};
	for (auto _ : state) {
		s.clear();
		for (int i = 0; i < LOOP; ++i) {
			s.append(Data);
		}
	}
}
BENCHMARK(string_append);

void stringstream_append(benchmark::State &state) 
{
	ostringstream ss{};
	for (auto _ : state) {
		ss.str("");
		for (int i = 0; i < LOOP; ++i) {
			ss.write(Data.c_str(), Data.size());
		}
	}
}
BENCHMARK(stringstream_append);


BENCHMARK_MAIN();