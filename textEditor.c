#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char data;
    struct element *next;
}Element;

typedef struct{
    Element *start;
    int size;
}Stack;

void init(Stack *s){
    s -> start = NULL;
    s -> size = 0;
}

void push(Stack *s, Element e){
    Element *new = calloc(1,sizeof(Element));
    new -> data = e.data;
    new -> next = s -> start;
    s -> start = new;
    s -> size++;
}

void empty(Stack *s) {
    Element *aux = s -> start;
    while(aux != NULL){
        Element *temp = aux;
        aux = aux -> next;
        free(temp);
    }
    s -> start = NULL;
    s -> size = 0;
}

Element pop(Stack *s){
    Element e;
    if(s -> start == NULL){
        e.data = NULL;//error
        return e;
    }
    Element *aux = s -> start;
    e.data = aux -> data;
    s -> start = aux -> next;
    free(aux);
    s -> size--;
    return e;
}

int main(){

    //welcome message
    printf("Bienvenido a JKM Text Editor");

    //variables
    int opc = -1;
    Stack text;
    Stack undo;
    Stack deleted;
    init(&deleted);
    init(&undo);
    init(&text);

    //Menu
    do{
        printf("\n\n");
        puts("Elija una opción");
        puts("1. Escribir");
        puts("2. Eliminar N letras");
        puts("3. Leer");
        puts("4. Deshacer");
        puts("5. Salir");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &opc);

        //switch
        if(opc == 1){
            //add the text to the text stack
            char tempText[100];
            printf("\nIngrese texto: ");
            fflush(stdin);
            scanf("%s", tempText);
            for(int i = 0; i < strlen(tempText); i++){
                Element e;
                e.data = tempText[i];
                push(&text, e);
            }
            //add the instruction to undo
            Element e;
            e.data = '1';
            push(&undo, e);
        }else if(opc == 2){
            //delete the text from the text stack
            int n;
            printf("\nIngrese N: ");
            fflush(stdin);
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                Element e = pop(&text);
                push(&deleted, e);
                //add the instruction to undo, each letter is a instruction
                Element e;
                e.data = '2';
                push(&undo, e);
            }
        }else if(opc == 3){
            //read the text
            Element e;
            Stack tempText;
            init(&tempText);
            do{
                e = pop(&text);
                if(e.data != NULL){
                    push(&tempText, e);
                }
            }while(e.data != NULL);

            //print the text
            printf("\nTexto: ");
            do{
                e = pop(&tempText);
                if(e.data != NULL){
                    printf("%c", e.data);
                    push(&text, e); //return the text to the text stack
                }
            }while(e.data != NULL);
        }else if(opc == 4){
            //undo the last instruction
            Element e = pop(&undo);
            if(e.data == '1'){
                //undo the last add
                Element e = pop(&undo);
            }else if(e.data == '2'){
                //undo the last delete
                Element e = pop(&deleted);
                push(&text, e);
            }
            //delete the last instruction
            pop(&undo);
        }else{
            printf("\nAdios\n");
            opc =  -1;
        }
    }while(opc>0);

    return 0;
}