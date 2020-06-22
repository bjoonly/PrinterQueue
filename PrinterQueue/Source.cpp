#include"Queue.h"
#include"Document.h"
#include"QueueWithPriority.h"
int main() {
	string line;
	Queue<string>stat(4);
	QueueWithPriority<Document>printerQueue(4);
	Document d1("Text",215,3),d2("Queue",220,1),d3("OPP C++",100,4),d4("Print",300,2),d5;
	cout << "Documnet:\n"<<d1<<endl;
	cout << "\nAdd document to printer queue: \n";
	printerQueue.AddWithPriority(d1, d1.GetPriority());
	cout << "\nPrinter queue:\n";
	printerQueue.Show();
	cout << "Add 3 documents to printer queue: \n";
	printerQueue.AddWithPriority(d2,d2.GetPriority());
	printerQueue.AddWithPriority(d3, d3.GetPriority());
	printerQueue.AddWithPriority(d4, d4.GetPriority());
	cout << "\nPrinter queue:\n";
	printerQueue.Show();
	cout << "\nPrint 3 documents.\nPrint stat:\n";
	for (int i = 0; i < 3; i++) {
		line = "";
		d5 = printerQueue.ExtractElemWithHighPriority();
		line += d5.GetName() + " ";
		line +=  to_string(d5.GetSize())+" ";
		line += to_string(10+i*2)+":"+to_string(3*15+2*i)+":"+to_string(5*5+5*i);
		stat.Enqueue(line);
		stat.Show();
		cout << "-----------------------------\n";
	}
	cout << "\nPrinter queue:\n";
	printerQueue.Show();
	cout << "\nPrint last document.\nPrint stat:\n";

	line = "";
	d5 = printerQueue.ExtractElemWithHighPriority();
	line += d5.GetName() + " ";
	line += to_string(d5.GetSize()) + " ";
	line += to_string(15) + ":" + to_string(27) + ":" + to_string(13);
	stat.Enqueue(line);
	stat.Show();

	return 0;
}