#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>   // Usa para getch() — leitura de senha mascarada

#include "funcoes.h"



// Função de login com até 3 tentativas

int login() {

  char usuario[30];

  char senha[30];

  int i, tentativas = 0;



  // Credenciais padrão (poderiam futuramente vir de um arquivo ou banco)

  char userCorreto[] = "admin";

  char senhaCorreta[] = "1234";



  while (tentativas < 3) {

    printf("\n==== LOGIN DO SISTEMA ====\n\n");

    printf("Usuario: ");

    scanf("%s", usuario);



    printf("Senha: ");

    i = 0;



    // Lê senha caracter por caracter, mascarando com '*'

    while (1) {

      char ch = getch(); 

      if (ch == 13) { // Enter

        senha[i] = '\0';

        break;

      } else if (ch == 8 && i > 0) { // Backspace

        i--;

        printf("\b \b");

      } else if (i < sizeof(senha) - 1) {

        senha[i++] = ch;

        printf("*");

      }

    }



    printf("\n");



     // Verifica credenciais

    if (strcmp(usuario, userCorreto) == 0 && strcmp(senha, senhaCorreta) == 0) {

      printf("\n Login realizado com sucesso!\n");

      system("cls");

      return 1; // Sucesso

    } else {

      printf("\n Usuario ou senha incorretos.\n");

      tentativas++;

      if (tentativas < 3) {

        printf("Tente novamente.\n");

      }

    }

  }



  printf("\nAcesso bloqueado. Numero maximo de tentativas atingido.\n");

  return 0; // Falha no login

}



// Salva os dados de um veículo em formato CSV (separado por ponto e vírgula)

void salvarDados(Veiculo v) {

  FILE *arquivo = fopen("veiculos.txt", "a"); // “a” = append (acrescenta)

  if (arquivo != NULL) {

    fprintf(arquivo, "%s;%s;%d;%s;%s\n",

        v.marca, v.modelo, v.ano, v.placa, v.cores);

    fclose(arquivo);

  } else {

    printf("Erro ao abrir o arquivo!\n");

  }

}



// Lê e exibe todos os veículos cadastrados

void lerDados() {

  FILE *arquivo = fopen("veiculos.txt", "r");

  char linha[200];



  if (arquivo == NULL) {

    printf("Nenhum veiculo cadastrado ainda.\n");

    return;

  }



  printf("\n=== Veiculos Cadastrados ===\n");

  while (fgets(linha, sizeof(linha), arquivo)) {

    printf("%s", linha);

  }



  fclose(arquivo);

}



// Permite editar os dados de um veículo com base na placa

void editarDados() {

  FILE *arquivo = fopen("veiculos.txt", "r");

  FILE *temp = fopen("temp.txt", "w");



  if (!arquivo || !temp) {

    printf("Erro ao abrir o arquivo.\n");

    return;

  }



  char placaBuscada[10];

  Veiculo v;

  int encontrado = 0;



  printf("Digite a placa do carro que deseja editar: ");

  scanf("%s", placaBuscada);

  getchar(); // Limpa buffer



  // Lê cada linha e compara placa

  while (fscanf(arquivo, "%[^;];%[^;];%d;%[^;];%[^\n]\n",

         v.marca, v.modelo, &v.ano, v.placa, v.cores) == 5) {



    if (strcmp(v.placa, placaBuscada) == 0) {

      printf("=== Editando veiculo ===\n");

      printf("Nova marca: "); fgets(v.marca, TAM_MAX, stdin); v.marca[strcspn(v.marca, "\n")] = 0;

      printf("Novo modelo: "); fgets(v.modelo, TAM_MAX, stdin); v.modelo[strcspn(v.modelo, "\n")] = 0;

      printf("Novo ano: "); scanf("%d", &v.ano); getchar();

      printf("Nova cor: "); fgets(v.cores, TAM_MAX, stdin); v.cores[strcspn(v.cores, "\n")] = 0;

      encontrado = 1;

    }





    // Regrava no arquivo temporário (alterado ou não)

    fprintf(temp, "%s;%s;%d;%s;%s\n", v.marca, v.modelo, v.ano, v.placa, v.cores);

  }



  fclose(arquivo);

  fclose(temp);

  remove("veiculos.txt");       // Remove original

  rename("temp.txt", "veiculos.txt"); // Renomeia arquivo temporário



  if (encontrado)

    printf("Veiculo editado com sucesso!\n");

  else

    printf("Placa nao encontrada.\n");

}



// Remove um veículo do arquivo com base na placa

void excluirDados() {

  FILE *arquivo = fopen("veiculos.txt", "r");

  FILE *temp = fopen("temp.txt", "w");

  if (!arquivo || !temp) {

    printf("Erro ao abrir arquivos.\n");

    return;

  }



  char placaBuscada[10];

  Veiculo v;

  int encontrado = 0;



  printf("Digite a placa do veiculo que deseja excluir: ");

  scanf("%s", placaBuscada);



  // Copia todas as linhas, exceto a placa a ser removida

  while (fscanf(arquivo, "%49[^;];%49[^;];%d;%9[^;];%49[^\n]\n",

         v.marca, v.modelo, &v.ano, v.placa, v.cores) == 5) {

    if (strcmp(v.placa, placaBuscada) != 0)

      fprintf(temp, "%s;%s;%d;%s;%s\n", v.marca, v.modelo, v.ano, v.placa, v.cores);

    else

      encontrado = 1;

  }



  fclose(arquivo);

  fclose(temp);

  remove("veiculos.txt");

  rename("temp.txt", "veiculos.txt");



  if (encontrado)

    printf("Veiculo excluido com sucesso!\n");

  else

    printf("Placa nao encontrada.\n");

}
