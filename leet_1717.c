#include <stdio.h>
#include <string.h>

int maximumGain(char* s, int x, int y) {
    if (!s || strlen(s) == 0) {
        return 0;
    }
    
    int tam = strlen(s);
    int totalPoints = 0;
    
    char first1, first2, second1, second2;
    int points1, points2; 
    
    if (x >= y) {
        // remove primeiro "ab", depois "ba"
        first1 = 'a'; second1 = 'b'; points1 = x;
        first2 = 'b'; second2 = 'a'; points2 = y;
    } else {
        // remove primeiro "ba", depois "ab"
        first1 = 'b'; second1 = 'a'; points1 = y;
        first2 = 'a'; second2 = 'b'; points2 = x;
    }
    
    // remove os de maior valor primeiro
    int top = -1;
    for (int i = 0; i < tam; i++) {
        if (top >= 0 && s[top] == first1 && s[i] == second1) {
            top--;
            totalPoints += points1;
        } else {
            s[++top] = s[i];
        }
    }
    
    // atualiza o tamanho da string restante
    tam = top + 1;
    
    // remove os de menor valor
    top = -1;
    for (int i = 0; i < tam; i++) {
        if (top >= 0 && s[top] == first2 && s[i] == second2) {
            top--;
            totalPoints += points2;
        } else {
            s[++top] = s[i];
        }
    }
    
    return totalPoints;
}

int main() {
    char str[100];
    int x, y;

    printf("Digite a string: ");
    scanf("%s", str);

    printf("Digite o valor de x (pontos para 'ab'): ");
    scanf("%d", &x);

    printf("Digite o valor de y (pontos para 'ba'): ");
    scanf("%d", &y);

    int resultado = maximumGain(str, x, y);
    printf("Pontuação máxima: %d\n", resultado);

    return 0;
}
