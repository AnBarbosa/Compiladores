#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct informacoes {
    char token[255]; 
    char lexema[255];
    int lexema_size;
    int linha;
    int coluna; 
    } informacoes;

void imprimeToken(informacoes token);
void setTokenValue(informacoes* info, char* newValue);
void setLexemaValue(informacoes* info, char* newLexema);
void setLinhaValue(informacoes* info, int newLineNumber);
void setColunaValue(informacoes* info, int colunaValue);
void quebrarLinha(informacoes* info);
void appendToLexema(informacoes *token, char aAnexar);
void incrementaColuna(informacoes* info);


int conta_vetor (char vet[] );
void q0 (char ch, informacoes *token);
void q1 (char ch, informacoes *token);
void q2 (char ch, informacoes *token);
void q3 (char ch, informacoes *token);
void q4 (char ch, informacoes *token);
void q5 (char ch, informacoes *token);
void q6 (char ch, informacoes *token);
void q7 (char ch, informacoes *token);
void q8 (char ch, informacoes *token);
void q9 (char ch, informacoes *token); // ESTADO_INICIAL
void q10 (char analisado, informacoes *token); // FINAL OUTROS
void q11 (char ch, informacoes *token); // Final OPERADOR RELACIONAL
void q12 (char ch, informacoes *token); // Final OPERADOR
void q13 (char ch, informacoes *token);
void q14 (char ch, informacoes *token); // Final INTEIRO
void q15 (char ch, informacoes *token); // Final PONTO FLUTUANTE
void q16 (char ch, informacoes *token); // Final OPERADOR
void q17 (char ch, informacoes *token); // Final IDENTIFICADOR
void q18 (char ch, informacoes *token); // Final PONTO FLUTUANTE

#typedef ESTADO_FINAL 19;
#typedef ESTADO_ERRO 20;
// Funcoes 
typedef void (* funcaoEstado)(char ch, informacoes *token);
funcaoEstado estados[] = { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, estadoFinal, estadoErro };
int estadoAtual;
void mudaEstado(int novoEstado);
void processaEspacoEmEstadoFinal(char espaco, char token, informacoes* info);
void consomeEspacos(char espaco, informacoes* token);
void analiseLexica(FILE *fp);    
    


int main(int argc, char **argv) {
    
    int ESTADO_INICIAL = 9;
    estadoAtual = ESTADO_INICIAL;
    printf(" Iniciando operacao \n");
    char *fileDir;
    if(argc > 1)    { // Foi informado um caminho.
        fileDir = argv[1];
    }

            // não foi informado um arquivo,
    else{   // provavelmente estamos testando a aplicação
        fileDir = "../Testes/teste1.jl";
    }
    
    FILE *file_pointer = fopen(fileDir, "rt");

    if(file_pointer == NULL){
        printf("Erro enquanto tentava ler o arquivo %s\n", fileDir);
        exit(1);
    }
    else{
        
        printf("Pronto para iniciar a análise lexica de %s", fileDir);
        analiseLexica(file_pointer);
    }
    
    return 0;
  
  

  return 0;
}


void analiseLexica(FILE *fp) { 
    
    if(fp == NULL){
        printf("Erro enquanto tentava ler o arquivo %s\n", fp);
        exit(1);
    }
    
    char ch;
    informacoes var;
    int numeroDeTokens = 0;
    printf("Iniciando analise lexica\n");
    
    var.linha = 1;  // linhas são numeradas de 1 em diante.
    var.coluna = 1; // colunas são numeradas de 1 em diante.
    setTokenValue(&var, "NOVO_TOKEN"); // token no estado inicial.
    printf("Iniciando while\n");
    while((ch = fgetc(fp)) != EOF)
    {
        // Executamos a função do Estado atual.
        // Exemplo: executamos q0(ch, var), ou q1(ch, var)
        // a função é definida pela variavel global estadoAtual;
        printf("Chamado funcao de estados para o estado numero %d\n", estadoAtual);
        
        estados[estadoAtual](ch, &var);
        
    }
    printf("Linhas %d e Colunas %d\n" ,var.linha, var.coluna); 
    /**/
}



