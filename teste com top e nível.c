#include<stdio.h>
#include<locale.h>
#include<time.h>
#define TAM 3  //define o tamanho maximo

struct pilha
{
    int dados[TAM];
    int topo; // o topo é marcado pelo número do indice
};
typedef struct pilha Pilha;

void push(Pilha *p, int x)
{
    if(p->topo==TAM-1)
    {
        //printf("Pilha está cheia - Overflow\n");
    }
    else
    {
        p->topo++;
        p->dados[p->topo]=x;
    }
}

int pop(Pilha *p)
{
    if(p->topo==-1)
    {
        //printf("Pilha já está vazia - under flow");
        return -1;
    }
    else
    {
        int res=p->dados[p->topo];
        p->topo--;
        return res;
    }

}

int isFull (Pilha p)
{
    if(p.topo == TAM-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty (Pilha p)
{
    if(p.topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int top(Pilha p)
{
    if(p.topo==-1)
    {
        return -1;
    }
    else
    {
        return p.dados[p.topo];
    }

}

void imprimir(Pilha p)
{
    printf("\n");
    for(int i=p.topo; i>=0; i--)
    {
        printf("%i\n",p.dados[i]);
    }
    printf("\n");
}

void imprimirPilha(Pilha p1, Pilha p2, Pilha p3)
{
    printf("\n\t  Torre-1      \t  Torre-2      \t  Torre-3  \n\n");

    int alturaPilha = p1.topo;
    if (p2.topo>alturaPilha)
    {
        alturaPilha=p2.topo;
    }
    if (p3.topo>alturaPilha)
    {
        alturaPilha=p3.topo;
    }

    for (int i = alturaPilha; i >= 0; i--)
    {
        if(i<=p1.topo)
        {
            printf ("\t     %i     ",p1.dados[i]);
        }
        else
        {
            printf ("\t     |     ");
        }
        if(i<=p2.topo)
        {
            printf ("\t     %i     ",p2.dados[i]);
        }
        else
        {
            printf ("\t     |     ");
        }
        if(i<=p3.topo)
        {
            printf ("\t     %i     ",p3.dados[i]);
        }
        else
        {
            printf ("\t     |     ");
        }
        printf("\n");
    }
}




int main()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao;


    do
    {
        Pilha p1, p2, p3;
        p1.topo=-1;
        p2.topo=-1;
        p3.topo=-1;
        push (&p1,3);
        push (&p1,2);
        push (&p1,1);
        int cont=0;

        int x,y;
        printf ("\n\tBem vindo ao jogo Torre de Hanói!\n\n\n");
        printf ("\tO desafio desse jogo é passar todos os números para a Torre-3\n");
        printf ("\tVocê deve mover um número por vez, sem colocar um número maior encima de um menor.\n\n\n");

        imprimirPilha(p1,p2,p3);

        while (p3.topo != TAM-1)
        {
            printf ("\n\n\tQual será a pilha de origem? 1, 2 ou 3?  ");
            scanf ("%i",&x);
            printf ("\n\tQual será a pilha de destino? 1, 2 ou 3?  ");
            scanf ("%i",&y);

            if (x==1 && y==2)
            {
                if (top(p2)==-1 || top (p1) < top(p2))
                {
                    push (&p2,pop(&p1));
                    system ("cls");
                }
                else if (top(p1)>top(p2))
                {
                    system ("cls");
                    printf ("\nMovimento não permitido!\n");
                }
            }


            if (x==1 && y==3)
            {
                if (top(p3)==-1 || top(p1) < top(p3))
                {
                    push (&p3,pop(&p1));
                    system ("cls");
                }
                else if (p1.topo>p3.topo)
                {
                    system ("cls");
                    printf ("\nMovimento não permitido!\n");
                }
            }

            if (x==2 && y==1)
            {
                if (p1.topo==-1 || p2.dados[p2.topo] < p1.dados[p1.topo] )
                {
                    push (&p1,pop(&p2));
                    system ("cls");
                }
                else if (p2.topo>p1.topo)
                {
                    system ("cls");
                    printf ("\nMovimento não permitido!\n");
                }
            }

            if (x==2 && y==3)
            {
                if (p3.topo==-1 || p2.dados[p2.topo] < p3.dados[p3.topo])
                {
                    push (&p3,pop(&p2));
                    system ("cls");
                }
                else if (p2.topo>p3.topo)
                {
                    system ("cls");
                    printf ("\nMovimento não permitido!\n");
                }
            }

            if (x==3 && y==1)
            {
                if (p1.topo==-1 || p3.dados[p3.topo] < p1.dados[p1.topo])
                {
                    push (&p1,pop(&p3));
                    system ("cls");
                }
                else if (p3.topo>p1.topo)
                {
                    system ("cls");
                    printf ("\nMovimento não permitido!\n");
                }
            }

            if (x==3 && y==2)
            {
                if (p2.topo==-1 || p3.dados[p3.topo] < p2.dados[p2.topo])
                {
                    push (&p2,pop(&p3));
                    system ("cls");
                }
                else if (p3.topo>p2.topo)
                {
                    system ("cls");
                    printf ("\nMovimento não permitido!\n");
                }
            }
            cont ++;
            printf ("\n\t %i jogadas!\n",cont);
            imprimirPilha(p1,p2,p3);

        }

        printf ("\nVocê conseguiu com %i jogadas\n",cont);

        printf ("\nParabéns!");
        printf ("\n\nDeseja continuar? sim(1)  não(2)");
        scanf ("%i",&opcao);
        system ("cls");
    }while (opcao==1);

}


