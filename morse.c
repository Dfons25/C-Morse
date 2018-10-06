
/* Use File->Load Prog to
   load a different Program
*/
int sensorPin = A0;
int sensorValue = 0;
int traco = 900;
int ponto = 300;
int espaco = 500;
int ledPin = 13;
//char source[] = ".-.-.-";
char frase[] = "abc";
int numeral;

char *morse[26] = {
".-&", "-...&", "-.-.&", "-..&", ".&", "..-.&", "--.&", "....&", "..&", ".---&", "-.-&", ".-..&", "--&",
"-.&", "---&", ".--.&", "--.-&", ".-.&", "...&", "-&", "..-&", "...-&", ".--&", "-..-&", "-.--&", "--..&"
};

char fraseConvert(char letra){
	int index = letra;
	return *morse[index];
}

void setup()
{	
	pinMode(ledPin,OUTPUT);
}

void loop()
{
	for (int e = 0; e < 3; e++){
		numeral = (int) (frase[e] - '0') - 49;
		
		for (int i = 0; i < 6; i++){
			if(morse[numeral][i] == '&'){	break;}
			
			digitalWrite(ledPin, HIGH);
			
			if(morse[numeral][i] == '.') 
			{	delay(ponto);
				
			} else {
				delay(traco);
			}
			digitalWrite(ledPin, LOW);
			delay(espaco);
		}	
		
	}
}
