#include "hellodpll.h"

int ToCnf(int a[][9],int holes) {
    FILE *fp;
    char c,tmp[10480],name[100];
    strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\sudoku.cnf");
    fp=fopen(name, "w+");
    int i,k,b,m,n;
    fprintf(fp,"p cnf 999 %d\n",8910-holes);
    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y)
            if(a[x][y] != 0)
                fprintf(fp,"%d 0\n",(x+1)*100 + (y+1)*10 + a[x][y]);
    }
    //entry
    for (int x = 1; x <= 9; ++x) {
        for (int y = 1; y <= 9; ++y) {
            for (int z = 1; z <= 9; ++z)
                fprintf(fp,"%d ",x * 100 + y * 10 + z);
                fprintf(fp,"%d \n",0);
        }
    }
    //row
    for (int y = 1; y <= 9; ++y) {
        for (int z = 1; z <= 9; ++z)
            for (int x = 1; x <= 8; ++x)
                for (int i = x+1; i <= 9; ++i)
                    fprintf(fp,"%d %d 0\n",0 - (x*100 + y*10 + z),0 - (i*100 + y*10 + z));
    }
    //column
    for (int x = 1; x <= 9; ++x) {
        for (int z = 1; z <=9 ; ++z)
            for (int y = 1; y <= 8; ++y)
                for (int i = y+1; i <= 9; ++i)
                    fprintf(fp,"%d %d 0\n",0-(x*100 + y*10 + z),0-(x*100 + i*10 + z));
    }
    //3*3 sub-grids
    for (int z = 1; z <= 9 ; ++z) {
        for (int i = 0; i <=2 ; ++i)
            for (int j = 0; j <=2 ; ++j)
                for (int x = 1; x <= 3 ; ++x)
                    for (int y = 1; y <= 3; ++y)
                        for (int k = y+1; k <= 3; ++k)
                            fprintf(fp,"%d %d 0\n",0 - ((3*i+x)*100 + (3*j+y)*10 + z),0-((3*i+x)*100 + (3*j+k)*10 + z));
    }
    for (int z = 1; z <= 9; z++) {
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                for (int x = 1; x <= 3; x++)
                    for (int y = 1; y <= 3; y++)
                        for (int k = x + 1; k <= 3; k++)
                            for (int l = 1; l <= 3; l++)
                                fprintf(fp,"%d %d 0\n", 0 - ((3*i+x)*100 + (3*j+y)*10 + z),0 - ((3*i+k)*100 + (3*j+l)*10 + z));
    }
    fclose(fp);
    return 0;
}


int CNF_TRANSLATER_SUDOKU(){
            char c,tmp[10480],name[100],filename[100];
            strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\sudoku.cnf");
            fp=fopen(name, "r+");
            int i,k,b;
            while(c=getc(fp)){
                if(c=='c'){
                    fgets(tmp,10470,fp);
                }
                else if(c=='p'){
                    break;
                }
                else {
                    printf("ERROR FORMAT!\n");
                    return 0;
                }
            }
            for(;;){
                c=getc(fp);
                if(c=='f')break;
            }
            getc(fp);
            fscanf(fp,"%d %d",&m,&n);

            // int times[m+1],maxtimes[m+1],pos[m+1],neg[m+1];
            memset(times,0,sizeof(times));
            memset(maxtimes,0,sizeof(maxtimes));
            // memset(pos,0,sizeof(pos));
            // memset(neg,0,sizeof(neg));

            Start1=clock();
            node *p;
            LIST *POSITION;
            HEAD=(LIST*)malloc(sizeof(LIST));
            HEAD->NEXT=NULL;
            POSITION=HEAD;

            POSITION->NEXT=NULL;
            POSITION->head=NULL;

            for(i=1;i<n;i++){
                POSITION->NEXT=(LIST*)malloc(sizeof(LIST));
                POSITION=POSITION->NEXT;
                POSITION->NEXT=NULL;
                POSITION->head=(node*)malloc(sizeof(node));
                POSITION->head->next=NULL;
                p=POSITION->head;
                fscanf(fp,"%d ",&b);

                times[abs(b)]++;
                // if(b>0)pos[b]++;
                // else neg[-b]++;

                p->data=b;
                p->next=NULL;
                for(k=1;;k++){
                    fscanf(fp,"%d ",&b);
                    if(b==0)break;

                    times[abs(b)]++;
                    // if(b>0)pos[b]++;
                    // else neg[-b]++;

                    p->next=(node*)malloc(sizeof(node));
                    p=p->next;
                    p->data=b;
                    p->next=NULL;
                }
                POSITION->length=k;
            }     
            fclose(fp);            
            // for(POSITION=HEAD;POSITION!=NULL;POSITION=POSITION->NEXT){
            //     for(p=POSITION->head;p!=NULL;p=p->next){
            //         printf("%d ",p->data);
            //     }
            //     printf("haha\n");
            // }  

            // for(i=1;i<=m;i++){
            //     printf("%d %d %d\n",times[i],pos[i],neg[i]);
            // }
            // printf("\n");
            End1=clock();
            system("cls");
            printf("Read-in_time of sudoku: %lf ms\n\n",(double)(End1-Start1)/CLOCKS_PER_SEC*1000.0);
            return 0;
}


