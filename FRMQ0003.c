/* Projeto FORMARQ */
/*
           ABRIR ARQUIVO
*/
#include<stdio.h>
#include<conio.h>

void invert(FILE* Arquivo)      // Convers�o INVERT
{
     char c;
     do{
          c = getc(Arquivo);
          printf("%c", c!='\n' ? 0x100-c : c);     // Inverte o char
     }while(c!=EOF);
     printf("\nEOF");
     return;
}

void cript(FILE* Arquivo, char Chave[])   // Convers�o CRIPT
{
     char c;
     do{
          c = getc(Arquivo);
          printf("%c", c);
     }while(c!=EOF);
     printf("\nEOF");
     return;
}

void u2d(FILE* Arquivo)                // Convers�o UNIX to DOS
{
     char c;
     do{
          c = getc(Arquivo);
          printf("%c", c==0x0A ? 0x0D : c);
     }while(c!=EOF);
     printf("\nEOF");
     return;
}

void d2u(FILE* Arquivo)               // Convers�o DOS to UNIX
{
     char c;
     do{
          c = getc(Arquivo);
          printf("%c", c);
     }while(c!=EOF);
     printf("\nEOF");
     return;
}     

int main()
{
    char Nome, Tipo, Chave[8];               //chave que vai dizer qual conversao sera usada / se C, Chav � a Senha
    FILE *Arquivo;                           // Declara o ARQUIVO
    printf("\n\tFORMARQ <dados.DAT> [I][C][D][U]\n\nI: ConversAo Invert.\nC: ConversAo Cript. [escrever chave]\nD: ConversAo UNIX to DOS.\nU: ConversAo DOS to UNIX.\n");
    Arquivo = fopen("DADOS.dat", "r");       // Abre ARQUIVO
    scanf("%c", &Tipo);                      // Recebe a convers�o
    if(Tipo=='c') scanf(" %s", &Chave);      // Recebe a Chave, se a convers�o for Cript
    switch(Tipo){                            // Define, partindo da letra, qual convers�o ser� usada
                 case'i': invert(Arquivo); break;
                 case'c': cript(Arquivo, Chave[8]); break;
                 case'd': u2d(Arquivo); break;
                 case'u': d2u(Arquivo); break;
                 default: printf("Nada acontece feijoada.");
    }
    fclose(Arquivo);
    getch();
    return 0;
}
