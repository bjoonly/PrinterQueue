#pragma once
#include <iostream>
using namespace std;
template<class T>
class QueueWithPriority{
	T* data;
	int* priorities;
	int maxSize;
	int size;

public:
	
	QueueWithPriority(int maxSize) {
		this->maxSize = maxSize;
		data = new T[maxSize];
		priorities = new int[maxSize];
		size = 0;
	}
	
	~QueueWithPriority() {
		delete[]data;
		delete[]priorities;
	}

	void AddWithPriority(T elem, int priority) {
		if (!IsFull()){
			data[size] = elem;
			priorities[size] = priority;
			++size;
		}
	}
	
	T ExtractElemWithHighPriority() {
		if (!IsEmpty()) {
			int prIndex = 0;
			int prValue = priorities[0];

			for (int i = 1; i < size; ++i){
				if (priorities[i] < prValue){
					prValue = priorities[i];
					prIndex = i;
				}
			}
			T element = data[prIndex];

			for (int i = prIndex; i < size - 1; i++){
				data[i] = data[i + 1];
				priorities[i] = priorities[i + 1];
			}

			--size;
			return element;
		}
		return T();
	}
	T Peek() const{
		if (!IsEmpty()){	
			int prIndex = 0;
			int prValue = priorities[0];

			for (int i = 1; i < size; ++i){
				if (priorities[i] < prValue){
					prValue = priorities[i];
					prIndex = i;
				}
			}

			return data[prIndex];
		}
		return T();
	}
	
	bool IsEmpty() const {
		return size == 0;
	}

	bool IsFull() const {
		return size == maxSize;
	}
	
	int GetCount() const {
		return size;
	}

	void Clear() {
		size = 0;
	}
	
	void Show() const {
		for (int i = 0; i < size; i++)
			cout << data[i];
		cout << endl;
	}
};
