#include <Vnesh_Sort.cpp>
#include <catch.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

SCENARIO("32mb", "[32mb]")
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
	Vnesh_sort("32mb", "out_32", 17);
	end = std::chrono::system_clock::now(); 
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout <<"32MB - " << elapsed_seconds <<" ms" << std::endl;
  REQUIRE(1);
}
SCENARIO("15mb", "[15mb]")
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
	Vnesh_sort("15mb", "out_15", 4);
	end = std::chrono::system_clock::now(); 
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout <<"15MB - " << elapsed_seconds <<" ms" << std::endl;
  REQUIRE(1);
}

SCENARIO("8mb", "[8mb]")
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
	Vnesh_sort("8mb", "out_8", 1);
	end = std::chrono::system_clock::now(); 
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout <<"8MB - " << elapsed_seconds <<" ms" << std::endl;
  REQUIRE(1);
}
