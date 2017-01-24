typedef struct Jogo {
   int pilha1;
   int pilha2;
   int pilha3;
   int pilha4;
   int totalPalitos;
   int inicio_de_jogo;
   int fim_de_jogo;
}Jogo;

typedef struct {
char login[9];
char senha[8];
char nome[50];
int idade;
int num_vitorias;
int num_derrotas;
} Jogador;

void imprimePalito(int pilha1, int pilha2, int pilha3, int pilha4);

void SalvaJogador (Jogador n);

void login(Jogador *n);

int verificalogin(Jogador n);

void vitoria (Jogador n);

void derrota (Jogador n);

void informacoes(Jogador n);