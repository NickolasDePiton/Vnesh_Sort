#include <Sort.cpp>
#include <catch.hpp>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

SCENARIO("io", "[io]")
{
  Vnesh_Sort("in.txt", "out.txt", 120);
	string *a = new string[16], *b = new string[16];
	bool x = false;
	ifstream f1("out.txt"), f2("test.txt");
	for (int i = 0; i < 16; ++i)
	{
		getline(f1, a[i]);
		getline(f2, b[i]);
	}
	size_t x_ = 0;
	for (int i = 0; i < 16; ++i)
	{
		if (a[i] == b[i]) ++x_;
	}
	if (x_ == 16) x = true;
  REQUIRE(x);
} 
