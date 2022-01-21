#include <benchmark/benchmark.h>
#include "../submodules/UnorderedRedis/include/unorderdRedis.h"
#include <vector>

static void Raw_Insert(benchmark::State& state) {
  // Perform setup here

   redisContext * context = redisConnect("127.0.0.1",6379);

  UnorderedRedis<std::string,std::string> a;
  for (auto _ : state) {
    // This code gets timed
      std::string key = "aaa";
      std::string value = "bbb";
      void * a = redisCommand(context , "set %s %s" , key.c_str(), value.c_str());
    benchmark::DoNotOptimize(a);
  }

}
// Register the function as a benchmark
BENCHMARK(Raw_Insert);

static void String_Insert(benchmark::State& state) {
  // Perform setup here

  UnorderedRedis<std::string,std::string> a;
  std::string key = "aaa";
  std::string value = "bbb";

  for (auto _ : state) {
    // This code gets timed
    a.insert(key,value);
  }
}
// Register the function as a benchmark
BENCHMARK(String_Insert);

static void Int_Insert(benchmark::State& state) {
  // Perform setup here

  UnorderedRedis<int,int> a;
  for (auto _ : state) {
    // This code gets timed
    a.insert(10,12);
  }
}

// Register the function as a benchmark
BENCHMARK(Int_Insert);


// Run the benchmark
BENCHMARK_MAIN();
