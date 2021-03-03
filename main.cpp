#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class file{
        
        public:
			ifstream inFile;
                file();
                ~file();
                virtual void loop()=0;
};
file::file(){
        inFile.open("ciagi.txt"); //tu nazwa pliku wejscia
        if (!inFile.good()){
            cerr << "Blad - pliku nie da sie otworzyc!\n";
            exit(1);
        }
}
file::~file(){
        inFile.close();
}
class zadanie:public file{
		public:
			virtual void loop()=0;
};
virtual void zadanie::loop(){
		string data; 
        while (!inFile.eof()){
            inFile >> data;
        	cout << data <<" ";
        }
}

int main(){
	file * b = new zadanie;
	b->loop();
	delete b;
}
