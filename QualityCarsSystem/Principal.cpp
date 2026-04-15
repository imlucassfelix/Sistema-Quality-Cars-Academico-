#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "funcoes.h"





// Função responsável para exibir o aviso de privacidade 

void exibirAvisoLGPD() {

  printf("==================================================================\n");

  printf("           AVISO DE PRIVACIDADE          \n");

  printf("==================================================================\n");

  printf("A Quality cars valoriza a privacidade e a seguranca de seus dados.\n \n");

  printf("de seus dados.\n\n");

  printf("De acordo com a Lei Geral de Protecao de Dados (Lei 13.709/2018),\n");

  printf("informamos que este sistema realiza apenas o tratamento minimo\n");

  printf("necessario de informacoes pessoais, utilizadas exclusivamente para:\n\n");

  printf(" - Autenticacao de usuarios (login e controle de acesso);\n");

  printf(" - Registro interno de operacoes no sistema;\n");

  printf(" - Garantia de integridade e seguranca das informacoes.\n\n");

  printf("Nenhum dado e compartilhado com terceiros.\n\n");

  printf("Ao prosseguir, voce declara estar ciente e de acordo com\n");

  printf("o tratamento de dados conforme esta politica de privacidade.\n\n");

  printf("==================================================================\n");

  printf("Pressione ENTER para continuar...\n");

  printf("==================================================================\n");

  fflush(stdin); // limpa o buffer do teclado

  getchar();   // Aguarda ENTER

  system("cls"); // Limpa a tela (Windows)

}





// Função de encerramento — mostra mensagem final antes de sair

void exibirTelaEncerramento() {

  system("cls"); 

  printf("==============================================================\n");

  printf("          ENCERRAMENTO DO PROGRAMA          \n");

  printf("==============================================================\n");

  printf("       Obrigado por utilizar nosso sistema!      \n\n");

  printf("           Quality cars            \n");

  printf("         Seu proximo carro comeca aqui        \n");

  printf("==============================================================\n");

  printf("     Desenvolvido por : Mateus Santos e Lucas Felix    \n");

  printf("==============================================================\n");

  printf("Pressione ENTER para sair...\n");

  getchar();

}





int main() {

// Exibe o aviso inicial de privacidade

exibirAvisoLGPD();



// Somente prossegue se o login for bem-sucedido

  if (login()) {

    int opcao;

    do {

      // Menu principal do sistema

      printf("\n===== MENU DE CADASTRO DE VEICULOS =====\n");

      printf("1. Cadastrar veiculo\n");

      printf("2. Listar veiculos\n");

      printf("3. Editar veiculo\n");

      printf("4. Excluir veiculo\n");

      printf("5. Sair do Programa\n");

      printf("\nEscolha uma opcao: ");

      scanf("%d", &opcao);

      getchar();

      printf("\n");



      switch (opcao) {

        case 1: {

          Veiculo novo;

          char buffer[20]; // Buffer temporário para leitura do ano



          printf("=== Inserir novo Veiculo ===\n");

           

           // Leitura e tratamento de strings (remove o '\n' final)

          printf("Marca: ");

          fgets(novo.marca, TAM_MAX, stdin);

          novo.marca[strcspn(novo.marca, "\n")] = 0;



          printf("Modelo: ");

          fgets(novo.modelo, TAM_MAX, stdin);

          novo.modelo[strcspn(novo.modelo, "\n")] = 0;



          printf("Ano: ");

          fgets(buffer, sizeof(buffer), stdin);

          sscanf(buffer, "%d", &novo.ano);



          printf("Placa: ");

          fgets(novo.placa, 10, stdin);

          novo.placa[strcspn(novo.placa, "\n")] = 0;



          printf("Cor: ");

          fgets(novo.cores, TAM_MAX, stdin);

          novo.cores[strcspn(novo.cores, "\n")] = 0;



          // Chama função de gravação em arquivo

          salvarDados(novo);

          printf("\nVeiculo cadastrado com sucesso!\n");

          break;

        }

        case 2:

          lerDados(); // Exibe os veículos cadastrados

          break;

        case 3:

          editarDados(); // Edita um veículo existente

          break;

        case 4:

          excluirDados(); // Exclui veículo por placa

          break;

        case 5:

          printf("\nEncerrando o programa...\n"); // Permanece até o usuário escolher “Sair”

          break;

        default:

          printf("\nOpcao invalida! Tente novamente.\n");

      }

    } while (opcao != 5);

  } else {

    printf("\nEncerrando o programa...\n");

  }



  // Exibe mensagem final antes de fechar

  exibirTelaEncerramento();

  return 0;

}

