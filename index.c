#include <stdio.h>

//VOU PEDIR UMA CONSIDERAÇÃO PROFESSOR, MEU COMPILADOR C NÃO ESTA FUNCIONANDO TENTEI 3 COMPILADORES E UNS TUTORIAIS NA INTERNET MAS NÃO CONSIGO TESTAR OS CODIGOS, FOI SOMENTE NA LOGICA.

int main() {
    int tabuleiro[10][10] = {
        {0,3,0,0,0,0,0,0,0,0},
        {0,0,3,0,0,0,0,0,0,0},
        {0,0,0,3,0,0,0,0,0,0},
        {0,0,0,0,3,3,3,3,0,0},
        {0,0,0,0,0,0,0,0,3,0},
        {0,0,0,3,0,0,0,3,0,0},
        {0,0,0,3,0,0,3,0,0,0},
        {0,0,0,3,0,3,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };


    int cone[7][7] = {
        {0,0,0,0,1,0,0},
        {0,0,0,1,1,1,0},
        {0,0,1,1,1,1,1},
        {0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}

       
    };
    int inicioCone = cone[0][4]; // Ponta do ataque cone

    int cruz[7][7]={
        {0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0},
        {0,1,1,1,1,1,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };
    int centroCruz = cruz[3][2]; // Centro do ataque cruz

int octaedro[7][7]={
        {0,0,0,1,0,0,0},
        {0,0,1,1,1,0,0},
        {0,1,1,1,1,1,0},
        {1,1,1,1,1,1,1},
        {0,1,1,1,1,1,0},
        {0,0,1,1,1,0,0},
        {0,0,0,1,0,0,0}

    };

    int centroOctaedro = octaedro[3][3]; // Centro do ataque octaedro


    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Cabeçalho das colunas
    printf("    ");
    for (int c = 0; c < 10; c++) {
        printf(" %c", colunas[c]);
    }
    printf("\n");

    // Exibe o tabuleiro com números das linhas à esquerda
    for (int row = 0; row < 10; row++) {
        printf("%2d |", row + 1);  // Identificador à esquerda
        for (int col = 0; col < 10; col++) {
            printf(" %d", tabuleiro[row][col]);
        }
        printf("\n");
    }

  



    int opcao;
    printf("Defina qual ataque especial deseja usar:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro\n");
    scanf("%d", &opcao);

    printf("Digite a posição para o ataque especial coluna de A a J: ");
    char col;
    scanf(" %c", &col);
    if (col < 'A' || col > 'J') {
        printf("Coluna inválida. Por favor, insira uma letra de A a J.\n");
        return 1;
    }
    
    for (int i = 0; i < 10; i++) {
        if (colunas[i] == col) {
            printf("Coluna selecionada: %d\n", i + 1);
            posColuna = i;
            return posColuna;
        } 
    int linha;
    printf("digite o numero da linha de 1 a 10: ");
    scanf("%d", &linha);
    if (linha < 1 || linha > 10) {
        printf("Linha inválida. Por favor, insira um número de 1 a 10.\n");
        return 1;
    

    }else {
        printf("Linha selecionada: %d\n", linha);
        return linha;
    }
    }




    if (opcao == 1) {
        printf("Ataque especial Cone selecionado.\n");
        // Crie a lógica para sobrepor a matriz de habilidade ao tabuleiro(cone), centrando a matriz de habilidade no ponto de origem definido no tabuleiro.
          // Posição do centro do ataque no tabuleiro (exemplo: linha 5, coluna 5)
    int centroAtaqueX = 5;
    int centroAtaqueY = 5;
    
    // Ponta do cone (é [0][4] conforme definido)
    int inicioConstX = 0;
    int inicioConstY = 4;

    // Calcular o offset para alinhar os centros
    int offsetX = centroAtaqueX - inicioConstX;
    int offsetY = centroAtaqueY - inicioConstY;

    // Aplicar a sobreposição
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            // Calcular posição no tabuleiro
            int tabX = i + offsetX;
            int tabY = j + offsetY;
            
            // Verificar se está dentro dos limites do tabuleiro
            if (tabX >= 0 && tabX < 10 && tabY >= 0 && tabY < 10) {
                // Se cone tem 1 e tabuleiro tem 3, mudar para 5
                if (cone[i][j] == 1 && tabuleiro[tabX][tabY] == 3) {
                    tabuleiro[tabX][tabY] = 5;
                }
                // Se cone tem 1 e tabuleiro tem 0, pode colocar 1
                else if (cone[i][j] == 1 && tabuleiro[tabX][tabY] == 0) {
                    tabuleiro[tabX][tabY] = 1;
                }
            }
        }
    }

    // Exibir o tabuleiro resultante
    printf("Tabuleiro após sobreposição:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
        


    } else if (opcao == 2) {
        printf("Ataque especial Cruz selecionado.\n");

    int centroAtaqueX = 5;
    int centroAtaqueY = 5;
    
    int centroCruzX = 2;
    int centroCruzY = 3;

    // Calcular o offset para alinhar os centros
    int offsetX = centroAtaqueX - centroCruzX;
    int offsetY = centroAtaqueY - centroCruzY;

    // Aplicar a sobreposição
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            // Calcular posição no tabuleiro
            int tabX = i + offsetX;
            int tabY = j + offsetY;
            
            // Verificar se está dentro dos limites do tabuleiro
            if (tabX >= 0 && tabX < 10 && tabY >= 0 && tabY < 10) {
                // Se cruz tem 1 e tabuleiro tem 3, mudar para 5
                if (cruz[i][j] == 1 && tabuleiro[tabX][tabY] == 3) {
                    tabuleiro[tabX][tabY] = 5;
                }
                // Se cruz tem 1 e tabuleiro tem 0, pode colocar 1
                else if (cruz[i][j] == 1 && tabuleiro[tabX][tabY] == 0) {
                    tabuleiro[tabX][tabY] = 1;
                }
            }
        }
    }

    // Exibir o tabuleiro resultante
    printf("Tabuleiro após sobreposição:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
    } else if (opcao == 3) {
        printf("Ataque especial Octaedro selecionado.\n");

    int centroAtaqueX = 5;
    int centroAtaqueY = 5;
    
    int centroOctaedroX = 3;
    int centroOctaedroY = 3;

    // Calcular o offset para alinhar os centros
    int offsetX = centroAtaqueX - centroOctaedroX;
    int offsetY = centroAtaqueY - centroOctaedroY;

    // Aplicar a sobreposição
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            // Calcular posição no tabuleiro
            int tabX = i + offsetX;
            int tabY = j + offsetY;
            
            // Verificar se está dentro dos limites do tabuleiro
            if (tabX >= 0 && tabX < 10 && tabY >= 0 && tabY < 10) {
                // Se octaedro tem 1 e tabuleiro tem 3, mudar para 5
                if (octaedro[i][j] == 1 && tabuleiro[tabX][tabY] == 3) {
                    tabuleiro[tabX][tabY] = 5;
                }
                // Se octaedro tem 1 e tabuleiro tem 0, pode colocar 1
                else if (octaedro[i][j] == 1 && tabuleiro[tabX][tabY] == 0) {
                    tabuleiro[tabX][tabY] = 1;
                }
            }
        }
    }

    // Exibir o tabuleiro resultante
    printf("Tabuleiro após sobreposição:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    } else {
        printf("Opção inválida.\n");
    }
    
    
    return 0;
}
