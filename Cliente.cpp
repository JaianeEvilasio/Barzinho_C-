#include "Cliente.h"

Cliente::Cliente(const string& n) : nome(n) {}
string Cliente::getnome() const { return nome; }
Cliente::~Cliente() {}
