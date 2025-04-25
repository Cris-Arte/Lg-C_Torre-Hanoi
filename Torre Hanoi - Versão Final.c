#include "stdio.h"
#include "locale.h"
#include "time.h"
#define TAM 7

struct pilha
{
    int dados[TAM];
    int topo;
};
typedef struct pilha Pilha;

void push(Pilha *p, int x)
{
    if(p->topo==TAM-1)
    {
        //printf("Pilha est� cheia - Overflow\n");
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
        //printf("Pilha j� est� vazia - under flow");
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

    for (int i = 0; i < TAM; i++)
    {
        int indice = TAM - 1 - i;

        if(indice <= p1.topo)
        {
            printf ("\t     %i     ",p1.dados[indice]);
        }
        else
        {
            printf ("\t     |     ");
        }
        if(indice <= p2.topo)
        {
            printf ("\t     %i     ",p2.dados[indice]);
        }
        else
        {
            printf ("\t     |     ");
        }
        if(indice <= p3.topo)
        {
            printf ("\t     %i     ",p3.dados[indice]);
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
        int nivel, nivelTam;
        printf ("\n\tBem vindo ao jogo Torre de Han�i!\n\n\n");
        printf ("\tO desafio desse jogo � passar todos os n�meros para a Torre-3\n");
        printf ("\tVoc� deve mover um n�mero por vez, sem colocar um n�mero maior encima de um menor.\n\n\n");
        printf("\n\tEscolha o n�vel de dificuldade:\n\n");
        printf("\t1 - F�cil (3 discos)\n");
        printf("\t2 - M�dio (5 discos)\n");
        printf("\t3 - Dif�cil (7 discos)\n");
        printf("\n\tOp��o: ");
        scanf("%d", &nivel);
        system ("cls");

        if(nivel == 1)
        {
            nivelTam = 3;
        }
        else if(nivel == 2)
        {
            nivelTam = 5;
        }
        else if(nivel == 3)
        {
            nivelTam = 7;
        }
        else
        {
            printf("Op��o inv�lida! Usando n�vel F�cil por padr�o.\n");
            nivelTam = 3;
        }

        Pilha p1, p2, p3;
        p1.topo=-1;
        p2.topo=-1;
        p3.topo=-1;

        for(int i = nivelTam; i >= 1; i--)
        {
            push (&p1, i);
        }

        int cont=0;
        int x,y;

        imprimirPilha(p1,p2,p3);

        while (p3.topo != nivelTam-1)
        {
            printf ("\n\n\tQual ser� a pilha de origem? 1, 2 ou 3?  ");
            scanf ("%i",&x);
            printf ("\n\tQual ser� a pilha de destino? 1, 2 ou 3?  ");
            scanf ("%i",&y);
            if((x>3||x<1)||(y>3||y<1)||(x==y))
            {
                system ("cls");
                printf ("\n\tN�mero inv�lido! Digite novamente!\n\n");

            }
            if (x==1 && y==2)
            {
                if ((top(p1)!=-1) && top(p2)==-1 || top (p1) < top(p2))
                {
                    push (&p2,pop(&p1));
                    cont ++;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    printf ("\n\tMovimento n�o permitido! Digite novamente!\n\n");
                }
            }
            if (x==1 && y==3)
            {
                if ((top(p1)!=-1) && (top(p3)==-1 || top(p1) < top(p3)))
                {
                    push (&p3,pop(&p1));
                    cont ++;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    printf ("\n\tMovimento n�o permitido! Digite novamente!\n\n");
                }
            }
            if (x==2 && y==1)
            {
                if ((top(p2)!=-1)&& (p1.topo==-1 || top(p2) < top(p1)))
                {
                    push (&p1,pop(&p2));
                    cont ++;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    printf ("\n\tMovimento n�o permitido! Digite novamente!\n\n");
                }
            }
            if (x==2 && y==3)
            {
                if ((top(p2)!=-1)&& (p3.topo==-1 || top(p2) < top(p3)))
                {
                    push (&p3,pop(&p2));
                    cont ++;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    printf ("\n\tMovimento n�o permitido! Digite novamente!\n\n");
                }
            }
            if (x==3 && y==1)
            {
                if ((top(p3)!=-1)&&(p1.topo==-1 || top(p3) < top(p1)))
                {
                    push (&p1,pop(&p3));
                    cont ++;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    printf ("\n\tMovimento n�o permitido! Digite novamente!\n\n");
                }
            }
            if (x==3 && y==2)
            {
                if ((top(p3)!=-1)&&(p2.topo==-1 || top(p3) < top(p2)))
                {
                    push (&p2,pop(&p3));
                    cont ++;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    printf ("\n\tMovimento n�o permitido! Digite novamente!\n\n");
                }
            }

            printf ("\n\tMovimentos: %i\n",cont);
            imprimirPilha(p1,p2,p3);

        }

        if((nivel==1 && cont==7)||(nivel==2 && cont==31)||(nivel==3 && cont==127))
        {
            printf ("\n\n\tUauuu!!!! Voc� conseguiu com o m�nimo de jogadas poss�vel!!! Parab�ns!\n");
            printf ("\n\n\tDeseja continuar? sim(1)  n�o(2)");
            scanf ("%i",&opcao);
            system ("cls");
        }
        else
        {

            printf ("\n\tVoc� conseguiu com %i movimentos.\n",cont);
            printf ("\n\tParab�ns!!! \n\tSe voc� gosta de desafios, pode tentar com n�mero de jogadas menor!");
            printf ("\n\n\tDeseja continuar? sim(1)  n�o(2) ");
            scanf ("%i",&opcao);
            system ("cls");
        }
    }
    while (opcao==1);

    if (opcao==2)
    {
        printf ("\n\tObrigado por jogar!\nVolte logo!\n\n\n");
    }
    getche();
}
