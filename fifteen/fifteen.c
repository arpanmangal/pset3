/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// empty tile of borad
int empty_row;
int empty_col;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int row, col, elem;
    for(row = 0; row < d; row++)
    {  
        for(col = 0; col < d; col++)
        {
            // assigns tiles value for normal cases
            elem = d * d - 1 - row * d - col;
            if (row == col == d - 1)
            {
                // last element
                elem = 0;
            }
            else if (!(d % 2) && row == d - 1)
            {
                // for odd tile board swap 1 and 2
                if (col == d - 2)
                {
                    elem = 2;
                }
                else if (col == d - 3)
                {
                    elem = 1;
                }
            }
            
            board[row][col] = elem;
        }
    }
    empty_row = empty_col = d - 1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    int row, col;

    for(row = 0; row < d; row++)
    {
        for(col = 0; col < d; col++)
        {
            if (board[row][col] == 0)
            {
                printf("  _");
            }
            else
            {
                printf(" %2d", board[row][col]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int row, col, tile_row, tile_col;
    int brk = 0;
    // search for tile
    for(row = 0; row < d; row++)
    {
        for(col = 0; col < d; col++)
        {
            if (board[row][col] == tile)
            {
                tile_row = row;
                tile_col = col;
                brk = 1;
                break;
            }
        }
        if (brk)
        {
            break;
        }
    }
    
    // check if valid move
    if (abs(empty_row - tile_row) + abs(empty_col - tile_col) == 1)
    {
        board[empty_row][empty_col] = tile;
        empty_row = tile_row;
        empty_col = tile_col;
        board[empty_row][empty_col] = 0;
        return true;
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    int row, col;
    for(row = 0; row < d; row++)
    {
        for(col = 0; col < d; col++)
        {
            // check if not last element
            if (row + col != 2 * d - 2)
            {
                // check if equal to desired value
                if (board[row][col] != row * d + col + 1)
                {
                    // not yet won the game
                    return false;
                }
            }
        }
    }
    // game won
    return true;
}