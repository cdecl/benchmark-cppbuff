#include <fstream>
#include <sstream>
using namespace std;

#include <benchmark/benchmark.h>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <fmt/os.h>


inline std::string getSample()
{
	return "abcdefghijklmnopqrstuvwxyz\n";
}



static void WriteFmtOstream(benchmark::State& state) {
	std::ofstream fout {"out_fmtostream.txt"};
	auto str = getSample();

	for (auto _ : state) {
		fmt::print(fout, str);
	}
}
BENCHMARK(WriteFmtOstream);

static void WriteFmtOutputflie(benchmark::State& state) {
	auto out = fmt::output_file("out_fmtoutputfile.txt");
	auto str = getSample();

	for (auto _ : state) {
		out.print(str);
	}
}
BENCHMARK(WriteFmtOutputflie);

static void WriteFopen(benchmark::State& state) {
	auto *fp = fopen("out_fopen.txt", "w");
	auto str = getSample();

	for (auto _ : state) {
		fputs(str.c_str(), fp);
	}
	fclose(fp);
}
BENCHMARK(WriteFopen);

static void WriteFopenBuff(benchmark::State& state) {
	auto *fp = fopen("out_fopenbuff.txt", "w");
	auto str = getSample();
	std::ostringstream os;

	for (auto _ : state) {
		os << str;
	}

	fputs(os.str().c_str(), fp);
	fclose(fp);
}
BENCHMARK(WriteFopenBuff);

static void WriteOfstream(benchmark::State& state) {
	std::ofstream fout {"out_ofstream.txt"};
	auto str = getSample();

	for (auto _ : state) {
		fout << str;
	}
}
BENCHMARK(WriteOfstream);

static void WriteOfstreamBuff(benchmark::State& state) {
	std::ofstream fout {"out_ofstreambuff.txt"};
	auto str = getSample();
	std::ostringstream os;

	for (auto _ : state) {
		os << str;
	}
	fout << os.str();
}
BENCHMARK(WriteOfstreamBuff);


BENCHMARK_MAIN();