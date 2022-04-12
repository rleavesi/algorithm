#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <limits.h>

using namespace std;
enum Mode {
	BIG,
	SMALL,
	UNORDER
};

template<class T>
class Heap {
public:
	explicit Heap(unsigned int capacity, Mode mode) : _capacity(capacity), _size(0), _root(nullptr),_mode(mode) { Create(); }
	~Heap(){
		Destory();
	}
	
	void Swap(T* a, T* b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	} 

	void AdjustUp(int n) {
		if (_mode == Mode::BIG) {
			for (int i = n; i > 1 && _root[i] > _root[i / 2]; i /= 2)
				Swap(&_root[i], &_root[i / 2]);
		}
		else if (_mode == Mode::SMALL) {
			for (int i = n; i > 1 && _root[i] < _root[i / 2]; i /= 2)
				Swap(&_root[i], &_root[i / 2]);
		}
		else return;
	}

	void AdjustDown(int n) {
		if (_mode == Mode::BIG) {
			for (int i = n; i * 2 <= _size; i *= 2) {
				int child = i * 2 + 1 <= _size ? (_root[i * 2] >  _root[i * 2 + 1] ? i * 2 : i * 2 + 1) : i * 2;
				if (_root[child] > _root[i])
					Swap(&_root[i], &_root[child]);
			}
		}
		else if (_mode == Mode::SMALL) {
			for (int i = n; i * 2 <= _size; i *= 2) {
				int child = i * 2 + 1 <= _size ? (_root[i * 2] < _root[i * 2 + 1] ? i * 2 : i * 2 + 1) : i * 2;
				if (_root[child] < _root[i])
					Swap(&_root[i], &_root[child]);
			}
		}
		else return;
	}

	void Create() {
		if (_root == nullptr)
			_root = (T*)malloc(sizeof(T) * (_capacity + 1));
		if (_root == nullptr) {
			perror("!");
			exit(EXIT_FAILURE);
		}
		if(_size != 0)
			Sort();
	}

	void Destory() {
		free(_root);
		_size =  _capacity = 0;
	}

	bool Push(const T val) {
		if (_size + 1 > _capacity) {
			perror("Extend Capacity!");
			return false;
		}
		_root[++_size] = val;
		AdjustUp(_size);
		return true;
	}

	T Pop() {
		if (_size == 0) return NULL;
		Swap(&_root[_size--], &_root[1]);
		AdjustDown(1);
		return _root[_size + 1];
	}

	T Top() {
		if (_size == 0) return NULL;
		return _root[1];
	}

	bool Empty() {
		return _size == 0;
	}


	int GetCapacity() {
		return _capacity;
	}

	int GetSize() {
		return _size;
	}

	void Sort() {
		for (int i = 1; i <= _size; i++)
			AdjustUp(i);
	}

	int __builtin_clz(unsigned int x) {
		for (int i = 0; i != 64; ++i) {
			if (x >> 63 - i & 1)
				return i;
		}
	}

	void Print() {
		int space = __builtin_clz(_size) - 23;
		for (int i = 1; i <= _size; i++) {
			printf("%d ", _root[i]);	
			if (((i + 1) & i) == 0) {
				printf("\n");
			}
		}
	}


public:
	T* _root;
	int _size;
	int _capacity;
	Mode _mode;
};