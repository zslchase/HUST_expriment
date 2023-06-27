#include "hellodpll.h"

LIST* single(LIST* HEAD)
{
    LIST* POSITION = HEAD;
    while(POSITION)
    {
        if(POSITION->head && !POSITION->head->next)    return POSITION;
        POSITION = POSITION->NEXT;
    }
    return NULL;
}


LIST *Copy(LIST *L){
    LIST *NEWHEAD;
    LIST *POSITION;
    LIST *COPY=L->NEXT;
    NEWHEAD=(LIST*)malloc(sizeof(LIST));
    NEWHEAD->NEXT=NULL;
    NEWHEAD->head=NULL;
    POSITION=NEWHEAD;
    for(;COPY!=NULL;COPY=COPY->NEXT){

        POSITION->NEXT=(LIST*)malloc(sizeof(LIST));
        POSITION=POSITION->NEXT;
        POSITION->NEXT=NULL;

        POSITION->length=COPY->length;
        node *p;
        node *copyp=COPY->head;
        if(copyp!=NULL){
            POSITION->head=(node*)malloc(sizeof(node));
            p=POSITION->head;
            p->data=copyp->data;
            p->next=NULL;
            copyp=copyp->next;
            //POSITION->head=p;
            //2ù???è°?

            for(;copyp!=NULL;copyp=copyp->next){

                p->next=(node*)malloc(sizeof(node));
                p=p->next;
                p->next=NULL;

                p->data=copyp->data;
            }
        //p->next=NULL;
        }
        else {
            POSITION->head=NULL;
        }
    }
    return NEWHEAD;
}



LIST* add(LIST* HEAD, int value)
{
    LIST* POSITION;
    POSITION = (LIST *)malloc(sizeof(LIST));
    POSITION->head = (node *)malloc(sizeof(node));
    POSITION->head->data = value;
    POSITION->head->next = NULL;
    POSITION->NEXT = HEAD->NEXT;
    HEAD->NEXT = POSITION;
    return HEAD;
}

int choose(LIST* HEAD,int index,int RESULT[],int maxtimes[])
{
    if(index==2){
        int i;
        for(i=0;i<m;i++){
            if(RESULT[maxtimes[i]-1]==-1){
                int p=maxtimes[i];
                RESULT[maxtimes[i]-1]=1;
                return p;
                // if(pos[maxtimes[i]]>=neg[maxtimes[i]])return p;
                // else return -p;
            }
        }
        int value = HEAD->NEXT->head->data;
        return value;
    }
    else if(index==1){
        int i;
        for(i=m-1;i>=0;i--){
            if(RESULT[maxtimes[i]-1]==-1){
                int p=maxtimes[i];
                RESULT[maxtimes[i]-1]=1;
                return p;
                // if(pos[maxtimes[i]]>=neg[maxtimes[i]])return p;
                // else return -p;
            }
        }
        int value = HEAD->NEXT->head->data;
        return value;
    }
    else {
        int value = HEAD->NEXT->head->data;
        return value;
    }

}

LIST* deletelist(LIST* HEAD)
{
    LIST* POSITION = HEAD;
    node* p;
    for(;HEAD->head;)
    {
        p = HEAD->head;
        HEAD->head = HEAD->head->next;
        free(p);
    }
    HEAD = HEAD->NEXT;
    free(POSITION);
    return HEAD;
}


LIST* deletenode(LIST* HEAD, int value)
{
    node *p = HEAD->head, *tmp;
        for(;HEAD->head;){
            p=HEAD->head;
            if(p->data!=value&&p->data!=-value)break;
            else {
                if(p->data==value)return NULL;
                else {
                    tmp=HEAD->head->next;
                    free(p);
                    HEAD->head=tmp;
                }
            }
    }
    p=HEAD->head;
    while(p)
    {
        if(p->next && p->next->data == -value)
        {
            tmp = p->next;
            p->next = p->next->next;
            free(tmp);
        }
        else if(p->next && p->next->data == value)  return NULL;
        p = p->next;
    }
    return HEAD;
}

int DELETE_(LIST* HEAD, int value)
{
    LIST *POSITION = HEAD->NEXT, *POSITION_ = HEAD;
    for(;POSITION!=NULL;)                                    
    {
        POSITION = deletenode(POSITION, value);
        if(POSITION == NULL)
        {
            POSITION = deletelist(POSITION_->NEXT);
            POSITION_->NEXT = POSITION;
            continue;
        }
        if(POSITION == NULL)   break;
        POSITION_ = POSITION;
        POSITION = POSITION->NEXT;
    }
    return OK;
}



