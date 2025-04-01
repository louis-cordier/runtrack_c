int my_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    
    // Si une chaîne est terminée avant l'autre
    if (s1[i] == '\0' && s2[i] != '\0')
        return -s2[i];
    if (s2[i] == '\0' && s1[i] != '\0')
        return s1[i];
    
    // Si les deux chaînes sont identiques
    return 0;
}