#pragma once
#include<string>
#include<iostream>
using namespace std;

class Document{
	string name;
	int size;
	int priority;
public:
	Document(string name="No name", int size=1, int priority=1);

	int GetPriority()const;
	string GetName()const;
	int GetSize()const;
	void SetName(string name);
	void SetSize(int size);
	void SetPriority(int priority);

	friend ostream& operator<<(ostream& out, const Document& document);

};