int empty(LIST* HEAD)
{
    LIST* POSITION = HEAD->NEXT;
    while(POSITION)
    {
        if(!POSITION->head) return 1;
        POSITION = POSITION->NEXT;
    }
    return 0;
}


int DPLL(LIST* HEAD, int* RESULT,int maxtimes[])
{
    int i,k,b,c,value;
    LIST* POSITION = HEAD;
    LIST* SINGLE = single(POSITION);
    for(;SINGLE!=NULL;)
    {
        if(SINGLE->head->data>0)RESULT[SINGLE->head->data-1]=1;
        else RESULT[-(SINGLE->head->data)-1]=0;
        value=SINGLE->head->data;
        DELETE_(HEAD, value);
        if(HEAD->NEXT == NULL) return 1;
        else if(empty(HEAD))   return 0;
        POSITION = HEAD;
        SINGLE = single(POSITION);
    }
    value = choose(HEAD,INDEX,RESULT,maxtimes);
    if(DPLL(add(Copy(HEAD), value),RESULT,maxtimes))  return 1; 
    return DPLL(add(HEAD, -value),RESULT,maxtimes);
}

int dig_mark(int x,int y,int value){
    int i,k,b,c;
    line_mark[x][value]=0;
    row_mark[y][value]=0;
    unit_mark[x/3][y/3][value]=0;
    return 0;
}
int re_dig_mark(int x,int y,int value){
    int i,k,b,c;
    line_mark[x][value]=1;
    row_mark[y][value]=1;
    unit_mark[x/3][y/3][value]=1;
    return 0;
}

// int show(){
//     int i, j;
//     SetPos(0,16);
//     setColor(10,8);
//     printf("      ---------------------\n"); 
//   	for (i = 0; i < 9; i++)
//   	{
//           printf("      ");
// 		for (j = 0; j < 9; j++)
// 		{
//       		if (j % 3 == 0) printf("|");
//             if(j==8) {
//                 if (sudoku_dig[i][j]!=0)printf("%d|\n",sudoku_dig[i][j]);
//                 else printf("_|\n");
//                 continue;}
//       		if (sudoku_dig[i][j]!=0) printf("%d ",sudoku_dig[i][j]);
//       		else printf("_ ");
//     	}
//     	if ((i + 1) % 3 == 0) printf("      ---------------------\n"); 
//   	}
//     setColor(7,0);
//       return 0;
// }


int show(){
    int i, j;
    SetPos(0,15);
    setColor(2,7);
    printf("---------------------\n"); 
  	for (i = 0; i < 9; i++)
  	{
		for (j = 0; j < 9; j++)
		{
      		if (j % 3 == 0) printf("|");
            if(j==8) {
                if (sudoku_dig[i][j]!=0)printf("%d|\n",sudoku_dig[i][j]);
                else printf("_|\n");
                continue;}
      		if (sudoku_dig[i][j]!=0) printf("%d ",sudoku_dig[i][j]);
      		else {
                  setColor(4,7);
                  printf("_ ");
                  setColor(2,7);
              }
    	}
    	if ((i + 1) % 3 == 0) printf("---------------------\n"); 
  	}
    setColor(7,0);
    return 0;
}

int ass(int x,int y,int value,int index){
    int i,k,b,c;
    if(index==1){
        sudoku_dig[x][y]=value;
        return 0;
    }
    else sudoku_dig[x][y]=0;
    return 0;
}

void dfs(int x,int y) {
    if(SUM_SOLUTION>1)return;
    if(sudoku_dig[x][y]) {
        if(x!=8||y!=8) {
            dfs(x+(y+1)/9,(y+1)%9);
            return;
            }
        else {
            SUM_SOLUTION++;
            if(SUM_SOLUTION>1)return;
            //show();
            // printf("\n");
            return;
            }
    }
    for(int i=1;i<=9;i++) {
        if(SUM_SOLUTION>1)return;
        if(line_mark[x][i]||row_mark[y][i]||unit_mark[x/3][y/3][i]) continue;
        ass(x,y,i,1);
        if(x==8&&y==8) {
            SUM_SOLUTION++;
            //show();
            // printf("\n");
            ass(x,y,i,-1);
            //break;
            }
        else dfs(x+(y+1)/9,(y+1)%9);
        ass(x,y,i,-1);
    }
}

