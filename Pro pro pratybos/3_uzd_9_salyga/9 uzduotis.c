#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 256

void conjoinWords(char **text, int line_nr);
void removeSymbol(char **text, int line_nr, int symbol_nr);

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        printf("Error: Please input input and output files\n");
        return 0;
    }
    char** text = NULL;
    char* input_file = argv[1];
    char* output_file = argv[2];
    FILE* in_file = fopen(input_file, "r");
    if(in_file == NULL)
    {
        printf("Error: Input file could not be created\n");
        return 0;
    }

    int line_c = 0;
    while(!feof(in_file))
    {
        text = realloc(text, (line_c + 1) * sizeof(char*));
        if(text == NULL)
        {
            printf("Error: Memory could not be allocated\n");
            return 0;
        }
        int buffer_size = LINE_SIZE;
        text[line_c] = calloc(buffer_size, sizeof(char));
        if(text[line_c] == NULL)
        {
            printf("Error: String memory could not be allocated\n");
            return 0;
        }
        int char_c = getline(&(text[line_c]), &buffer_size, in_file);
        if(char_c > LINE_SIZE)
        {
            buffer_size = LINE_SIZE;
            text[line_c] = realloc(text[line_c], buffer_size * sizeof(char));
            text[line_c][LINE_SIZE - 1] = '\n';
        }
        line_c++;
    }
    fclose(in_file);

    for(int i = 0; i < line_c; i++)
    {
        conjoinWords(text, i);
    }
    FILE* out_file = fopen(output_file, "w");
    if(out_file == NULL)
    {
        printf("Error: Output file could not be created\n");
        return 0;
    }

    for(int i = 0; i < line_c; i++)
    {
        fprintf(out_file, "%s", text[i]);
    }
    fclose(out_file);

    for(int i = 0; i < line_c; i++)
    {
        free(text[i]);
    }
    free(text);
    return 0;
}

void conjoinWords(char **text, int line_nr)
{
    for(int symbol_nr = 1; text[line_nr][symbol_nr] != '\0' && symbol_nr < LINE_SIZE; symbol_nr++)
    {
        if(text[line_nr][symbol_nr] == ' ')
        {
            //Find the next non-space symbol
            int gap = 1;
            while(text[line_nr][symbol_nr + gap] == ' ')
            {
                gap++;
            }

            if(text[line_nr][symbol_nr - 1] == text[line_nr][symbol_nr + gap])
            {
                removeSymbol(text, line_nr, symbol_nr);
                symbol_nr--;
            }
        }
    }
}

void removeSymbol(char **text, int line_nr, int symbol_nr)
{
    for(int i = symbol_nr; text[line_nr][i] != '\0' && i < LINE_SIZE - 1; i++)
    {
        text[line_nr][i] = text[line_nr][i + 1];
    }
    text[line_nr][LINE_SIZE - 1] = '\0';
}