void q0 (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q1 (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q2 (char analisado,  informacoes *token) {
     printf("Iniciando estado 2\n");
    estadoAtual = 10;
}

void q3 (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q4  (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q5  (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q6  (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q7 (char analisado,  informacoes *token) {
    // TODO: Implementar
}

void q8 (char analisado,  informacoes *token) {
    // TODO: Implementar
}


void q9 (char analisado,  informacoes *token) {
    printf("Iniciando estado 9\n");
    
    if(isspace(analisado))
    {
        estadoAtual = 9;
        consomeEspacos(analisado, token);
        return;
    }
    
    if(isalnum(analisado))
    {
        if(isalpha(analisado)         {
            estadoAtual = 17;
        }
        if(isnum(analisado) {
            estadoAtual = 14;
    }
    // TODO: Implementar
}

void q10 (char ignorado, informacoes *token) {
    // TODO: Implementar
}


void q11 (char analisado,  informacoes *token) {
    // TODO: Implementar
}


void q12 (char analisado,  informacoes *token) {
    // TODO: Implementar
}


void q13 (char analisado,  informacoes *token) {
    // TODO: Implementar
}


void q14 (char analisado,  informacoes *token) {
    if(isspace(analisado)
    {
        setTokenValue("INTEIRO");
        mudaEstado(9);
    } else if(isnum(analisado) {
        mudaEstado(14);
    } else if(analisado=='.') {
        mudaEstado(15);   
    } else {
        mudaEstado(ESTADO_ERRO);
    }
    appendToLexema(analisado, token);
}


void q15 (char analisado,  informacoes *token) {
    // TODO: Implementar
}


void q16 (char analisado,  informacoes *token) {
    // TODO: Implementar
}


void q17 (char analisado,  informacoes *token) {
    if(isspace(analisado))
    {
        setTokenValue("IDENTIFICADOR");
        mudaEstado(ESTADO_FINAL);
        return;
    }
    if(isalnum(analisado) || analisado='_' || ) {
        mudaEstado(17);
        appendToLexema(analisado);
    } else {
        mudaEstado(ESTADO_ERRO);
    }
    
    
}


void q18 (char analisado,  informacoes *token) {
    // TODO: Implementar
}
// Auxiliares

void estadoFinal (char ignorado, informacoes *token)
{
    printf("Iniciando estado final.");
    imprimeToken(*token);    
}

void estadoErro (char ignorado, informacoes *token)
{
    printf("Iniciando estado final.");
    imprimeToken(*token);    
}

int  append(char*s, size_t size, char c) {
     if(strlen(s) + 1 >= size) {
         printf ("Erro no tamanho do lexema.");
          return 1;
     }
     int len = strlen(s);
     s[len] = c;
     s[len+1] = '\0';
     return 0;
}

void appendToLexema(informacoes *token, char aAnexar)
{
    // Criar uma maneira de "adicionar" o caractere ao lexema.
    // Essa não funciona direito.
   // printf("Appending to lekema: %c" , aAnexar);
    size_t currentLexemaSize = token->lexema_size;
    token->lexema_size++;
    append(token->lexema, currentLexemaSize, aAnexar);
}


void imprimeToken(informacoes token){
    printf("%s @ %s @ %d @ %d\n", token.token, token.lexema,
                             token.linha, token.coluna);
}

void setTokenValue(informacoes* info, char* newValue)
{
    strcpy(info->token, newValue);
}

void setLexemaValue(informacoes* info, char* newLexema)
{
    strcpy(info->lexema, newLexema);
    info->lexema_size = strlen(info->lexema);
}

void setLinhaValue(informacoes* info, int newLineNumber)
{
    info->linha = newLineNumber;
}

void setColunaValue(informacoes* info, int colunaValue)
{
    info->coluna = colunaValue;
}

void quebrarLinha(informacoes* info)
{ 
    info->linha = info->linha + 1;
    info->coluna = 0;
}

void incrementaColuna(informacoes* info)
{
    info->coluna = info->coluna + 1;
}




void mudaEstado(int novoEstado)
{
    estadoAtual = novoEstado;
}


void consomeEspacos(char espaco, informacoes* token)
{
    if(ch == '\n')
    {
        token->linha++;
        token->coluna = 0;
    } else {
        token->coluna++;
    }
}

void void processaEspacoEmEstadoFinal(char espaco, char token, informacoes* info)
{
    consomeEspacos(espaco, info);
    mudaEstado(ESTADO_FINAL);
    setTokenValue(token, info);

}
    