/*
   Importando as Bibliotecas
*/
#include <IRremote.h>
#include <math.h>


/*
  Define os Numeros
*/
#define UM -23971
#define DOIS 25245
#define TRES -7651
#define QUATRO 8925
#define CINCO 765
#define SEIS -15811
#define SETE -8161
#define OITO -22441
#define NOVE -28561
#define ZERO -26521
#define MAIS 6375
#define MENOS 19125
#define VEZES 4335
#define DIVIDIR 23205
#define IGUAL 14535

/*
  Variaveis Globais
*/
IRrecv controle(13);
decode_results results;

int numero = 0, numero_aux = 0, count = 0, op = 0;
short int resultado = 0;

/*
  Prototipos
*/
int Verifica(int);
void Numero(int);
void Operacao(int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  controle.enableIRIn(); // Inicializa o receptor IR
}

void loop() {
  delay(1000);
  Serial.println("Esperando...");
  int continuar = 1;
  while(continuar){
    if (controle.decode(&results)){
      int tecla = Verifica(results.value);
      if(tecla){
        int valorTeste = results.value;
        switch (tecla) {
          case 1:
            if(count <= 3){
              Numero(results.value);
            }
            else Serial.println("Memoria Cheia!");
            break;
          case 2:
            Operacao(results.value);
          case 3:
            if((numero_aux)&&(op)&&(numero)){
              switch(op){
                case 1:
                  resultado = numero_aux + numero;
                  break;
                case 2:
                  resultado = numero_aux - numero;
                  break;  
                case 3:
                  resultado = numero_aux * numero;
                  break;
                case 4:
                  resultado = numero_aux / numero;
                  break;
              }
            }
        }
        if(!resultado){
          Serial.print("1 Numero = ");
          Serial.println(numero_aux);
          Serial.print("Operador = ");
          Serial.println(op);
          Serial.print("2 Numero = ");
          Serial.println(numero);
        }
        else{
          Serial.print(" RESULTADO ");
          Serial.print(numero_aux);
          switch(op){
            case 1:
              Serial.print(" + ");
              break;
            case 2:
              Serial.print(" - ");
              break;  
            case 3:
              Serial.print(" * ");
              break;
            case 4:
              Serial.print(" / ");
              break;
          }
          Serial.print(numero);
          Serial.print(" = ");
          Serial.println(resultado);
          op = numero_aux = numero = count = resultado = 0;
        }
      }
      continuar = 0;  
    }
  }
  controle.resume(); //Le o próximo valor
}
/*
  VERIFICA SE O NUMERO DIGITADO É UM NUMERO OU UMA OPERAÇAO
  SE FOR UM NUMERO RETORNA 1
  SE FOR UMA OPERACAO RETORNA 2
  SE FOR O IGUAL RETORNA 3
*/
int Verifica(int valor) {
  int contem = 0;
  if (valor == UM) contem = 1;
  else if (valor == DOIS) contem = 1;
  else if (valor == TRES) contem = 1;
  else if (valor == QUATRO) contem = 1;
  else if (valor == CINCO) contem = 1;
  else if (valor == SEIS) contem = 1;
  else if (valor == SETE) contem = 1;
  else if (valor == OITO) contem = 1;
  else if (valor == NOVE) contem = 1;
  else if (valor == ZERO) contem = 1;
  else if (valor == MAIS) contem = 2;
  else if (valor == MENOS) contem = 2;
  else if (valor == VEZES) contem = 2;
  else if (valor == DIVIDIR) contem = 2;
  else if (valor == IGUAL) contem = 3;
  return contem;
}

void Numero(int num) {
  numero = numero *10; //Anda com o numero uma casa para o lado
  if (num == UM) numero += 1;
  else if (num == DOIS) numero += 2;
  else if (num == TRES) numero += 3;
  else if (num == QUATRO) numero += 4;
  else if (num == CINCO) numero += 5;
  else if (num == SEIS) numero += 6;
  else if (num == SETE) numero += 7;
  else if (num == OITO) numero += 8;
  else if (num == NOVE) numero += 9;
  else if (num == ZERO) numero += 0;
  count += 1;
}

void  Operacao(int operador){
  if(!op){
    numero_aux = numero;
    numero = 0;
    count = 0;
    if (operador == MAIS) op = 1;
    else if (operador == MENOS) op = 2;
    else if (operador == VEZES) op = 3;
    else if (operador == DIVIDIR) op = 4;
  }
}
