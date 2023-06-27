#include "hellodpll.h"

int find_solution(){
    // CNF_TRANSLATER_SUDOKU();
    LIST *POSITION,*HEAD;
    int i,k,b,c;
    memset(sudoku_solution,0,sizeof(sudoku_solution));
    for(i=0;i<1000;i++){
        sudoku_solution[i]=RESULT[i];
    }
    b=0;
    // show();
    // printf("\n");
    // print();
    for(i=0;i<9;i++){
        for(k=0;k<9;k++){
            if(sudoku_dig[i][k]==0){
                holes_mark[b][0]=i;
                holes_mark[b][1]=k;
                // printf("%d ",sudoku_begin[i][k]);
                // holes_mark[b][2]=sudoku_begin[i][k];
                for(c=(i+1)*100+(k+1)*10;c<(i+1)*100+(k+1)*10+9;c++){
                    if(RESULT[c])holes_mark[b][2]=c-((i+1)*100+(k+1)*10-1);
                }
                //printf("%d ",holes_mark[b][2]);
                b++;        
            }
        }
    }
    printf("The sudoku problem:\n\n");
    show();
    printf("\nThere are %d holes in this sudoku problem:\nThe positions of holes are as follows:\n",b);
    for(i=0;i<b;i++){
        printf("(%d,%d)  ",holes_mark[i][1]+1,holes_mark[i][0]+1);
        if((i+1)%5==0)printf("\n");
    }
    printf("\nNow plsase input your solution of this sudoku problem in the order above:(Input 0 to exit)\n");
    for(i=0;i<b;i++){
        scanf("%d",&c);
        if(c==sudoku_begin[holes_mark[i][0]][holes_mark[i][1]])continue;
        //if(c==holes_mark[b][2])continue;
        else if(c==0)break;
        else {
            system("cls");
            printf("Wrong answer!\nPlease input once again.");
            i=-1;
            printf("The sudoku problem:\n\n");
            show();
            printf("\nThere are %d holes in this sudoku problem:\nThe position of holes are as follows:\n",b);
            for(k=0;k<b;k++){
                printf("(%d,%d)  ",holes_mark[k][1]+1,holes_mark[k][0]+1);
                if((k+1)%5==0)printf("\n");
            }
            printf("\nNow plsase input your solution of this sudoku problem in the order above:(Input 0 to exit)\n");
        }
    }
    system("cls");
    printf("Right answer!\nCongratulations!\n");
    system("Pause");
    return 0;
}

