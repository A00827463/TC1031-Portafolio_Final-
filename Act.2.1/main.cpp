#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
	LinkedList<string> lista;
	lista.create("HOLA", 0);
	lista.create("CRAYOLA", 1);
	lista.create("AQUI", 2);
	lista.create("ESTOY", 3);
	// lista.print();
	cout << "-------------" << endl;
	lista.create("BIENVENIDO", 2);
	lista.create("AQUI", 2);
	cout << "Read: " << lista.read("HOLA") << endl;
	lista.update("CRAYOLA", "SEBAS");
	// lista.print();
	cout << "-------------" << endl;

	lista.del("AQUI");
	lista.del("ESTOY");
	// lista.print();
	cout << "-------------" << endl;
}
