char **split(char *src)
{
    char **result;
    int word_count;
    int i, j, k;
    int start, len;

    // Si la chaîne est vide ou NULL
    if (src == 0 || src[0] == '\0')
    {
        result = (char **)malloc(sizeof(char *));
        result[0] = 0;
        return result;
    }

    // Compter le nombre de mots
    word_count = 0;
    i = 0;
    while (src[i] != '\0')
    {
        // Passer les délimiteurs
        while (src[i] == ' ' || src[i] == '\t' || src[i] == '\n')
            i++;
        if (src[i] != '\0')
            word_count++;
        // Aller à la fin du mot
        while (src[i] != '\0' && src[i] != ' ' && src[i] != '\t' && src[i] != '\n')
            i++;
    }

    // Allouer le tableau de pointeurs (+1 pour NULL)
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (result == 0)
        return 0;

    // Remplir le tableau avec les mots
    i = 0;
    k = 0;
    while (src[i] != '\0' && k < word_count)
    {
        // Passer les délimiteurs
        while (src[i] == ' ' || src[i] == '\t' || src[i] == '\n')
            i++;
        if (src[i] == '\0')
            break;

        // Trouver le début et la longueur du mot
        start = i;
        while (src[i] != '\0' && src[i] != ' ' && src[i] != '\t' && src[i] != '\n')
            i++;
        len = i - start;

        // Allouer la mémoire pour le mot
        result[k] = (char *)malloc(sizeof(char) * (len + 1));
        if (result[k] == 0)
            return 0;

        // Copier le mot
        j = 0;
        while (j < len)
        {
            result[k][j] = src[start + j];
            j++;
        }
        result[k][j] = '\0';
        k++;
    }
    result[word_count] = 0;  // Terminer par NULL

    return result;
}