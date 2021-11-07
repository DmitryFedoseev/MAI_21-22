#include <iostream>

using namespace std;

class Array 
{
private:
	int size;
	int *pArr;

public:
	Array(int size) {
		this->size = size;
		this->pArr = new int[size];

		for (int i = 0; i < size; i++) {
			pArr[i] = i;
		}

	}

	Array(const Array &next) {
		this->size = next.size;
		this->pArr = new int[next.size];

		for (int i = 0; i < next.size; i++) {
			this->pArr[i] = next.pArr[i];
		}
	}

	~Array() {
		delete[] pArr;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << pArr[i] << " ";
		}

		cout << endl;
	}

	void SetArr(int num, int val) {
		if (num >= 0 && num < size && val > -100 && val < 100) {
			pArr[num] = val;
		}
		else {
			cout << "Date error" << endl;
		}
	}

	int GetArr(int num) {
		if (num >= 0 && num < size) {
			return pArr[num];
		}
		else {
			cout << "Array out of bounds" << endl;
		}
	}

	void AddArr(int newval) {
		if (newval >= -100 && newval <= 100) {
			size = size + 1;
			int* NewArr = new int[size];

			for (int i = 0; i < size - 1; i++) {
				NewArr[i] = pArr[i];
			}

			NewArr[size - 1] = newval;
			pArr = NewArr;
		}
		else {
			cout << "Date error" << endl;
		}
	}

	void Sum(Array &next) {
		if (size <= next.size) {
			for (int i = 0; i < size; i++) {
				pArr[i] += next.pArr[i];
			}
		}
		else {
			for (int i = 0; i < next.size; i++) {
				pArr[i] += next.pArr[i];
			}
		}
	}

	void Raz(Array& next) {
		if (size <= next.size) {
			for (int i = 0; i < size; i++) {
				pArr[i] -= next.pArr[i];
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				pArr[i] -= next.pArr[i];
			}
		}
	}

};

int main(){
	Array mas(10);
	//mas.SetArr(1, 88);
	//mas.GetArr(5);
	mas.print();
	Array cop(mas);
	cop.print();
	mas.AddArr(21);
	mas.print();
	cop.Sum(mas);
	cop.print();
	cop.Raz(mas);
	cop.print();
}