int CNF_TRANSLATER(){
            char c,tmp[10480],name[100],filename[100];
            printf("_________________________________________________\n");
            printf("|        Input filename you want to read_in      |\n");
            printf("|------------------------------------------------|\n");
            printf("|                  Please input:                 |\n");
            printf("|________________________________________________|\n");
            scanf("%s",filename);
            strcpy(name,"C:\\Users\\13226\\Desktop\\SAT\\");
            strcat(name,filename);
            strcat(name,".cnf");
            fp=fopen(name, "r+");
            int i,k,b;
            // while(c=getc(fp)){
            //     if(c=='c'){
            //         fgets(tmp,10470,fp);
            //     }
            //     else if(c=='p'){
            //         break;
            //     }
            // }
            while(c=getc(fp)){
                if(c=='c'){
                    fgets(tmp,10470,fp);
                }
                else if(c=='p'){
                    break;
                }
                else {
                    printf("ERROR FORMAT!\n");
                    system("Pause");
                    return -1;
                }
            }
            for(;;){
                c=getc(fp);
                if(c=='f')break;
            }
            getc(fp);
            fscanf(fp,"%d %d",&m,&n);

            // int times[m+1],maxtimes[m+1],pos[m+1],neg[m+1];
            memset(times,0,sizeof(times));
            memset(maxtimes,0,sizeof(maxtimes));
            // memset(pos,0,sizeof(pos));
            // memset(neg,0,sizeof(neg));

            Start1=clock();
            node *p;
            LIST *POSITION;
            HEAD=(LIST*)malloc(sizeof(LIST));
            HEAD->NEXT=NULL;
            POSITION=HEAD;

            POSITION->NEXT=NULL;
            POSITION->head=NULL;

            for(i=1;i<n;i++){
                POSITION->NEXT=(LIST*)malloc(sizeof(LIST));
                POSITION=POSITION->NEXT;
                POSITION->NEXT=NULL;
                POSITION->head=(node*)malloc(sizeof(node));
                POSITION->head->next=NULL;
                p=POSITION->head;
                fscanf(fp,"%d ",&b);

                times[abs(b)]++;
                // if(b>0)pos[b]++;
                // else neg[-b]++;

                p->data=b;
                p->next=NULL;
                for(k=1;;k++){
                    fscanf(fp,"%d ",&b);
                    if(b==0)break;

                    times[abs(b)]++;
                    // if(b>0)pos[b]++;
                    // else neg[-b]++;

                    p->next=(node*)malloc(sizeof(node));
                    p=p->next;
                    p->data=b;
                    p->next=NULL;
                }
                POSITION->length=k;
            }     
            fclose(fp);            
            // for(POSITION=HEAD;POSITION!=NULL;POSITION=POSITION->NEXT){
            //     for(p=POSITION->head;p!=NULL;p=p->next){
            //         printf("%d ",p->data);
            //     }
            //     printf("haha\n");
            // }  

            // for(i=1;i<=m;i++){
            //     printf("%d %d %d\n",times[i],pos[i],neg[i]);
            // }
            // printf("\n");
            End1=clock();
            system("cls");
            printf("Read-in_time: %lf ms\n\n",(double)(End1-Start1)/CLOCKS_PER_SEC*1000.0);
            return 0;
}
