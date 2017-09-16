/* 74181
 * @version 0.0.3
 * @author Lucas de Souza Moraes
 * BITWISE OPERATIONS
 * https://www.embarcados.com.br/portas-logicas/
 * https://www.embarcados.com.br/bits-em-linguagem-c/
 */

//F MUX:
const int ledF3 = 13;
const int ledF2 = 12;
const int ledF1 = 11;
const int ledF0 = 10;
//LOGICAL CONSTANTS:
const int logical_0 = "0000";
const int logical_1 = "1111";
//DISMEMBERED DIGITS: //DEPRECATED
int d3,
    d2,
    d1,
    d0;
int A, //A VALUE
    B, //B VALUE
    F; //F VALUE
char S; //MUX INSTRUCTION
String bin = "0000", //BIN VALUE
	in; //IN SERIAL VALUE
void setup() {
	//SETUP:
	pinMode(ledF3,OUTPUT);
	pinMode(ledF3,OUTPUT);
	pinMode(ledF2,OUTPUT);
	pinMode(ledF0,OUTPUT);
	Serial.begin(9600);
}
//
char readChar(){
	return Serial.read();
} //DEPRECATED
//CHAR TO INTEGER
void toInt(char value){ //DEPRECATED
	return atoi(value);
}
//HEX TO DEC
int hexToDec(char value){
	int ans;
	if(isHexadecimalDigit(value)){
		ans = (int)value - 55;
	}
	else{
		ans = (int)value - 48;
	}
	return ans;
}
//DEC TO BIN
void decToBin(int value){
	String temp = String(value,BIN);
  bin.setCharAt(0) = temp.charAt(temp.length() - 3);
  bin.setCharAt(1) = temp.charAt(temp.length() - 2);
  bin.setCharAt(2) = temp.charAt(temp.length() - 1);
  bin.setCharAt(3) = temp.charAt(temp.length());
}
//DISMEMBER VALUE
void dismember(int value){ //DEPRECATED
	int temp = value;
	d3 = temp/1000;
	d2 = (temp/100)%10;
	d1 = ((temp/10)%100)%10;
	d0 = (((temp%1000)%100)%10);
}
//DISPLAY LEDS
void display(int value){ //DEPRECATED
	int temp = value;
	digitalWrite(ledF3, temp/1000);
	digitalWrite(ledF2, (temp/100)%10);
	digitalWrite(ledF1, ((temp/10)%100)%10);
	digitalWrite(ledF0,(((temp%1000)%100)%10));
}
void display(String value){
	digitalWrite(ledF3, value.charAt(0));
	digitalWrite(ledF2, value.charAt(1));
	digitalWrite(ledF1, value.charAt(2));
	digitalWrite(ledF0, value.charAt(3));
}
/*FUNCTION TABLE L = LOW H = HIGH
LLLL = A'		HLLL = or(A',B)
LLLH = nor(A,B)		HLLH = xnor(A,B)
LLHL = and(A',B)	HLHL = B
LLHH = Logical(0)	HLHH = and(A,B)
LHLL = and(A',B')	HHLL = Logical(1)
LHLH = B'		HHLH = or(A,B')
LHHL = xor(A,B)		HHHL = or(A,B)
LHHH = and(A,B')	HHHH = A
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
			ans = AND(A,B);
			break;
		case '3': //OK
			ans = logical_0;
			break;
		case '4': //OK
			ans = AND(NOT(A),NOT(B));
			break;
		case '5': //OK
			ans = NOT(B);
			break;
		case '6': //OK
			ans = XOR(A,B);
			break;
		case '7': //OK
			ans = AND(A,B);
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
}
//END MUX
/*LOGICAL CHART & MNEMONIC
A' = An			or(A',B) = AnoB
nor(A,B) = nAoB		xnor(A,B)' = nAxB
and(A',B) = AnB		B = B
Logical(0) = zeroL	and(A,B) = AB
and(A',B') = nAeB	Logical(1) = umL
B' = Bn			or(A,B') = AoBn
xor(A,B) = AxB		or(A,B) = AoB
and(A,B') = ABn		A = A
*/
int NOT(int value){ //OK
	return (~value); //b = ~a;
}
int AND(int value1,int value2){
  return (value1 & value2); //c = a & b;
}
int OR(int value1,int value2){
  return (value1 | value2); //c = a | b;
}
int NAND(int value1,int value2){
	return not(value1 & value2); //d = a ~& b;
}
int NOR(int value1,int value2){
  return not(value1 | value2); //d = a ~| b;
}
int XOR(int value1,int value2){
	return (value1 ^ value2); //c = a ^ b;
}
int XNOR(int value1,int value2){
	return not(value1 ^ value2); //c = a ~^ b;
}
//END LOGICAL
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
	A = hexToDec('A');
  B = hexToDec('B');
  S = '6';
	int test = mux();
  decToBin(test);
  delay(500);
	Serial.println("OI :"+bin);
  display(bin);
	//ENDTEST

  /* NOTE: toBin - fix String bin = '0000' 4bits
     Logic test{
     NOT(A);
     AND(A,B);
     OR(A,B);
     NAND(A,B);
     NOR(A,B);
     XOR(A,B);
     XNOR(A,B);
     }
   */

   	Serial.flush();
}
