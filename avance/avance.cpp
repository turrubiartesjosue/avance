#include <iostream>
#include <fstream>

using namespace std;

struct usuario {
	char nombre[50];
	char email[50];
	char comercio[50];
	usuario* sig;
};

struct cliente {
	char nombreCliente[50];
	int monto;
	int subtotal;
	int descuento;
	int total;
	cliente* sig2;
};

struct promocion {
	char nombreProm[50];
	int montoProm;
	int porcentajeProm;
	char estatusProm[50];
	promocion* sig3;
};

struct consumo {
	char clienteCons[50];
	int montoCons;
	int subtotalCons;
	int descuentoCons;
	int totalCons;
	consumo* sig4;
};

usuario* inicio, * auxiliar = nullptr;
cliente* inicio2, * auxiliar2 = nullptr;
promocion* inicio3, * auxiliar3 = nullptr;
consumo* inicio4, * auxiliar4 = nullptr;

void altaUsuario(usuario* nuevo);
void modificarUsuario(char nomUsa[50]);

void altaCliente(cliente* nuevo2);
void modificarCliente(char nomCli[50]);
void eliminarCliente(char nomCli[50]);
void listaCliente();

void altaPromocion(promocion* nuevo3);
void listaProm();

void altaConsumo(consumo* nuevo4);
void listaCons();

int main() {

	string user = "", pass = "";
	cout << "ingresa tu nombre de usuario :" << endl;
	cin >> user;
	cout << "ingresa contraseña :" << endl;
	cin >> pass;
	if (user == "jtturbo " && pass == "buenas45")
	{
		cout << "bienvenido";
	}
	else {
		cout << "usuario no encontrado";
	}

	int op = 0;
	char nomUsa[] = { 0 };
	char nomCli[] = { 0 };
	char nomPromo[] = { 0 };
	char nomCons[] = { 0 };

	usuario* nodoUsa = new usuario;
	cliente* nodoCli = new cliente;
	promocion* nodoPromo = new promocion;
	consumo* nodoCons = new consumo;

	do {
		system("cls");
		cout << "::::Menu::::" << endl;
		cout << "1.- Alta de usuario" << endl;
		cout << "2.- Modificar usuario" << endl;
		cout << "3.- Alta de clientes" << endl;
		cout << "4.- Modificar clientes" << endl;
		cout << "5.- Baja de clientes" << endl;
		cout << "6.- Listado de clientes" << endl;
		cout << "7.- Alta de promociones" << endl;
		cout << "8.- Lista de promociones" << endl;
		cout << "9.- Alta de consumo" << endl;
		cout << "10.- Lista de consumo" << endl;
		cin >> op;
		cin.ignore();

		if (op == 1) {
			cout << "Nombre de usuario: " << endl;
			cin.getline(nodoUsa->nombre, 50);
			cout << "Correo de usuario: " << endl;
			cin.getline(nodoUsa->email, 50);
			cout << "Comercio de usario: " << endl;
			cin.getline(nodoUsa->comercio, 50);
			altaUsuario(nodoUsa);
			op = 0;
		}
		else if (op == 2) {
			cout << "Nombre de usuario a modificar: " << endl;
			cin.getline(nomUsa, 50);
			modificarUsuario(nomUsa);
			cin.ignore();
			op = 0;
		}
		else if (op == 3) {
			cout << "Nombre de cliente: " << endl;
			cin.getline(nodoCli->nombreCliente, 50);
			cout << "El monto del cliente: " << endl;
			cin >> nodoCli->monto;
			cin.ignore();
			cout << "El subtotal del cliente: " << endl;
			cin >> nodoCli->subtotal;
			cin.ignore();
			cout << "El Descuento del cliente: " << endl;
			cin >> nodoCli->descuento;
			cin.ignore();
			cout << "El total del cliente: " << endl;
			cin >> nodoCli->total;
			cin.ignore();
			op = 0;
		}
		else if (op == 4) {
			cout << "Nombre de cliente a modificar: " << endl;
			cin.getline(nomCli, 50);
			modificarCliente(nomCli);
			cin.ignore();
			op = 0;
		}
		else if (op == 5) {
			cout << "Nombre de cliente a eliminar: " << endl;
			cin.getline(nomCli, 50);
			eliminarCliente(nomCli);
			op = 0;
		}
		else if (op == 6) {
			listaCliente();
			cin.ignore();
			op = 0;
		}
		else if (op == 7) {
			cout << "Nombre de la promocion: " << endl;
			cin.getline(nodoPromo->nombreProm, 50);
			cout << "El monto de la promocion: " << endl;
			cin >> nodoPromo->montoProm;
			cin.ignore();
			cout << "El porcentaje de descuento de la promocion: " << endl;
			cin >> nodoPromo->porcentajeProm;
			cin.ignore();
			cout << "Estatus de la promocion: " << endl;
			cin.getline(nodoPromo->estatusProm, 50);
			altaPromocion(nodoPromo);
			op = 0;
		}
		else if (op == 8) {
			listaProm();
			cin.ignore();
			op = 0;
		}
		else if (op == 9) {
			cout << "Nombre del cliente: " << endl;
			cin.getline(nodoCons->clienteCons, 50);
			cout << "El monto del consumo: " << endl;
			cin >> nodoCons->montoCons;
			cin.ignore();
			cout << "Subtotal del consumo: " << endl;
			cin >> nodoCons->subtotalCons;
			cin.ignore();
			cout << "Descuento del consumo: " << endl;
			cin >> nodoCons->descuentoCons;
			cin.ignore();
			cout << "Total del consumo: " << endl;
			cin >> nodoCons->totalCons;
			cin.ignore();
			altaConsumo(nodoCons);
			op = 0;
		}
		else if (op == 10) {
			listaCons();
			cin.ignore();
			op = 0;
		}

	} while (op < 1 || op > 11);


	system("PAUSE");
	return 0;
}

