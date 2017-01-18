#include <string.h>
#include <stdio.h>

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println();
}

struct data{
  String ssid;
  String pass;
  String url;
  //long h01, h02, h03, h04, h05, h06, h07, h08, h09, h10, h11, h12, h13, h14, h15, h16, h17, h18, h19, h20, h21, h22, h23, h24, h25, h26, h27, h28;
  long int hidro[28];
};

struct data decompose(String wordC){                     //Decompose in the struct the word
  Serial.println(wordC);
  char _word[wordC.length()];
  strcpy(_word, wordC.c_str());
  char *piece;
  int cont = 0;
  struct data info;
  
  piece = strtok(_word,"#&");
  while (piece != NULL){
    if (cont == 0)
      info.ssid = String(piece);
    else if (cont == 1)
      info.pass = String(piece);
    else if (cont == 2)
      info.url = String(piece);
    else
      info.hidro[cont-3] = atol(piece);
    cont++;
    piece = strtok(NULL, "#&");
  }
  return info;
}

String compose(struct data d){                          //Componse int the word the struct
  String wordC = d.ssid;
  wordC += "#&";
  wordC += d.pass;
  wordC += "#&";
  wordC += d.url;
  wordC += "#&";

  for (int i = 0; i < 28; i++){
    wordC += d.hidro[i];
    wordC += "#&";
  }
  return wordC;
}

void loop() {
  delay(5000);
  struct data info = decompose("Trojan Horse#&riboflavina#&http://google.com#&69#&0#&2#&3#&444444#&5555555#&6666666#&777777#&888888#&999999999#&11#&12#&13#&14#&15#&16#&17#&18#&19#&20#&21#&22#&23#&24#&25#&0#&0#&69#&");
  Serial.println(info.ssid);
  Serial.println(info.pass);
  Serial.println(info.url);
  for (int i = 0; i<28; i++){
    Serial.println(info.hidro[i]);
  }

  delay(1000);
  Serial.println();
  Serial.println("Compose Word: ");
  Serial.println(compose(info));
  
}
