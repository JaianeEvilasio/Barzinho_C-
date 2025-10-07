#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {
private:
    string nome;

public:
    Cliente(const string& n = "");
    string getnome() const;
    ~Cliente();
};

#endif