void altaUsuario(usuario* nuevo) {
	if (inicio == nullptr) {
		inicio = new usuario;
		auxiliar = inicio;

		strcpy_s(auxiliar->nombre, nuevo->nombre);
		strcpy_s(auxiliar->email, nuevo->email);
		strcpy_s(auxiliar->comercio, nuevo->comercio);
		auxiliar->sig = nullptr;
	}
	else {
		auxiliar = inicio;
		while (auxiliar->sig != nullptr)
		{
			auxiliar = auxiliar->sig;
		}

		auxiliar->sig = new usuario;

		auxiliar = auxiliar->sig;

		strcpy_s(auxiliar->nombre, nuevo->nombre);
		strcpy_s(auxiliar->email, nuevo->email);
		strcpy_s(auxiliar->comercio, nuevo->comercio);

		auxiliar->sig = nullptr;
	}
}
void modificarUsuario(char usuBuscar[50]) {
	auxiliar = inicio;
	char newUsu[50];
	if (auxiliar == nullptr) {
		cout << "La lista esta vacia. Agregue un usuario" << endl;
	}
	else {
		while (auxiliar != nullptr && strcmp(auxiliar->nombre, usuBuscar) != 0) {
			auxiliar = auxiliar->sig;
		}
		if (auxiliar == nullptr) {
			cout << "Usuario no encontrado" << endl;
		}
		else {
			cout << "::::Usuario encontrado:::: " << endl;
			cout << "Nombre del usuario: " << auxiliar->nombre << endl;
			cout << endl;

			cout << "Nuevo nombre del usuario: " << endl;
			cin.getline(newUsu, 50);
			strcpy_s(auxiliar->nombre, newUsu);
			cout << endl;
			cout << "::::Usuario modificado:::: " << endl;
		}
	}
	system("PAUSE");
}

