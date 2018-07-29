#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void incrementaColuna(informacoes* info);

int conta_vetor (char vet[] );
void q0 (char ch, informacoes tokens);
void q1 (char ch, informacoes tokens);
void q2 (char ch, informacoes tokens);
void q3 (char ch, informacoes tokens);
void q4 (char ch, informacoes tokens);
void q5 (char ch, informacoes tokens);
void q6 (char ch, informacoes tokens);
void q7 (char ch, informacoes tokens);
void q8 (char ch, informacoes tokens);
void q9 (char ch, informacoes tokens); // ESTADO_INICIAL
void q10 (char ignorado, informacoes tokens); // FINAL OUTROS
void q11 (char ch, informacoes tokens); // Final OPERADOR RELACIONAL
void q12 (char ch, informacoes tokens); // Final OPERADOR
void q13 (char ch, informacoes tokens);
void q14 (char ch, informacoes tokens); // Final PONTO FLUTUANTE
void q15 (char ch, informacoes tokens); // Final PONTO FLUTUANTE
void q16 (char ch, informacoes tokens); // Final OPERADOR
void q17 (char ch, informacoes tokens); // Final IDENTIFICADOR
void q18 (char ch, informacoes tokens); // Final PONTO FLUTUANTE


// Funcoes 
typedef void (* funcaoEstado)(char ch, informacoes tokens);
funcaoEstado estados[] = { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18 };
int estadoAtual;

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
        
        estados[estadoAtual](ch, var);
        
    }
    printf("Linhas %d e Colunas %d\n" ,var.linha, var.coluna); 
    /**/
}

int conta_vetor (char vet[] ){
    int i=0;
    while(vet[i]){
        i++;
    }
    return i ; 
}
void q9 (char ch, informacoes tokens){
    char vet[255];
    int i ;
    if(ch == '?'){
    //    setTokenValue(tokens, "?"); 
        q0('=',tokens);
    }else if(ch == '#'){
   //     setTokenValue(tokens, "#"); 
        q16('#',tokens);
        
    }else if(ch == '|'){
    //  setTokenValue(tokens, "|"; 
        q8('|',tokens);
    }else if(ch == '*'){ // 
    //  setTokenValue(tokens, OPERADOR); 
        q12(' ',tokens);
    }else if(ch == '&'){ // Qualquer Caractere
   //   setTokenValue(tokens, '&'); 
 //       q3(' ',tokens);
    }else if(ch == '='||ch == '>'||ch == '<'){
        vet[0] = ch;
    //    setTokenValue(tokens, ch) 
  //      //tokens.token = vet; 
        q11(' ',tokens);
    }else if(ch == '/'||ch == '%'||ch == '['||ch == ']'||ch == '{'||ch == '}'||ch == ';'||ch == ','){
        vet[0] = ch;
 //       //tokens.token = ""; 
 //       //tokens.token = vet; 
        q10(' ', tokens);
    }else if(ch == '"'){
       // //tokens.token = "\""; 
        // q10(' ', tokens);
        q2('g',tokens);
    }
    
    setLexemaValue(&tokens, &ch);
  
}

void q0 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch == '='){
        strcpy(vet,tokens.token);
        // i =  conta_vetor(vet);
        strcat(vet, "=");
          //tokens.token = ""; 
          //tokens.token = vet; 
          q10(' ', tokens);
      }

}
void q8 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch == '|'){
        strcpy(vet,tokens.token);
        // i =  conta_vetor(vet);
        strcat(vet, "|");
          //tokens.token = ""; 
          //tokens.token = vet; 
          q10(' ', tokens);
      }else{
      printf("erro carracrte: %c nao esperado",ch);
      }

}
void q16 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch == '#'){
        strcpy(vet,tokens.token);
        // i =  conta_vetor(vet);
        strcat(vet, "#");
          //tokens.token = ""; 
          //tokens.token = vet; 
          q10(' ', tokens);
      }else if(ch != ' '){
          q10(' ', tokens);
      }else{
        printf("erro carracrte: %c nao esperado",ch);
      }
  }

void q12 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch == '@'){
        strcpy(vet,tokens.token);
        // i =  conta_vetor(vet);
        strcat(vet, "@");
          //tokens.token = ""; 
          //tokens.token = vet; 
          q10(' ', tokens);
      }else if(ch != ' '){
          q10(' ', tokens);
      }else{
        printf("erro carracrte: %c nao esperado",ch);
      }

}
void q3 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch == '&'){
        strcpy(vet,tokens.token);
        // i =  conta_vetor(vet);
        strcat(vet, "&");
          //tokens.token = ""; 
          //tokens.token = vet; 
          q10(' ', tokens);
      }else if(ch == ' '){
        printf("espaço nao esperado");
      }else{
        printf("erro carracrte: %c nao esperado",ch);
      }

}
void q11 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch == '='){
        strcpy(vet,tokens.token);
        // i =  conta_vetor(vet);
        strcat(vet, "=");
          //tokens.token = ""; 
          //tokens.token = vet; 
          q10(' ', tokens);
      }else if(ch == ' '){
          q10(' ', tokens);
      }else{
        printf("erro carracrte: %c nao esperado",ch);
      }

}
void q2 (char ch, informacoes tokens){
  char vet[255];
      int i ;
        // q10(' ', tokens);
      
      // if(ch == '\\'){
      //   strcpy(vet,tokens.token);
      //   i =  conta_vetor(vet);
      //   vet[i+1] = ch ;
      //   // strcat(vet, "=");
      //     //tokens.token = ""; 
      //     //tokens.token = vet; 
      //     q1('a',tokens);
      // }else
       if(ch !='\\'||ch != '\'' ){
        // q10(' ', tokens);
          q7('q',tokens);
      }
      // else{
      //   printf("erro carracrte: %c nao esperado",ch);
      // }

}
void q1 (char ch, informacoes tokens){
  char vet[255];
      int i ;
      if(ch !='\\'||ch != '\'' ){
        strcpy(vet,tokens.token);
        i =  conta_vetor(vet);
        vet[i+1] = ch ;
          //tokens.token = ""; 
          //tokens.token = vet; 
          q7('w',tokens);
      }else{
        printf("erro carracrte: %c nao esperado",ch);
      }

}
void q7 (char ch, informacoes tokens){
  char vet[255];
      int i ;
        q10(' ', tokens);
      
      if(ch !='\\'||ch != '\'' ){
        strcpy(vet,tokens.token);
        i =  conta_vetor(vet);
        vet[i+1] = ch ;
          //tokens.token = ""; 
          //tokens.token = vet; 
          q7('\'',tokens);
      }
      // }else if(ch == '\\'){
      //   strcpy(vet,tokens.token);
      //   i =  conta_vetor(vet);
      //   vet[i+1] = ch ;
      //     //tokens.token = ""; 
      //     //tokens.token = vet; 
      //     q1('\\',tokens);
      // }else if(ch == '"'){
      //   strcpy(vet,tokens.token);
      //   i =  conta_vetor(vet);
      //   vet[i+1] = ch ;
      //     //tokens.token = ""; 
      //     //tokens.token = vet; 
      //     q10(' ', tokens);
      // }else{
      //   printf("erro carracrte: %c nao esperado",ch);
      // }

}
void q10 (char ignorado,  informacoes tokens){ //FINAL

        printf("%s",tokens.token);

}

void q4 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q5 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q6 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q13 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q14 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q15 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q17 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}

void q18 (char ignorado,  informacoes tokens) {
    // TODO: Implementar
}











// Auxiliares

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