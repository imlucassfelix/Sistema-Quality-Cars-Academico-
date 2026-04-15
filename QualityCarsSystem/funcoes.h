#ifndef FUNCOES_H

#define FUNCOES_H



#define TAM_MAX 50 // Tamanho máximo para strings de texto



// Estrutura que representa um veículo

typedef struct {

  char marca[TAM_MAX];

  char modelo[TAM_MAX];

  int ano;

  char placa[10];

  char cores[TAM_MAX];

} Veiculo;





// Declarações das funções do sistema

int login();         // Função de autenticação do usuário

void salvarDados(Veiculo v); // Salva novo veículo no arquivo

void lerDados(void);     // Lê e exibe todos os veículos cadastrados

void editarDados(void);    // Edita dados de um veículo específico

void excluirDados(void);   // Exclui um veículo por placa



#endif

