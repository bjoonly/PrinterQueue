#include "Document.h"

ostream& operator<<(ostream& out, const Document& document){
    out << "Name: " << document.name << "\nSize: " << document.size << endl;
	return out;
}
Document::Document(string name, int size, int priority) :size(1), priority(1) {
	this->name = name;
	SetSize(size);
	SetPriority(priority);
}
int Document::GetPriority()const {
	return priority;
}

int Document::GetSize()const {
	return size;
}
string Document::GetName()const {
	return name;
}
void Document::SetName(string name) {
	this->name = name;
}
void Document::SetSize(int size) {
	if (size > 1)
		this->size = size;
}
void Document::SetPriority(int priority) {
	if (priority > 1)
		this->priority = priority;
}