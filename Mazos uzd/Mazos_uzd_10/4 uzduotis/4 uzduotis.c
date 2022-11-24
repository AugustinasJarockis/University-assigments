#include <stdio.h>
#include <assert.h>

char *strstr (const char *s1, const char *s2);

int main()
{
    char *s1 = "BigMacas";
    char *s2 = "Mac";
    assert(strstr(s1, s2) == s1 + 3 * sizeof(char));
    char *s3 = "Krabozauras";
    char *s4 = "zauras";
    assert(strstr(s3, s4) == s3 + 5 * sizeof(char));
    char *s5 = "Dundine";
    char *s6 = "unine";
    assert(strstr(s5, s6) == NULL);
    char *s7 = NULL;
    char *s8 = "unine";
    assert(strstr(s7, s8) == NULL);
    char *s9 = "Bavarija";
    char *s10 = NULL;
    assert(strstr(s9, s10) == s9);
    char *s11 = "Bavarija";
    char *s12 = "\0";
    assert(strstr(s11, s12) == s11);
    return 0;
}

char *strstr (const char *s1, const char *s2)
{
    if(s1 == NULL)
    {
        return NULL;
    }
    if(s2 == NULL || s2[0] == '\0')
    {
        return s1;
    }
    int i = 0;
    while(s1[i] != '\0')
    {
        if(s1[i] == s2[0])
        {
            char *start = s1 + i * sizeof(char);
            int start_i = i;
            int y = 0;
            while(s1[i] == s2[y])
            {
                i++;
                y++;
                if(s2[y] == '\0')
                {
                    return start;
                }
            }
            i = start_i;
        }
        i++;
    }
    return NULL;
}
