#include <stdio.h>
#include <stdlib.h>
int main()
{
   int rounds;

   do
   {
      scanf("%d", &rounds);
   } while (rounds < 1 || rounds > 11);
   for (int game = 0; game < rounds; game++)

   {
      int win    = 0;
      int defeat = 0;
      int size;
      do
      {
         scanf("%d", &size);
      } while (size < 1 || size > 101);
      char board[size][size];
      int  i, j;
      for (i = 0; i < size; i++)
      {
         for (j = 0; j < size; j++)
         {
            scanf("%s", &board[i][j]);
         }
      }
      int play;
      scanf("%d", &play);
      for (int k = 0; k < play; k++)
      {
         int br, bc;
         scanf("%d %d", &br, &bc);
         if (board[br][bc] == 'b')
         {
            defeat = 1;
         }
         else if ((br == 0) && (bc == 0))
         {
            board[br][bc] = 'o';
            int r = 0;
            for (int rl = (br); rl < (br + 2); rl++)
            {
               for (int rc = (bc); rc < (bc + 2); rc++)
               {
                  if (board[rl][rc] != 'b')
                  {
                     r++;
                  }
               }
            }
            if (r == 4)
            {
               for (int rl = br; rl < br + 2; rl++)
               {
                  for (int rc = bc; rc < bc + 2; rc++)
                  {
                     board[rl][rc] = 'o';
                  }
               }
            }
         }
         else if ((br == size - 1) && (bc == size - 1))
         {
            board[br][bc] = 'o';
            int r = 0;
            for (int rl = (br - 1); rl < (br + 1); rl++)
            {
               for (int rc = (bc - 1); rc < (bc + 1); rc++)
               {
                  if (board[rl][rc] != 'b')
                  {
                     r++;
                  }
               }
            }
            if (r == 4)
            {
               for (int rl = br - 1; rl < br + 1; rl++)
               {
                  for (int rc = (bc - 1); rc < bc + 1; rc++)
                  {
                     board[rl][rc] = 'o';
                  }
               }
            }
         }
         else
         {
            board[br][bc] = 'o';
            int r = 0;
            for (int rl = (br - 1); rl < (br + 2); rl++)
            {
               for (int rc = (bc - 1); rc < (bc + 2); rc++)
               {
                  if (board[rl][rc] != 'b')
                  {
                     r++;
                  }
               }
            }
            if (r == 9)
            {
               for (int rl = br - 1; rl < br + 2; rl++)
               {
                  for (int rc = bc - 1; rc < bc + 2; rc++)
                  {
                     board[rl][rc] = 'o';
                  }
               }
            }
         }
      }
      for (i = 0; i < size; i++)
      {
         for (j = 0; j < size; j++)
         {
            if ((board[i][j] == 'b') || (board[i][j] == 'o'))
            {
               win++;
            }
         }
      }
      if ((defeat == 1) && win < (size * size))
      {
         printf("PERDEU\n");
         continue;
      }
      if (defeat == 0 && win < (size * size))
      {
         printf("NÃO TERMINOU\n");
      }
      if (win == (size * size))
      {
         printf("GANHOU\n");
      }
   }
   return(0);
}
