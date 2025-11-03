# Cinestesia: Barzinho C++

Projeto acadêmico da disciplina de Estrutura de Dados e Orientação a Objetos (EDOO) do CIn-UFPE.

## Descrição Geral
O **Cinestesia** é um projeto desenvolvido em C++ para a disciplina de Estrutura de Dados e Orientação a Objetos, ministrada pelo professor Francisco Paulo Magalhães Simões, do curso de Sistemas de Informação do Centro de Informática da UFPE (CIn-UFPE).

O projeto consiste em um sistema em modo console para um "Barzinho", que apresenta um cardápio digital completo e funções de gerenciamento no estilo **CRUD (Create, Read, Update, Delete)**.

## Integrantes
* Clarissa Honório
* Jaiane Evilásio
* Lavinya Costa
* Luciano Paixão
* Marcos Silva

## Estrutura do Projeto 

## Arquitetura do Projeto
Este projeto implementa um sistema simples de pedidos para um bar (Barzinho), escrito em C++ e orientado a objetos. O núcleo é a classe `Barzinho`, que mantém o cardápio (produtos) e armazena pedidos finalizados. Produtos são modelados por uma hierarquia (`Produto` → `Bebidas` / `Aperitivo`). A aplicação é de console (CLI) e usa herança e polimorfismo para exibir itens.

### Componentes Principais

* **`Barzinho` (`Barzinho.h` / `Barzinho.cpp`)**
    * Mantém um cardápio (`Produto* cardapio[100]`) e uma lista de pedidos (`Pedido* pedidos[100]`).
    * Responsável por adicionar produtos, listar por categoria e armazenar pedidos.
    * Libera (`delete`) os objetos de cardápio e pedidos no destrutor — portanto, é o proprietário desses objetos.

* **`Produto` (`Produto.h`)**
    * Classe base com atributos `nome`, `preco` e `categoria`.
    * Define `virtual void mostrar()` para permitir polimorfismo.

* **`Bebidas`, `Aperitivo` (`Bebidas.h`, `Aperitivo.h`)**
    * Subclasses de `Produto` que sobrescrevem `mostrar()` e definem a categoria.

* **`Pedido` (`Pedido.h` / `Pedido.cpp`)**
    * Contém um `Cliente` (por valor) e um array de ponteiros `Produto* produtos[50]`.
    * Métodos: `adicionaProduto`, `mostrarpedido`, `calcularTotal` (declarado).
    * Não deleta os `Produto*` recebidos — portanto, não é proprietário dos produtos.

* **`Cliente` (`Cliente.h` / `Cliente.cpp`)**
    * Representa o cliente (`nome`).

* **`main.cpp`**
    * Popula o `Barzinho` com produtos (alocados com `new`), lê interações do usuário, cria pedidos (`new Pedido(...)`), adiciona produtos (referenciando ponteiros do cardápio) e registra pedidos no `Barzinho`.

## Conceitos Utilizados na Disciplina
* Linguagem C++
* **Programação Orientada a Objetos (POO)**
* **Polimorfismo e Herança**
* Estrutura **CRUD (Create, Read, Update, Delete)**

## Instruções de Execução

* falta fazer rsrsrrsrrrsrs

---

## 
