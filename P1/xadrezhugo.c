    #include <stdio.h>
    
    // Função pra ver os tiros de Luiza
    // Consiste em verificar se há algum jogador nas diagonais
    // Se achar um jogador, ganha uma kill, para o for e verifica a próxima diagonal
    // Se achar o Anderson, só para o for e verifica a próxima diagonal
    void bulletLuiza(int n, int matriz[n][n], int x, int y, int xAnderson, int yAnderson, int *kills)
    {
        for(int i = x, j = y; i < n, j < n; i++, j++)
        {
            // Verificação se achou o Anderson
            if(i == xAnderson && j == yAnderson)
            {
                break;
            }
            // Verificação se achou um jogador
            if(matriz[i][j] == 1)
            {
                (*kills)++;
                matriz[i][j] = 0;
                break;
            }
        }
    
        for(int i = x, j = y; i >= 0, j < n; i--, j++)
        {
            if(i == xAnderson && j == yAnderson)
            {
                break;
            } 
            if(matriz[i][j] == 1)
            {
                (*kills)++;
                matriz[i][j] = 0;
                break;
            }
        }
    
        for(int i = x, j = y; i < n, j >= 0; i++, j--)
        {
            if(i == xAnderson && j == yAnderson)
            {
                break;
            } 
            if(matriz[i][j] == 1)
            {
                (*kills)++;
                matriz[i][j] = 0;
                break;
            }
        }
    
        for(int i = x, j = y; i >= 0, j >= 0; i--, j--)
        {
            if(i == xAnderson && j == yAnderson)
            {
                break;
            }        
            if(matriz[i][j] == 1)
            {
                (*kills)++;
                matriz[i][j] = 0;
                break;
            }
        }
    
        return;
    }
    
    // Função pra ver os tiros de Anderson
    // Consiste em verificar se há algum jogador na esquerda, direita, encima e embaixo (a linha/coluna inteira)
    // Se achar um jogador, ganha uma kill, para o for e verifica a próxima direção
    // Se achar a Luiza, só para o for e verifica a próxima diagonal
    void bulletAnderson(int n, int matriz[n][n], int x, int y, int xLuiza, int yLuiza, int *kills)
    {
        for(int i = x; i < n; i++)
        {
            // Verificação se achou a Luiza
            if(i == xLuiza && y == yLuiza)
            {
                break;
            }
            // Verifica se achou um jogador
            if(matriz[i][y] == 1)
            {
                (*kills)++;
                matriz[i][y] = 0;
                break;
            }
        }
    
        for(int i = x; i >= 0; i--)
        {
            if(i == xLuiza && y == yLuiza)
            {
                break;
            }
            if(matriz[i][y] == 1)
            {
                (*kills)++;
                matriz[i][y] = 0;
                break;
            }
        }
    
        for(int j = y; j >= 0; j--)
        {
            if(x == xLuiza && j == yLuiza)
            {
                break;
            }
            if(matriz[x][j] == 1)
            {
                (*kills)++;
                matriz[x][j] = 0;
                break;
            }
        }
    
        for(int j = y; j < n; j++)
        {
            if(x == xLuiza && j == yLuiza)
            {
                break;
            }
            if(matriz[x][j] == 1)
            {
                (*kills)++;
                matriz[x][j] = 0;
                break;
            }
        }
    
        return;
    }
    
    int main()
    {
        int n, xLuiza, yLuiza, xAnderson, yAnderson, killsLuiza = 0, killsAnderson = 0;
        scanf("%d", &n);
    
        int matriz[n][n];
    
        // Scan da matriz
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }
    
        // Scan das posições de Luiza e Anderson
        scanf("%d %d %d %d", &xLuiza, &yLuiza, &xAnderson, &yAnderson);
    
        // Chama as funções q resolvem a questão (passando as kills como ponteiro para printar na main mas pode ser alterado)
        bulletLuiza(n, matriz, xLuiza, yLuiza, xAnderson, yAnderson, &killsLuiza);
        bulletAnderson(n, matriz, xAnderson, yAnderson, xLuiza, yLuiza, &killsAnderson);
    
        printf("aziul matou %d\nnosredna matou %d\n", killsLuiza, killsAnderson);
        
        return 0;
    }