void altaCliente(cliente* nuevo2) {

	if (inicio2 == nullptr) {
		inicio2 = new cliente;
		auxiliar2 = inicio2;

		auxiliar2->monto = nuevo2->monto;
		strcpy_s(auxiliar2->nombreCliente, nuevo2->nombreCliente);
		auxiliar2->subtotal = nuevo2->subtotal;
		auxiliar2->descuento = nuevo2->descuento;
		auxiliar2->total = nuevo2->total;
		auxiliar2->sig2 = nullptr;
	}
	else {
		auxiliar2 = inicio2;
		while (auxiliar2->sig2 != nullptr) {
			auxiliar2 = auxiliar2->sig2;
		}

		auxiliar2->sig2 = new cliente;

		auxiliar2 = auxiliar2->sig2;

		strcpy_s(auxiliar2->nombreCliente, nuevo2->nombreCliente);
		auxiliar2->monto = nuevo2->monto;
		auxiliar2->subtotal = nuevo2->subtotal;
		auxiliar2->descuento = nuevo2->descuento;
		auxiliar2->total = nuevo2->total;

		auxiliar2->sig2 = nullptr;
	}
}
void modificarCliente(char cliBuscar[50]) {
	auxiliar2 = inicio2;
	char newCli[50];
	if (auxiliar2 == nullptr) {
		cout << "La lista esta vacia. Agregue un cliente" << endl;
	}
	else {
		while (auxiliar2 != nullptr && strcmp(auxiliar2->nombreCliente, cliBuscar) != 0) {
			auxiliar2 = auxiliar2->sig2;
		}
		if (auxiliar2 == nullptr) {
			cout << "Cliente no encontrado" << endl;
		}
		else {
			cout << "::::Cliente encontrado:::: " << endl;
			cout << "Nombre del cliente: " << auxiliar2->nombreCliente << endl;
			cout << endl;

			cout << "Nuevo nombre del cliente: " << endl;
			cin.getline(newCli, 50);
			strcpy_s(auxiliar2->nombreCliente, newCli);
			cout << "endl";
			cout << "::::Cliente modificado:::: " << endl;
		}
	}
	system("PAUSE");
}
void eliminarCliente(char cliEliminar[50]) {
	auxiliar2 = inicio2;
	cliente* anterior = nullptr;
	if (auxiliar2 == nullptr)
	{
		cout << "La lista esta vacia. Agregue clientes" << endl;
	}
	else {
		while (auxiliar2 != nullptr && strcmp(auxiliar2->nombreCliente, cliEliminar) != 0) {
			anterior = auxiliar2;
			auxiliar2 = auxiliar2->sig2;
		}
		if (auxiliar == nullptr) {
			cout << "Usuario no encontrado" << endl;
		}
		else if (auxiliar2 == inicio2) {
			cout << "::::Usuario encontrado:::: " << endl;
			cout << "Nombre del usuario: " << auxiliar2->nombreCliente << endl;
			cout << endl;

			inicio2 = auxiliar2->sig2;
			delete auxiliar2;

			auxiliar2 = inicio2;

			cout << "::::Cliente eliminado:::: " << endl;
		}
		else {
			cout << "::::Cliente encontrado:::: " << endl;
			cout << "Nombre del cliente: " << auxiliar2->nombreCliente << endl;
			cout << endl;

			anterior->sig2 = auxiliar2->sig2;

			delete auxiliar2;

			auxiliar2 = inicio2;

			cout << "::::Cliente eliminado:::: " << endl;

		}
	}
	system("PAUSE");
}
void listaCliente() {
	system("cls");
	if (inicio2 == nullptr) {

		cout << endl;
		cout << "La lista esta vacia. Agregue clientes";

	}
	else {
		auxiliar2 = inicio2;

		while (auxiliar2 != nullptr)
		{
			cout << "Cliente: " << auxiliar2->nombreCliente << endl;
			cout << "Monto: " << auxiliar2->monto << endl;
			cout << "Subtotal: " << auxiliar2->subtotal << endl;
			cout << "Descuento: " << auxiliar2->descuento << endl;
			cout << "Total: " << auxiliar2->total << endl;
			auxiliar2 = auxiliar2->sig2;
		}
	}
}
void altaPromocion(promocion* nuevo3) {
	if (inicio3 == nullptr) {
		inicio3 = new promocion;
		auxiliar3 = inicio3;

		strcpy_s(auxiliar3->nombreProm, nuevo3->nombreProm);
		auxiliar3->montoProm = nuevo3->montoProm;
		auxiliar3->porcentajeProm = nuevo3->porcentajeProm;
		strcpy_s(auxiliar3->estatusProm, nuevo3->estatusProm);
		auxiliar3->sig3 = nullptr;
	}
	else {
		auxiliar3 = inicio3;
		while (auxiliar3->sig3 != nullptr) {
			auxiliar3 = auxiliar3->sig3;
		}

		auxiliar3->sig3 = new promocion;

		auxiliar3 = auxiliar3->sig3;

		strcpy_s(auxiliar3->nombreProm, nuevo3->nombreProm);
		auxiliar3->montoProm = nuevo3->montoProm;
		auxiliar3->porcentajeProm = nuevo3->porcentajeProm;
		strcpy_s(auxiliar3->estatusProm, nuevo3->estatusProm);

		auxiliar3->sig3 = nullptr;
	}
}
void listaProm() {
	system("cls");
	if (inicio3 == nullptr) {

		cout << endl;
		cout << "La lista esta vacia. Agregue promociones";

	}
	else {
		auxiliar3 = inicio3;

		while (auxiliar3 != nullptr)
		{
			cout << "Nombre: " << auxiliar3->nombreProm << endl;
			cout << "Monto: " << auxiliar3->montoProm << endl;
			cout << "Porcentaje de descuento: " << auxiliar3->porcentajeProm << endl;
			cout << "Estatus: " << auxiliar3->estatusProm << endl;
			auxiliar3 = auxiliar3->sig3;
		}
	}
}
void altaConsumo(consumo* nuevo4) {
	if (inicio4 == nullptr) {
		inicio4 = new consumo;
		auxiliar4 = inicio4;

		strcpy_s(auxiliar4->clienteCons, nuevo4->clienteCons);
		auxiliar4->montoCons = nuevo4->montoCons;
		auxiliar4->subtotalCons = nuevo4->subtotalCons;
		auxiliar4->descuentoCons = nuevo4->descuentoCons;
		auxiliar4->totalCons = nuevo4->totalCons;
		auxiliar4->sig4 = nullptr;
	}
	else {
		auxiliar4 = inicio4;
		while (auxiliar4->sig4 != nullptr) {
			auxiliar4 = auxiliar4->sig4;
		}

		auxiliar4->sig4 = new consumo;

		auxiliar4 = auxiliar4->sig4;

		strcpy_s(auxiliar4->clienteCons, nuevo4->clienteCons);
		auxiliar4->montoCons = nuevo4->montoCons;
		auxiliar4->subtotalCons = nuevo4->subtotalCons;
		auxiliar4->descuentoCons = nuevo4->descuentoCons;
		auxiliar4->totalCons = nuevo4->totalCons;
		auxiliar4->sig4 = nullptr;

		auxiliar4->sig4 = nullptr;
	}
}
void listaCons() {
	system("cls");
	if (inicio4 == nullptr) {

		cout << endl;
		cout << "La lista esta vacia. Agregue consumos";

	}
	else {
		auxiliar4 = inicio4;

		while (auxiliar4 != nullptr)
		{
			cout << "Nombre del cliente: " << auxiliar4->clienteCons << endl;
			cout << "Monto: " << auxiliar4->montoCons << endl;
			cout << "subtotal: " << auxiliar4->subtotalCons << endl;
			cout << "Descuento: " << auxiliar4->descuentoCons << endl;
			cout << "Total: " << auxiliar4->totalCons << endl;
			auxiliar4 = auxiliar4->sig4;
		}
	}
}




