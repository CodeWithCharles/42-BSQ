#include <stdlib.h>
#include <unistd.h>

void find_largest_square(char **map, int rows, int cols, char obstacle, char full_spaces)
{
    int **dp = malloc(rows * sizeof(int *));
    int i = 0;
    while (i < rows)
    {
        dp[i] = malloc(cols * sizeof(int));
        i++;
    }

    int max_size = 0, max_row = 0, max_col = 0;

    i = 0;
    while (i < rows)
    {
        int j = 0;
        while (j < cols) {
            if (map[i][j] == obstacle)
                dp[i][j] = 0;
            else
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                {
                    int min_val = dp[i-1][j];
                    if (dp[i][j-1] < min_val)
                        min_val = dp[i][j-1];
                    if (dp[i-1][j-1] < min_val)
                        min_val = dp[i-1][j-1];
                    dp[i][j] = 1 + min_val;
                }
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_row = i;
                    max_col = j;
                }
            }
            j++;
        }
        i++;
    }

    i = max_row;
    while (i > max_row - max_size)
    {
        int j = max_col;
        while (j > max_col - max_size)
        {
            map[i][j] = full_spaces;
            j--;
        }
        i--;
    }

    i = 0;
    while (i < rows)
    {
        free(dp[i]);
        i++;
    }
    free(dp);
}

int validate_map_columns(const char *map_str, int rows)
{
    int i = 0;
    int col_count = 0;
    int current_col_count = 0;
    int row = 0;

    while (map_str[i] != '\n')
        i++;
    i++;

    while (map_str[i] != '\0')
    {
        if (map_str[i] == '\n')
        {
            if (row == 0)
                col_count = current_col_count;
            else if (current_col_count != col_count)
                return 0;
            current_col_count = 0;
            row++;
        }
        else
            current_col_count++;
        i++;
    }

    if (current_col_count != col_count)
        return 0;

    return col_count;
}

int count_rows(const char *map_str)
{
    int i = 0;
    int row_count = 0;

    while (map_str[i] != '\n')
        i++;
    i++;

    while (map_str[i] != '\0')
    {
        if (map_str[i] == '\n')
            row_count++;
        i++;
    }

    if (map_str[i-1] != '\n')
        row_count++;

    return row_count;
}

void print_map(char **map, int rows, int cols)
{
    int i = 0;
    while (i < rows)
    {
        write(1, map[i], cols);
        write(1, "\n", 1);
        i++;
    }
}

int main()
{
    char map_str[1000] =  {"9.ox\n....o......................\n....o......................\n....o......................\n....o......................\n....o......................\n...............o...........\n...........................\n......o..............o.....\n..o.......o................"};

    // Etape 1: Extraire la map et les paramètres
    int i = 0;
    int max_row = count_rows(map_str);
    int row_count = 0;
    int max_col = 0;
    char empty_spaces = 0;
    char obstacle = 0;
    char full_spaces = 0;
    while (map_str[i] != '\n')
    {
        if (i == 0)
        {
            row_count = map_str[i] - '0';
            if (row_count == 0 || row_count < max_row || row_count > max_row)
            {
                write(1,"map error\n",10);
                return 1;
            }
        }
        if (i == 1)
            empty_spaces = map_str[i];
        if (i == 2)
            obstacle = map_str[i];
        if (i == 3)
            full_spaces = map_str[i];
        i++;
    }
    i++;
    // Etape 2: Validé la map
    max_col = validate_map_columns(map_str, max_row);
    if (max_col == 0)
    {
        write(1,"map error\n",10);
        return 1;
    }

    // Etape 3: Recréer la map
    char **map = malloc(max_row * sizeof(char *));
    i = 0;
    while (i < max_row)
    {
        map[i] = malloc((max_col + 1) * sizeof(char));
        i++;
    }

    int row = 0, col = 0;
    i = 5;
    while (map_str[i] != '\0')
    {
        if (map_str[i] == '\n')
        {
            row++;
            col = 0;
        } 
        else
            map[row][col++] = map_str[i];
        i++;
    }

    // Etape 4: Trouvé le plus grand carré
    find_largest_square(map, max_row, max_col, obstacle, full_spaces);

    // Etape 5: Afficher la map
    print_map(map, max_row, max_col);

    // Etape 6: Libérer la mémoire
    i = 0;
    while (i < max_row)
    {
        free(map[i]);
        i++;
    }
    free(map);

    return 0;
}