int singlesolution(){
    SUM_SOLUTION=0;
    dfs(0,0);
    // printf("%d\n",SUM_SOLUTION);
    // if(SUM_SOLUTION==1)printf("YES\n");
    // if(SUM_SOLUTION==0)show();
    if(SUM_SOLUTION==1)return 1;
    else return 0;
}


// void createStartinggrid(int num) {
//     int i,k,b,j,m,flag=0;
//     int c[num][2];
//     for(i=0;i<num;i++){
//         for(k=0;k<2;k++){
//             c[i][k]=0;
//         }
//     }
//     srand((unsigned)time(NULL));
//     for( i = 0; i < 9 ; i ++)
//         for( j = 0; j < 9 ; j++)
//             sudoku_dig[i][j] = sudoku_begin[i][j];

//     for( i = 0; i < num ; i++) {
//         j = rand()%9;
//         k = rand()%9;
//         flag = 0;
//         for(m = 0; m < i ; m++)
//             if( j == c[m][0] && k == c[m][1]){
//                 // i--;
//                 // continue;
//                 flag=1;
//             }
//             if(flag==1){
//                 i--;
//                 continue;
//             }
//             if(flag==0)
//             {
//                 b=sudoku_begin[j][k];
//                 dig_mark(j,k,b);
//                 sudoku_dig[j][k]=0;
//                 if(!singlesolution()){
//                     i--;
//                     sudoku_dig[j][k]=b;
//                     re_dig_mark(j,k,b);
//                     continue;
//                 }
//                 else{
//                     c[i][0] = j;
//                     c[i][1] = k;
//                 }
//             }
//     }
//     // show();
// }



void createStartinggrid(int num) {
    int i,k,b,j,m,flag=0;
    int c[10][10];
    for(i=0;i<10;i++){
        for(k=0;k<10;k++){
            c[i][k]=0;
        }
    }
    srand((unsigned)time(NULL));
    for( i = 0; i < 9 ; i ++)
        for( j = 0; j < 9 ; j++)
            sudoku_dig[i][j] = sudoku_begin[i][j];

    for( i = 0; i < num ; i++) {
        j = rand()%9;
        k = rand()%9;
            if(c[j][k]==1){
                i--;
                continue;
            }
            else if(num<40)
            {
                b=sudoku_begin[j][k];
                dig_mark(j,k,b);
                sudoku_dig[j][k]=0;
                c[j][k]=1;
                if(!singlesolution()){
                    i--;
                    sudoku_dig[j][k]=b;
                    re_dig_mark(j,k,b);
                    continue;
                }
                else{
                    c[j][k]=1;
                }
            }
            else {
                b=sudoku_begin[j][k];
                dig_mark(j,k,b);
                sudoku_dig[j][k]=0;
                c[j][k]=1;
            }
    }
    // show();
}

int Digit(int a[][9], int x, int y) {
    int i,k,b,c,j,flag;
    int check[10];
    for(i=0;i<10;i++){
        check[i]=1;
    }
    if (x < 9 && y < 9) {
        for(i = 0 ; i < x ; i++)
            check[a[i][y]] = 0;
        for(i = 0 ; i < y ; i++)
            check[a[x][i]] = 0;
        for(i = x/3*3 ; i <= x; i++) {
            if(i == x)
                for(j = y/3*3 ; j < y; j++)
                    check[a[i][j]] = 0;
            else
                for(j = y/3*3 ; j < y/3*3 + 3; j++)
                    check[a[i][j]] = 0;
        }
        flag=0;
        for(k = 1; k <= 9 && flag == 0 ; k++){
            // for(i=0;i<10;i++)printf("%d ",check[i]);
            // printf("\n");
            if(check[k]==1){
                flag = 1;
                a[x][y] = k;
                if(y == 9-1 && x != 9-1){
                    if(Digit(a,x+1,0) == 1) return 1;
                    else flag = 0;
                }
                else if(y != 9-1){
                    if(Digit(a,x,y+1) == 1) return 1;
                    else flag = 0;
                }
            }
        }
        if( flag == 0 ) {
            a[x][y] = 0;
            return 0;
        }
    }
    return 1;
}