int SUDOKU_FUNCTION(){
    int i,k,b,c,flag=0;
            system("cls");
            setColor(5,0);
            printf("\n---------------FUNCTION <SUDOKU>-----------------\n\n");
            setColor(7,0);
            createSudoku(sudoku_begin);
            for(i=0;i<9;i++){
                for(k=0;k<=9;k++){
                    line_mark[i][k]=1;
                    row_mark[i][k]=1;
                }
            }
            for(i=0;i<3;i++){
                for(k=0;k<3;k++){
                    for(b=0;b<10;b++){
                        unit_mark[i][k][b]=1;
                    }
                }
            }
            int hole_num;
            // printf("Input the number of holes you want to dig\n(Input 0 to get sudoku problem from existed files):");
            printf("_________________________________________________\n");
            setColor(14,0);
            printf("|    Input the number of holes you want to dig   |\n");
            setColor(7,0);
            printf("|------------------------------------------------|\n");
            printf("|Input 0 to get sudoku problem from existed files|\n");
            printf("|                                                |\n");
            printf("|                  Please input:                 |\n");
            printf("|________________________________________________|\n");
            scanf("%d",&hole_num);
            if(hole_num!=0)
            {        Start1=clock();
                    createStartinggrid(hole_num);
                    End1=clock();}
            else {
                    flag=1;
                    char c,tmp[10480],name[100],filename[100];
                    system("cls");
                    // printf("                        Input filename:");
                    printf("_________________________________________________\n");
                    setColor(14,0);
                    printf("|        Input filename you want to read_in      |\n");
                    setColor(7,0);
                    printf("|------------------------------------------------|\n");
                    printf("|                  Please input:                 |\n");
                    printf("|________________________________________________|\n");
                    scanf("%s",filename);
                    strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\");
                    strcat(name,filename);
                    strcat(name,".ss");
                    fp=fopen(name, "r+");
                    for(i=0,k=0;;){
                        c=getc(fp);
                        if(c=='!')continue;
                        else if(c=='.'){
                            sudoku_dig[i][k]=0;
                            hole_num++;
                        }
                        else if(c=='-'){
                            char tmp[10471];
                            fgets(tmp,10470,fp);
                            continue;
                        }
                        else {
                            sudoku_dig[i][k]=c-'0';
                        }
                        // x+(y+1)/9,(y+1)%9+1
                        if(i==8&&k==8)break;
                        if(k==8)getc(fp);
                        i=i+(k+1)/9;
                        k=(k+1)%9;
                    }
            }



            ToCnf(sudoku_dig,hole_num);
            printf("Digtime: %lf ms\n",(double)(End1-Start1)/CLOCKS_PER_SEC*1000.0);
            //printf("The sudoku problem has been translated to .cnf foramt and been saved in the file ""sudoku.cnf"" \n");
            printf("The preview of this sudoku problem:\n\n");
            show();
            printf("\n\n");
            int sh;
            // printf("Input 1 to show the translated data of the sudoku problem\nInput 0 to skip\n");
            // printf("_________________________________________________\n");
            // printf("|                 Choose a function              |\n");
            // printf("|------------------------------------------------|\n");
            // printf("|                  INDEX1:Show solution:         |\n");
            // printf("|                  INDEX2:DPLL solution:         |\n");
            // printf("|                  INDEX3:Exit:                  |\n");
            // printf("|                                                |\n");
            // printf("|                  Please input:                 |\n");
            // printf("|________________________________________________|\n");
            // scanf("%d",&sh);
            sh=0;
            system("Pause");
            LIST *POSITION;
            node *p;
            CNF_TRANSLATER_SUDOKU();
            char name[100];
            if(sh==1){
                POSITION=HEAD->NEXT;
                for(;POSITION!=NULL;POSITION=POSITION->NEXT){
                    p=POSITION->head;
                    for(;p!=NULL;p=p->next){
                        printf("%d ",p->data);
                    }
                    printf("  length=%d\n",POSITION->length);
                }
            }
            // system("Pause");
            system("cls");
            printf("NOW LET'S SOLVE THIS SAT PROBLEM!\n\n");
            printf("_________________________________________________\n");
            setColor(14,0);
            printf("|     Please choose your selection strategy      |\n");
            setColor(7,0);
            printf("|------------------------------------------------|\n");
            printf("|                  INDEX1:Normal:                |\n");
            printf("|                  INDEX2:Optimized:             |\n");
            printf("|                  INDEX3:RANDOM:                |\n");
            printf("|                                                |\n");
            printf("|                  Please input:                 |\n");
            printf("|________________________________________________|\n");
            scanf("%d",&INDEX);


            for(i=0;i<m;i++){
                int position;
                position=max_element(times+1,times+m+1)-times;
                maxtimes[i]=position;
                // printf("%d ",position);
                times[position]=-1;
            }
            // printf("\n");
            // for(i=0;i<m;i++){
            //     printf("%d ",maxtimes[i]);
            // }
            // system("Pause");

            // int RESULT[m];                             // 真值表
            memset(RESULT,-1,sizeof(RESULT));
            clock_t Start,End;
            Start=clock();
            b=DPLL(HEAD, RESULT,maxtimes);
                End=clock();
                printf("Runtime: %lf ms\n",(double)(End-Start)/CLOCKS_PER_SEC*1000.0);
                printf("The solution has been saved in the file ""for.res""\n");
                // scanf("%s",filename);
                strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\for.res");
                // strcat(name,filename);
                // strcat(name,".res");
                // fp=fopen(name, "w");
                if(b) {
                    fprintf(fp,"s 1\nv \n");
                    for(i=0;i<m;i++){
                        if(RESULT[i]!=0){
                            fprintf(fp,"%6d ",i+1);
                        }
                        else {
                            fprintf(fp,"%6d ",-i-1);
                        }
                    }
                }
				else fprintf(fp,"s 0\n");
                fclose(fp);
                system("Pause");

            system("cls");
            find_solution();
            for(i=0,k=0;i<9;i++){
                for(;k<9;k++){
                    sudoku_begin[i][k]=sudoku_dig[i][k];
                }
            }
            for(i=0,k=0;i<9;i++){
                for(;k<9;k++){
                    if(sudoku_begin[i][k])continue;
                    for(c=(i+1)*100+(k+1)*10;c<(i+1)*100+(k+1)*10+9;c++){
                    if(RESULT[c])sudoku_begin[i][k]=c-((i+1)*100+(k+1)*10-1);
                }
                }
            }
            // printf("\n\nInput 1 to show solution\nInput 2 to show the DPLL solution\nInput 0 to exit:");
            printf("_________________________________________________\n");
            setColor(14,0);
            printf("|                 Choose a function              |\n");
            setColor(7,0);
            printf("|------------------------------------------------|\n");
            printf("|                  INDEX1:Show solution:         |\n");
            printf("|                  INDEX2:DPLL solution:         |\n");
            printf("|                  INDEX0:Exit:                  |\n");
            printf("|                                                |\n");
            printf("|                  Please input:                 |\n");
            printf("|________________________________________________|\n");
            scanf("%d",&b);
            while(b!=0){
                if(b==1){
                    print();
                }
                else if(b==2){
                    for(i=0;i<999;i++){
                        if(RESULT[i]!=0){
                        printf("%d ",i+1);
                    }
                    else {
                        printf("-%d ",i+1);
                        }
                    if((i+1)%5==0)printf("\n");
                        }
                }
                else printf("Illigal index!");
                system("Pause");
                system("cls");
                // getchar();
                getchar();
            printf("_________________________________________________\n");
            setColor(14,0);
            printf("|                 Choose a function              |\n");
            setColor(7,0);
            printf("|------------------------------------------------|\n");
            printf("|                  INDEX1:Show solution:         |\n");
            printf("|                  INDEX2:DPLL solution:         |\n");
            printf("|                  INDEX0:Exit:                  |\n");
            printf("|                                                |\n");
            printf("|                  Please input:                 |\n");
            printf("|________________________________________________|\n");
                scanf("%d",&b);
            }
            printf("Bye bye~\n");
            system("Pause");
            return 0;
}
