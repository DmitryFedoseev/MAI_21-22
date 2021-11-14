#include <iostream>
#include <exception>
#include <new>
using namespace std;

template<typename T>
class Mass
{
private:
	T* arr;
	int size;

public:

	Mass();
	Mass(int size)
	{

		if (size < 0)
		{
			throw out_of_range("Index error");
		}
		else
		{
			this->size = size;
			arr = new T[size];
			if (!arr)
			{
				throw bad_alloc();
			}
			if (typeid(T) == typeid(int))
			{
				for (int i = 0; i < size; i++)
				{
					arr[i] = 0;
				}
			}

		}
	}
	Mass(const Mass& other)
	{
		this->size = other.size;
		arr = new T[size];
		if (!arr)
		{
			throw bad_alloc();
		}
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	~Mass()
	{
		delete[] arr;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << " - " << arr[i] << endl;
		}
		cout << endl;
	}
	void SetVal(int i, T val)
	{

		if (typeid(T) == typeid(int))
		{
			if (val > 100 || val < -100)
			{
				throw invalid_argument("value outside the range -100..100");
			}
		}

		if (i >= size || i < 0)
		{
			throw out_of_range("Index error");
		}
		else
		{
			arr[i] = val;
		}


	}
	int GetVal(int i)
	{
		if (i >= size || i < 0)
		{
			throw out_of_range("Index error");
		}
		else
		{
			return arr[i];
		}
	}
	void AddVal(T newval)
	{
		if (typeid(T) == typeid(int))
		{
			if (newval > 100 || newval < -100)
			{
				throw invalid_argument("value outside the range - 100..100");
			}
			else
			{
				size = size + 1;
				int* NewArr = new T[size];
				if (!NewArr)
				{
					throw bad_alloc();
				}
				for (int i = 0; i < size - 1; i++)
				{
					NewArr[i] = arr[i];
				}
				delete[] arr;
				NewArr[size - 1] = newval;
				arr = NewArr;
			}
		}
		else
		{
			throw logic_error("Wrong data type");
		}
	}
	void GetArrSize()
	{
		return size;
	}
	void Plus(Mass& other)
	{
		if (size <= other.size)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] += other.arr[i];
			}
		}
		else
		{
			for (int i = 0; i < other.size; i++)
			{
				arr[i] += other.arr[i];
			}
		}
	}
	void Minus(Mass& other)
	{
		if (size <= other.size)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] -= other.arr[i];
			}
		}
		else
		{
			for (int i = 0; i < other.size; i++)
			{
				arr[i] -= other.arr[i];
			}
		}
	}
	void operator = (Mass& other)
	{
		if (size > other.size)
		{
			for (int i = 0; i < other.size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
				arr[i] = other.arr[i];
		}
	}
	double GetDistance(Mass& Other)
	{
		if (typeid(Other.arr[0]) != typeid(int) or typeid(arr[0]) != typeid(int))
		{
			throw logic_error("Wrong data type");
		}
		double dist = 0;
		for (int i = 0; i < size; i++) {
			dist = (toInt(arr[i]) - toInt(Other.arr[i])) * (toInt(arr[i]) - toInt(Other.arr[i])) + dist;
		}
		return sqrt(dist);
	}
};
template<typename T>
ostream& operator << (ostream& os, Mass <T>& array)
{
	for (int i = 0; i < 3; i++)
	{
		os << i << " - " << array.GetVal(i) << endl;
	}
	return os;
}


int main()
{
	Mass<int> a(2);
	a.SetVal(1, 5);
	a.SetVal(0, 4);
	try
	{
		Mass<int> arr(3);
		arr.SetVal(0, 2);
	}
	catch (out_of_range exception)
	{
		cout << "An exception was thrown " << exception.what() << endl;
	}
	catch (bad_alloc exception) {
		cout << "An exception was thrown " << exception.what() << endl;
	}
	catch (invalid_argument exception) {
		cout << "An exception was thrown " << exception.what() << endl;
	}
	Mass<int> b(3);
	b = a;
	Mass <int> c(5);
	Mass <int> d(5);
	try
	{
		c.GetDistance(d);
	}
	catch (logic_error exception)
	{
		cout << "An exception was thrown " << exception.what() << endl;
	}
	a.Print();
	b.Print();
	cout << b << endl;;
	return 0;
}