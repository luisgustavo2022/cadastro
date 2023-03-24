#include <stdio.h>

typedef struct {
  int idade;
  char nome[50];
  int cpf[11];
  char endereco[100];
  char profissao[50];
  float renda;
} Pessoa;

typedef struct {
  char nome[100];
  char endereco[100];
  int cnpj[14];
  char dono[50];
  int numero_funcionarios;
  float faturamento_anual;
} Empresa;

void linha() {
  printf("_________________________________________________________________\n");
};

void adicionar_pessoa(Pessoa pessoas[], int *num_pessoas) {
  printf("Adicionar Pessoa\n");
  printf("Nome: ");
  scanf("%s", pessoas[*num_pessoas].nome);
  printf("CPF: ");
  scanf("%d", &pessoas[*num_pessoas].cpf);
  printf("Idade: ");
  scanf("%d", &pessoas[*num_pessoas].idade);
  printf("Endereco: ");
  scanf("%s", pessoas[*num_pessoas].endereco);
  printf("Profissao: ");
  scanf("%s", pessoas[*num_pessoas].profissao);
  printf("Renda: ");
  scanf("%f", &pessoas[*num_pessoas].renda);
  printf("Pessoa adicionada com sucesso!\n");
  (*num_pessoas)++;
}

void adicionar_empresa(Empresa empresas[], int *num_empresas) {
  printf("Adicionar Empresa\n");
  printf("Nome: ");
  scanf("%s", empresas[*num_empresas].nome);
  printf("CNPJ: ");
  scanf("%d", &empresas[*num_empresas].cnpj);
  printf("Endereco: ");
  scanf("%s", empresas[*num_empresas].endereco);
  printf("Dono: ");
  scanf("%s", empresas[*num_empresas].dono);
  printf("Numero de Funcionarios: ");
  scanf("%d", &empresas[*num_empresas].numero_funcionarios);
  printf("Faturamento Anual: ");
  scanf("%f", &empresas[*num_empresas].faturamento_anual);
  (*num_empresas)++;
}
void visualizarPessoas(Pessoa *p, int n) {
  printf("Pessoas cadastradas:\n");
  for (int i = 0; i < n; i++) {
    printf("Nome: %s | Idade: %d | CPF: %011d | Endereço: %s | Profissão: %s | "
           "Renda: R$%.2f\n",
           p[i].nome, p[i].idade, p[i].cpf, p[i].endereco, p[i].profissao,
           p[i].renda);
  }
}

void visualizarEmpresas(Empresa *e, int n) {
  printf("Empresas cadastradas:\n");
  for (int i = 0; i < n; i++) {
    printf("Nome: %s | Endereço: %s | CNPJ: %014d | Dono: %s | Número de "
           "funcionários: %d | Faturamento anual: R$%.2f\n",
           e[i].nome, e[i].endereco, e[i].cnpj, e[i].dono,
           e[i].numero_funcionarios, e[i].faturamento_anual);
  }
}

int main() {
  linha();
  printf("Bem vindo ao Cadastro.\n");
  linha();
  int opcao = 0, total_pessoas = 0, total_empresas = 0;
  Pessoa pessoas[50];
  Empresa empresas[50];

  while (opcao != 4) {
    printf("\nEscolha uma opção:\n");
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Cadastrar empresa\n");
    printf("3 - Visualiar os já cadastrados\n");
    printf("4 - Sair do programa");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (total_pessoas < 50) {
        adicionar_pessoa(pessoas, &total_pessoas);
      } else {
        printf("Não é possível cadastrar mais pessoas.\n");
      }
      break;
    case 2:
      if (total_empresas < 50) {
        adicionar_empresa(empresas, &total_empresas);
      } else {
        printf("Não é possível cadastrar mais empresas.\n");
      }
      break;
    case 3:
      visualizarPessoas(pessoas, total_pessoas);
      visualizarEmpresas(empresas, total_empresas);
      break;
    case 4:
      printf("Encerrando o programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  }

  return 0;
}
