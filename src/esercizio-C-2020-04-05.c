#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_ROWS 10
#define BLOCK_CURRENT 50

int main ()
{
    char ch;
    int n = 0;
    int tot_rows = BLOCK_ROWS, n_row = 0, tot_current = BLOCK_CURRENT; //Byte allocati di rows, numero riga corrente, byte allocati di current
    char **rows = malloc (tot_rows * sizeof (char *)); //Righe
    char *current = malloc (tot_current * sizeof (char)); //Riga corrente
    while ((ch = getchar ()) != EOF)
    {
        if (ch == '\n')
        {
            //Salvo currente in rows[n_row]
            current[n] = '\0';
            rows[n_row] = malloc (n * sizeof (char));
            memcpy (rows[n_row],current,n * sizeof (char));
            //Controllo eventuali duplicati
            for (int i = 0; i < n_row; i++)
            {
                if (!strcmp (current, rows[i]))
                    printf ("***questa riga è stata già letta %d righe fa***\n", n_row - i);
            }
            //Incremenento n_row ed eventualmente alloco altro spazio per rows
            n_row++;
            if (n_row == tot_rows)
            {
                tot_rows += BLOCK_ROWS;
                rows = realloc (rows, tot_rows * sizeof (char *));
            }
            //Per la prossima riga
            n = 0;
        }
        else
            current[n++] = ch;
        //Eventualmente alloco altro spazio per current
        if (n == tot_current)
        {
            tot_current += BLOCK_CURRENT;
            current = realloc (current, tot_current * sizeof (char));
        }
    }
    return 0;
}
