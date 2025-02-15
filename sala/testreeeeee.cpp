#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações do usuário
typedef struct {
    int id;
    char nome[50];
} Usuario;

// Função que busca um usuário pelo ID
Usuario* buscarUsuario(Usuario usuarios[], int tamanho, int id) {
    for (int i = 0; i < tamanho; i++) {
        if (usuarios[i].id == id) {
            return &usuarios[i]; // Retorna o endereço do usuário encontrado
        }
    }
    return NULL; // Retorna NULL se não encontrar
}

int main() {
    // Array de usuários
    Usuario usuarios[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    int idBusca;
    printf("Digite o ID do usuário para buscar: ");
    scanf("%d", &idBusca);

    // Busca o usuário pelo ID
    Usuario* usuarioEncontrado = buscarUsuario(usuarios, 3, idBusca);

    // Verifica se encontrou o usuário
    if (usuarioEncontrado != NULL) {
        printf("Usuário encontrado: ID=%d, Nome=%s\n", usuarioEncontrado->id, usuarioEncontrado->nome);
    } else {
        printf("Usuário com ID=%d não encontrado.\n", idBusca);
    }

    return 0;
}