// int Digit(int a[][9], int i, int j) {//递归�?充数�?元素
//     if (i < 9 && j < 9) {
//         int x,y,k;
//         int check[9+1]={1};//用于排除已经使用过的的数�?
//         for(x = 0 ; x < i ; x++)
//             check[a[x][j]] = 0;//列已使用的数字置为WRONG
//         for(x = 0 ; x < j ; x++)
//             check[a[i][x]] = 0;//行使用过的数字置为WRONG
//         for(x = i/3*3 ; x <= i; x++) {
//             if(x == i)
//                 for(y = j/3*3 ; y < j; y++)
//                     check[a[x][y]] = 0;
//             else
//                 for(y = j/3*3 ; y < j/3*3 + 3; y++)
//                     check[a[x][y]] = 0;
//         }

//         int flag = 0;
//         for(k = 1; k <= 9 && flag == 0 ; k++){//从check数组�?查找安全的数�?
//             if(check[k] == 1){
//                 flag = 1;
//                 a[i][j] = k;
//                 if(j == 9-1 && i != 9-1){
//                     if(Digit(a,i+1,0) == 1) return 1;
//                     else flag = 0;
//                 }
//                 else if(j != 9-1){
//                     if(Digit(a,i,j+1) == 1) return 1;
//                     else flag = 0;
//                 }
//             }
//         }
//         if( flag == 0 ) {
//             a[i][j] = 0;
//             return 0;
//         }
//     }
//     return 1;
// }

void randomFirstRow(int a[], int n) {//随机生成�?一�?
    int i,k,b,c,j;
    srand((unsigned)time(NULL));
    for( i = 0 ; i < n ; i++){
        a[i] = rand()%9 + 1;
        j = 0 ;
        while(j < i){
            if(a[i] == a[j]){
                a[i] = rand()%9 + 1;
                j = 0;
            }
            else j++;
        }
    }
}


void createSudoku(int a[][9]){
    randomFirstRow(a[0],9);
    Digit(a,1,0);
}


// void createStartinggrid(const int a[][9], int b[][9], int num) {//随机生成初盘
//     int i,k,b,c,j,m,flag=0;
//     int c[num][2];
//     srand((unsigned)time(NULL));
//     for( i = 0; i < 9 ; i ++)
//         for( j = 0; j < 9 ; j++)
//             b[i][j] = a[i][j];

//     for( i = 0; i < num ; i++) {
//         j = rand()%9;
//         k = rand()%9;
//         flag = 0;
//         for(m = 0; m < i ; m++)
//             if( j == c[m][0] && k == c[m][1]){
//                 i--;
//                 continue;
//             }
//             else if(singlesolution()){
//                 i--;
//                 continue;
//             }
//             else{
//             b[j][k] = 0;
//             c[i][0] = j;
//             c[i][1] = k;
//         }
//         else
//             i--;
//     }
// }

// 

void print(){//打印数独数组
    int i, j;
    SetPos(0,15);
    setColor(2,7);
    printf("---------------------\n"); 
  	for (i = 0; i < 9; i++)
  	{
		for (j = 0; j < 9; j++)
		{
      		if (j % 3 == 0) printf("|");
            if(j==8) {
                if (sudoku_begin[i][j]!=0)printf("%d|\n",sudoku_begin[i][j]);
                else printf("_|\n");
                continue;}
      		if (sudoku_begin[i][j]!=0) printf("%d ",sudoku_begin[i][j]);
      		else {
                  setColor(4,7);
                  printf("_ ");
                  setColor(2,7);
              }
    	}
    	if ((i + 1) % 3 == 0) printf("---------------------\n"); 
  	}
    setColor(7,0);
}

