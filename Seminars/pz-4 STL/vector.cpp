#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void vectorFunction(int size_v1, int size_v2)
{
	srand(time(NULL));
	vector<int> vector1, vector2, vectorRep;
	
	cout << "Vector 1:\n";
	for (int i = 0; i < size_v1; i++)
	{
		vector1.push_back(rand() % 201 - 100);
		cout << vector1[i] << " ";
	}
	cout << endl;

	cout << "Vector 2:\n";
	for (int i = 0; i < size_v2; i++)
	{
		int buf = rand() % 201 - 100;
		vector2.push_back(buf);
		cout << vector2[i] << " ";
		if (find(vector1.begin(), vector1.end(), buf) != vector1.end())
		{
			vectorRep.push_back(buf);
		}
	}
	cout << endl;

	auto average1 = accumulate(vector1.begin(), vector1.end(), 0.0) / size_v1;
	cout << "Arithmetic mean of elements vector 1: \n";
	cout << average1 << endl;

	auto average2 = accumulate(vector2.begin(), vector2.end(), 0.0) / size_v2;
	cout << "Arithmetic mean of elements vector 2:\n";
	cout << average2 << endl;

	cout << "Cross elements:\n" << endl;
	for (int i = 0; i < vectorRep.size(); i++) {
		cout << vectorRep[i] << " ";
	}
	cout << endl;

}

int main()
{
	int v1, v2;
	cout << "Enter the v1 and v2:" << endl;
	cin >> v1 >> v2;
	vectorFunction(v1, v2);
}