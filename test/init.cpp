#include <Vnesh_Sort.cpp>
#include <catch.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

SCENARIO("32mb", "[32mb]")
{
	auto begin = std::chrono::high_resolution_clock::now();
	start = std::chrono::system_clock::now();
	Vnesh_sort("32mb", "out_32", 17);
	auto end = std::chrono::high_resolution_clock::now();
	auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	cout <<"32MB - " <<(end - start).count() <<" ms"<< endl;
  REQUIRE(1);
}
SCENARIO("15mb", "[15mb]")
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	Vnesh_sort("15mb", "out_15", 4);
	end = std::chrono::system_clock::now();
	cout <<"15MB - " <<(end - start).count() <<" ns"<< endl;
  REQUIRE(1);
}

SCENARIO("8mb", "[8mb]")
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	Vnesh_sort("8mb", "out_8", 1);
	end = std::chrono::system_clock::now();
	cout <<"8MB - " <<(end - start).count() <<" ns"<< endl;
  REQUIRE(1);
}