int SAT_FUNCTION(){
        system("cls");
            setColor(5,0);
            printf("--------------------Function <SAT>---------------------\n\n");
            setColor(7,0);
            if(CNF_TRANSLATER()==-1)return 0;
            // char c,tmp[10480],name[100],filename[100];
            // printf("                Input filename:\n");
            // scanf("%s",filename);
            // strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\");
            // strcat(name,filename);
            // strcat(name,".cnf");
            // fp=fopen(name, "r+");
            // int i,k,b;
            // while(c=getc(fp)){
            //     if(c=='c'){
            //         fgets(tmp,10470,fp);
            //     }
            //     else if(c=='p'){
            //         break;
            //     }
            // }
            // for(;;){
            //     c=getc(fp);
            //     if(c=='f')break;
            // }
            // getc(fp);
            // fscanf(fp,"%d %d",&m,&n);

            // int times[m+1],maxtimes[m+1],pos[m+1],neg[m+1];
            // memset(times,0,sizeof(times));
            // memset(maxtimes,0,sizeof(maxtimes));
            // memset(pos,0,sizeof(pos));
            // memset(neg,0,sizeof(neg));

            // Start1=clock();
            // node *p;
            // LIST *HEAD,*POSITION;
            // HEAD=(LIST*)malloc(sizeof(LIST));
            // HEAD->NEXT=NULL;
            // POSITION=HEAD;

            // POSITION->NEXT=NULL;
            // POSITION->head=NULL;

            // for(i=1;i<n;i++){
            //     POSITION->NEXT=(LIST*)malloc(sizeof(LIST));
            //     POSITION=POSITION->NEXT;
            //     POSITION->NEXT=NULL;
            //     POSITION->head=(node*)malloc(sizeof(node));
            //     POSITION->head->next=NULL;
            //     p=POSITION->head;
            //     fscanf(fp,"%d ",&b);

            //     times[abs(b)]++;
            //     // if(b>0)pos[b]++;
            //     // else neg[-b]++;

            //     p->data=b;
            //     p->next=NULL;
            //     for(k=1;;k++){
            //         fscanf(fp,"%d ",&b);
            //         if(b==0)break;

            //         times[abs(b)]++;
            //         // if(b>0)pos[b]++;
            //         // else neg[-b]++;

            //         p->next=(node*)malloc(sizeof(node));
            //         p=p->next;
            //         p->data=b;
            //         p->next=NULL;
            //     }
            //     POSITION->length=k;
            // }     
            // fclose(fp);            
            // // for(POSITION=HEAD;POSITION!=NULL;POSITION=POSITION->NEXT){
            // //     for(p=POSITION->head;p!=NULL;p=p->next){
            // //         printf("%d ",p->data);
            // //     }
            // //     printf("haha\n");
            // // }  

            // // for(i=1;i<=m;i++){
            // //     printf("%d %d %d\n",times[i],pos[i],neg[i]);
            // // }
            // // printf("\n");
            // End1=clock();
            // system("cls");
            // printf("Read-in_time: %lf ms\n\n",(double)(End1-Start1)/CLOCKS_PER_SEC*1000.0);
            int sh;
            printf("        Input 1 to show the data of this file\n        Input 0 to skip\n");
            scanf("%d",&sh);
            LIST *POSITION;
            node *p;
            int b;
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
            system("Pause");
            system("cls");
            printf("NOW LET'S SOLVE THIS SAT PROBLEM!\n\n");
            // printf("-------------------INDEX1:Normal  INDEX2:Optimized  INDEX3:RANDOM--------------------\n");
            // printf("                                    Input INDEX:");
            printf("_________________________________________________\n");
            printf("|     Please choose your selection strategy      |\n");
            printf("|------------------------------------------------|\n");
            printf("|                  INDEX1:Normal:                |\n");
            printf("|                  INDEX2:Optimized:             |\n");
            printf("|                  INDEX3:RANDOM:                |\n");
            printf("|                                                |\n");
            printf("|                  Please input:                 |\n");
            printf("|________________________________________________|\n");
            scanf("%d",&INDEX);
            int i;
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
            if(b)for(i=0;i<m;i++){
                if(RESULT[i]!=0){
                  printf("%d ",i+1);
               }
              else {
                  printf("-%d ",i+1);
                }
               if((i+1)%5==0)printf("\n");
                  }
            else printf("error");
                printf("\n");
                End=clock();
                printf("Runtime: %lf ms\n",(double)(End-Start)/CLOCKS_PER_SEC*1000.0);
                printf("The solution has been saved in the file ""for.res""\n");
                // scanf("%s",filename);
                strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\for.res");
                // strcat(name,filename);
                // strcat(name,".res");
                fp=fopen(name, "w");
                if(b) {
                    fprintf(fp,"s 1\nv ");
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
                fprintf(fp,"\nt %6d ",(End-Start)/CLOCKS_PER_SEC*1000);
                fclose(fp);
                system("Pause");
        return 0;
}
