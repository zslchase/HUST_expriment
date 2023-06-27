#include "hellodpll.h"
#include "sudoku.cpp"
#include "cnf_translater.cpp"
#include "DPLL.cpp"

int main()
{
    int x = 1, result, i;
    // LIST* HEAD;
    // FILE* fp;
    // clock_t Start1,End1;
    while(x)
    {
        system("cls");
        printf("\n\n");
        printf("_________________________________________________\n");
        printf("|");
        setColor(13,0);
        printf("                      MENU                      ");
        setColor(7,0);
        printf("|\n");
        printf("|------------------------------------------------|\n");
        printf("|                     1. SAT                     |\n");
        printf("|                     2. SUDOKU                  |\n");
        printf("|                     0. BACK                    |\n");
        printf("|                  CHOOSE FUNCTION:              |\n");
        printf("|________________________________________________|\n");
        scanf("%d", &x);
        if(x==1)
        {
            SAT_FUNCTION();
        }

        else if(x==0) {
            printf("\nBye bye~;");
            system("Pause");
            return 0;
        }
        else if(x==2){
            if(SUDOKU_FUNCTION()==-1);
        }

        else
        {
            printf("\nILLIGAL FUNCTION!\n");
            getchar();
			getchar(); 
        }
    }
    return OK;
}
