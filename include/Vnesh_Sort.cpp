#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct da_ta
{
	string s;
	ifstream *f;
	da_ta(const string& s_, ifstream* f_) : s(s_), f(f_){}
	bool operator < (const da_ta& da_ta_) const
	{
		return (s > da_ta_.s);
	}
};

void Vnesh_Sort(const string input_name, const string output_name, const unsigned long int mem_size)
{
	ifstream fin(input_name);
	if (!fin.is_open()) 
		throw("file_not_open");
	ofstream fout(output_name);
	size_t k = 0;
	while (!fin.eof())
	{
		ofstream fout_(to_string(k + 1) + ".txt");
		vector<string> v; string s;
		for (unsigned long int size = 0; (size + sizeof(string)) <= mem_size; size += sizeof(string))
		{
			getline(fin, s);
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (auto i : v)
		{
			if (i != "") fout_ << i;
			if (i != *(--v.end())) fout_ << endl;
		}
		++k;
		fout_.close();
	}
	fin.close();
	priority_queue<da_ta> pq;
	for (size_t i = 0; i < k; ++i)
	{
		ifstream* f_ = new ifstream(to_string(i + 1) + ".txt");
		string str;
		getline(*f_, str);
		da_ta si(str, f_);
		pq.push(si);
	}
	while (!pq.empty())
	{
		da_ta si = pq.top();
		pq.pop();
		if (si.s != "")
		{
			fout << si.s;
			fout << endl;
		}
		if (!(*si.f).eof())
		{
			getline(*si.f, si.s);
			pq.push(si);
		}
		else
		{
			(*(si.f)).close();
		}
	}
	for (size_t i = 0; i < k; ++i)
	{
		remove((to_string(i + 1) + ".txt").c_str());
	}
	fout.close();
}

