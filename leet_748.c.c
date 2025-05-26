char* shortestCompletingWord(char* licensePlate, char** palavra,
                             int tamanho_palavra) {
    int alfabeto[26] = {0}; // começa por 0 pra contar
    char* final = NULL;     // incializa zerado pra armazenar depois

    while (*licensePlate != '\0') {
        if ((*licensePlate >= 'a' && *licensePlate <= 'z') ||
            (*licensePlate >= 'A' && *licensePlate <= 'Z')) {
            if (*licensePlate >= 'a' && *licensePlate <= 'z') {
                alfabeto[*licensePlate - 'a']++;
            } else {
                alfabeto[*licensePlate - 'A']++;
            }
        }
        licensePlate++;
    }

    int tam_maximo = 30;

    for (int i = 0; i < tamanho_palavra; i++) { 
        int contagem[26] = {0};
        char* tmps = palavra[i];

        while (*tmps != '\0') {
            if (*tmps >= 'a' && *tmps <= 'z') {
                contagem[*tmps - 'a']++;
            } else if (*tmps >= 'A' && *tmps <= 'Z') {
                contagem[*tmps - 'A']++;
            }
            tmps++;
        }

        int resultado = 0;

        for (int j = 0; j < 26; j++) {
            if (alfabeto[j] > 0 && contagem[j] < alfabeto[j]) {
                resultado = 1;
                break;
            }
        }

        if (resultado == 0) {
            if (final == NULL || strlen(palavra[i]) < strlen(final)) {
                final = palavra[i];
            }
        }
    }

    return final;
}
