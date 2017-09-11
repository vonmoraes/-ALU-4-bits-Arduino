/* 74181 
 * @author Lucas de Souza Moraes 
 * BITWISE OPERATIONS 
 * SUJESTAO DE ALTERACAO (FAZER AS OPERACOES COMO String E NAO BIT A BIT)
 */

//F MUX:
const int ledF3 = 13;
const int ledF2 = 12;
const int ledF1 = 11;
const int ledF0 = 10;
//LOGICAL CONSTANTS:
const int logical_0 = 0000;
const int logical_1 = 1111;
//DISMEMBERED DIGITS:
int d3, 
    d2,
    d1,
    d0;
int A, //A VALUE
    B, //B VALUE
    S; //MUX INSTRUCTION

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
}
//CHAR TO INTEGER
void toInt(char value){
	return atoi(value);	
}
//BINARY CONVERSION
int toBin(){
	
}
//DISMEMBER VALUE
void dismember(int value){
  int temp = value;
  d3 = temp/1000;
  d2 = (temp/100)%10;
  d1 = ((temp/10)%100)%10;
  d0 = (((temp%1000)%100)%10);
}
//DISPLAY LEDS
void display(int value){
  int temp = value;
  digitalWrite(ledF3, temp/1000);
  digitalWrite(ledF2, (temp/100)%10);
  digitalWrite(ledF1, ((temp/10)%100)%10);
  digitalWrite(ledF0,(((temp%1000)%100)%10));
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
		case 0000: //OK
			ans=not(A);
			break;
		case 0001: //OK
			ans=nor(A,B);
			break;
		case 0010: //OK
			ans=and(A,B);
			break;
		case 0011: //OK
			ans=logical_0;
			break;
		case 0100: //OK
			ans=and(not(A),not(B));
			break;
		case 0101: //OK
			ans=not(B);
			break;
		case 0110: //OK
			ans=xor(A,B);
			break;
		case 0111: //OK
			ans=and(A,B);
			break;
		case 1000: //OK
			ans=or(not(A),B);
			break;
		case 1001: //OK
			ans=xnor(A,B);
			break;
		case 1010: //OK
			ans=B;
			break;
		case 1011: //OK
			ans=and(A,B);
			break;
		case 1100: //OK
			ans=logical_1;
			break;
		case 1101: //OK
			ans=or(A,not(B));
			break;
		case 1110: //OK
			ans=or(A,B);
			break;
		case 0000: //OK
			ans=A;
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
int not(int value){ //OK
	return ~(value);
}
int nor(int value1,int value2){ //OK
	return not(value1 | value2);
}
int and(int value1,int value2){ //OK
	return (value1 & value2);
}
int nand(int value1,int value2){ //OK
	return not(value1 & value2);
}
int xor(int value1,int value2){ //OK
	return (value1 ^ value2);
}
int or(int value1,int value2){ //OK
	return (value1 | value2);
}
int xnor(int value1,int value2){ //OK
	return not(value1 ^ value2);
}
//END LOGICAL

//
void loop() {
	//CODE:
	/*
	A = readChar();
	B = readChar();
	S = readChar();
	display(dismember(mux()))
	*/
	
	//TEST
	desmebrar(1010);
	display();
	delay(1000);
	display(0101);
	//ETEST
	Serial.flush();
}
