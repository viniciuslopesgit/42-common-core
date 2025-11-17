typedef struct s_point
{
    int x;
    int y;
} t_point;

// Função auxiliar para preencher recursivamente
void fill(char **tab, t_point size, t_point cur, char target)
{
    // Verifica se a posição atual é válida e tem o caractere alvo
    if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y)
        return;
    if (tab[cur.y][cur.x] != target)
        return;
    
    // Preenche a posição atual
    tab[cur.y][cur.x] = 'F';
    
    // Chama recursivamente para as 4 direções (cima, baixo, esquerda, direita)
    t_point up = {cur.x, cur.y - 1};
    t_point down = {cur.x, cur.y + 1};
    t_point left = {cur.x - 1, cur.y};
    t_point right = {cur.x + 1, cur.y};
    
    fill(tab, size, up, target);
    fill(tab, size, down, target);
    fill(tab, size, left, target);
    fill(tab, size, right, target);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    // Verifica se o ponto inicial é válido
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return;
    
    // Obtém o caractere original na posição inicial
    char target = tab[begin.y][begin.x];
    
    // Se o caractere já é 'F', não precisa processar
    if (target == 'F')
        return;
    
    // Inicia o preenchimento a partir do ponto begin
    fill(tab, size, begin, target);
}


