#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

long long int CalculateSum(vector<long long int> v)
{
	long long int retval = 0;

	for(int i = 0; i < v.size(); i++)
		retval += v[i];

	return retval;
}

int main()
{
	ifstream in("input.txt");

	long long int months;
	int families;

	in >> months >> families;

	vector<vector<int>> rules;

	for(int i = 0; i < families; i++)
	{
		int count;
		in >> count;
		vector<int> v;
		for(int j = 0; j < count; j++)
		{
			int element;
			in >> element;

			v.push_back(element);
		}
		//v.push_back(i);

		//sort(v.begin(), v.end());

		rules.push_back(v);
	}

	/*

	cout << "Rules: " << endl;
	for(int i = 0; i < rules.size(); i++)
	{
		cout << endl;
		for(int j = 0; j < rules[i].size(); j++)
			cout << rules[i][j] << " ";
	}
	*/
	vector<vector<int>> complements;

	for(int i = 0; i < rules.size(); i++)
	{
		vector<int> v;
		
		for(int j = 0; j < families; j++)
			v.push_back(j);

		for(int j = rules[i].size() - 1; j > -1; j--)
			v.erase(v.begin() + rules[i][j]);

		complements.push_back(v);
	}
	
	cout << endl << endl;

	cout << "Complements: " << endl;
	for(int i = 0; i < complements.size(); i++)
	{
		cout << endl;
		for(int j = 0; j < complements[i].size(); j++)
			cout << complements[i][j] << " ";
	}
	
	vector<long long int> first_line;

	for(int i = 0; i < families; i++)
	{
		first_line.push_back(1);
	}

	vector<long long int> last(first_line);

	long long int sum = families;

	bool done = false;

	int result = 0;

	for(; done == false;)
	{
		result++;

		vector<long long int> v;

		v.resize(families);

		//sum.push_back(last);

		for(int j = 0; j < families && done == false; j++)
		{
			for(int k = 0; k < complements[j].size(); k++)
				v[complements[j][k]] += last[j];

			sum += (complements[j].size() * last[j]);

			if(sum >= months)
				done = true; 
		}

		if(result < 30)
		cout << "sum => " << sum << endl;

		last = v;
	}
/*
	cout << "Table: " << endl;
	for(int i = 0; i < table.size(); i++)
	{
		cout << endl;
		for(int j = 0; j < table[i].size(); j++)
			cout << table[i][j] << " ";
		cout << sum[i];
	}
*/
	cout << endl << endl;

	cout << "Solution => " << sum << endl; 

	ofstream out("output.txt");

	out << result;

	return 0;
}