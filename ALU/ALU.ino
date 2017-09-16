/** ALU 4_bits 74181,
 * Aritmetic Logic Unit with SN54/74LS181 datasheet bitwise operations
 * @author Lucas de Souza Moraes
 * @author Vinícius de Almeida Rocha
 * @author André Albino Bastos
 * @version 0.0.4
 # REFERENCES
 * @link
 * @link https://www.embarcados.com.br/portas-logicas/
 * @link https://www.embarcados.com.br/bits-em-linguagem-c/
  ## NOTE:
  # display(int value); also converts dec to bin. OK
  # MUX(); OK
  # LOGICGATES; OK
  ##
 */
//F MUX:
const int ledF3 = 13;
const int ledF2 = 12;
const int ledF1 = 11;
const int ledF0 = 10;
//LOGICAL CONSTANTS:
const int logical_0 = 0000;
const int logical_1 = 1111;
int A, //A VALUE
    B, //B VALUE
    F; //F VALUE
char S; //MUX INSTRUCTION
String in; //IN SERIAL VALUE
void setup() {
	//SETUP:
	pinMode(ledF3,OUTPUT);
	pinMode(ledF3,OUTPUT);
	pinMode(ledF2,OUTPUT);
	pinMode(ledF0,OUTPUT);
	Serial.begin(9600);
}
//HEX TO DEC
int hexToDec(char value){
	int ans;
	if(isAlpha(value)){
		ans = (int)value - 55;
	}
	else{
		ans = (int)value - 48;
	}
	return ans;
}
//DISPLAY
void display(int value){
  int temp = value;
  if(value < 0){
      temp = value + 16;
  }
  (temp >= 8) && ((temp -= 8) >= 0)? digitalWrite(ledF0, HIGH) : digitalWrite(ledF0, LOW);
  (temp >= 4) && ((temp -= 4) >= 0)? digitalWrite(ledF1, HIGH) : digitalWrite(ledF1, LOW);
  (temp >= 2) && ((temp -= 2) >= 0)? digitalWrite(ledF2, HIGH) : digitalWrite(ledF2, LOW);
  (temp >= 1) && ((temp -= 1) >= 0)? digitalWrite(ledF3, HIGH) : digitalWrite(ledF3, LOW);
}
/* FUNCTION TABLE (@see REFERENCES)
 */
int mux(){
	int ans;
	switch(S){
		case '0': //OK
			ans = NOT(A);
			break;
		case '1': //OK
			ans = NOR(A,B);
			break;
		case '2': //OK
			ans = AND(NOT(A),B);
			break;
		case '3': //OK
			ans = logical_0;
			break;
		case '4': //OK
			ans = NAND(A,B);
			break;
		case '5': //OK
			ans = NOT(B);
			break;
		case '6': //OK
			ans = XOR(A,B);
			break;
		case '7': //OK
			ans = AND(A,NOT(B));
			break;
		case '8': //OK
			ans = OR(NOT(A),B);
			break;
		case '9': //OK
			ans = XNOR(A,B);
			break;
		case 'A': //OK
			ans = B ;
			break;
		case 'B': //OK
			ans = AND(A,B);
			break;
		case 'C': //OK
			ans = logical_1;
			break;
		case 'D': //OK
			ans= OR(A,NOT(B));
			break;
		case 'E': //OK
			ans= OR(A,B);
			break;
		case 'F': //OK
			ans = A ;
			break;
	}
	return ans;
}//END MUX
/* LOGICAL GATES (@see REFERENCES)
 */
int NOT(int value){
	return (~value); //b = ~a;
}
int AND(int value1,int value2){
  return (value1&value2); //c = a & b;
}
int OR(int value1,int value2){
  return (value1|value2); //c = a | b;
}
int NAND(int value1,int value2){
	return ~(value1 & value2); //d = a ~& b;
}
int NOR(int value1,int value2){
  return ~(value1 | value2); //d = a ~| b;
}
int XOR(int value1,int value2){
	return (value1 ^ value2); //c = a ^ b;
}
int XNOR(int value1,int value2){
	return ~(value1 ^ value2); //c = a ~^ b;
}//END LOGICAL GATES
void loop() {
	//CODE:
	/*
	while(Serial.avaliable() > 0){
		in = Serial.readString();
		A = hexToDec(in.charAt(0));
		B = hexToDec(in.charAt(1));
		S = in.charAt(2);
		F = mux();
		display(decToBin(F));
		Serial.flush();
		delay(1000);
	}
	*/
	//TEST
	A = hexToDec('1');
  B = hexToDec('A');
  S = '0';
	int test = mux();
  Serial.println(test);
  display(test);
  delay(500);
	//ENDTEST
   	Serial.flush();
}
