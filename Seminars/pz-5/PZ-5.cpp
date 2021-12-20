#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template <typename T>
struct Struc
{
	T temp;
	int pri = 0;

};

template <class V>
class  Hash
{
private:
	list <Struc<V>> lst;

	typename list <Struc<V>> ::iterator iter;

	void sort(typename list <Struc<V>> ::iterator it)
	{
		Struc<V> buf;
		auto it_big = it;
		while (it != lst.begin())
		{

			it_big--;

			if (it->pri > it_big->pri)
			{

				buf = *it;
				it->temp = it_big->temp;
				it->pri = it_big->pri;
				it_big->pri = buf.pri;
				it_big->temp = buf.temp;
			}
			else
			{
				break;
			}
			it--;
		}
	}
public:
	Hash()
	{

	}

	~Hash()
	{

	}

	V getCache(V value)
	{
		Struc<V> buf;
		for (iter = lst.begin(); iter != lst.end(); iter++)
		{
			if (iter->temp == value)
			{
				iter->pri++;
				sort(iter);
				return iter->temp;
			}
		}
	}

	void add(V value)
	{
		Struc<V> new_Struc;
		new_Struc.temp = value;
		lst.push_back(new_Struc);
	}

	void print()
	{
		for (iter = lst.begin(); iter != lst.end(); iter++)
		{
			cout << iter->temp << " : " << iter->pri << endl;
		}
	}
};


int main()
{
	Hash<char> rowing;
	for (char i = 65; i < 90; i++)
	{
		rowing.add(i);
	}
	rowing.getCache('R');
	rowing.getCache('O');
	rowing.getCache('W');
	rowing.getCache('I');
	rowing.getCache('N');
	rowing.getCache('G');
	rowing.print();
	rowing.getCache('G');
	rowing.getCache('N');
	rowing.getCache('N');
	rowing.print();

	return 0;
}