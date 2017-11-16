float pouls = 0;
unsigned long time;
int val;
int lock = 0;
int choix;
int i;
void setup() {
 
  Serial.begin(9600);
  for(i=2;i<12;i++){
    pinMode(i,OUTPUT);
  }
  time = 100;
Serial.println("Menu : \nChoisissez le mode de clignotement des LED :\n -1.Remplissage progressif \n -2.Clignotement total \n -3.Chenille \n -4.Une LED sur deux \n -5.Une LED sur trois \n -6.Une LED sur 4 \n -7.Choisir la LED à allumer -8.Roue infinie \n -9.Remplissage/Déremplissage");
while(Serial.available()==0){}
choix=Serial.parseInt();
 
  while (time > 0) {
    Serial.println(((1000.0 * 60.0) / (analogRead(0)))-100);
    pouls = pouls + ((1000.0 * 60.0) / (analogRead(0)))-100;
    delay(100);//prend une valeur tous les :
    time -= 1;
  }
  Serial.println("pouls : ");
  val = pouls/100;//ici avec un delay(100) et un temps de 10000 on a 100 valeurs
  Serial.println(val);
}
 
 
void loop() {
//On demande à l'utilisateur à entrer une valeur.
  switch(choix){
//L'utilisateur entre 1
  case 1:
//Remplissage progressif
for(i=2;i<12;i++){
    if(i==11){
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      delay(60000/(val*10*2));
      for(i=2;i<12;i++){
        digitalWrite(i,LOW);
      }
    }else{
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      delay(60000/(val*10*2));
      digitalWrite(i,LOW);
      delay(60000/(val*10*2));
    }
  }
  break;
//L'utilisateur entre 2
  case 2:
//Clignotement total
 for(i=2;i<12;i++){
      digitalWrite(i,HIGH);
    }
    delay(60000/(val*2));
    for(i=2;i<12;i++){
      digitalWrite(i,LOW);
      if(i==11){
        digitalWrite(i,LOW);
        delay(60000/(val*2));
      }
    }
  break;
 
//L'utilisateur entre 3
  case 3:
//Chenille
for(i=2;i<12;i++){
    if(i==11){
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      delay(60000/(val*10*2));
      for(i=2;i<12;i++){
        digitalWrite(i,LOW);
      }
    }else if(i==2){
      digitalWrite(i,HIGH);
      digitalWrite(10,HIGH);
      delay(60000/(val*10*2));
      digitalWrite(10,LOW);
    }else{
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      delay(60000/(val*10*2));
      digitalWrite(i-1,LOW);
      delay(60000/(val*10*2));
    }
  }
  break;
 
//L'utilisateur entre 4
  case 4:
//Une LED sur 2
 for(i=2;i<12;i=i+2){
      digitalWrite(i,HIGH);
      if(i<12){
        digitalWrite(i,HIGH);
      }
    }
    delay(60000/(val*2));
    for(i=2;i<12;i++){
      digitalWrite(i,LOW);
      if(i==11){
        digitalWrite(i,LOW);
        delay(60000/(val*2));
      }
    }
    break;
   
//L'utilisateur entre 5
  case 5 :
//Une LED sur 3
for(i=2;i<12;i=i+3){
      digitalWrite(i,HIGH);
      if(i<11){
        digitalWrite(i,HIGH);
      }
    }
    delay(60000/(val*2));
    for(i=1;i<12;i++){
      digitalWrite(i,LOW);
      if(i==11){
        digitalWrite(i,LOW);
        delay(60000/(val*2));
      }
    }
    break;
    
//L'utilisateur entre 6
  case 6 :
//Une LED sur 4
for(i=2;i<12;i=i+4){
      digitalWrite(i,HIGH);
      if(i<11){
        digitalWrite(i,HIGH);
      }
    }
    delay(60000/(val*2));
    for(i=1;i<12;i++){
      digitalWrite(i,LOW);
      if(i==11){
        digitalWrite(i,LOW);
        delay(60000/(val*2));
      }
    }
  break;
  
//L'utilisateur entre 7
  case 7 :
//Une LED au choix
  if(lock == 0){
    Serial.println("Entrez la led à allumer : ");
    while(Serial.available()==0){}
    i=(Serial.parseInt()+1);
    if(i<2 || i>11)
    Serial.println("La LED entrée doit être comprie entre 1 et 10. Entrez une nouvelle valeur : ");
    while(i<2 || i>11 ){
      while(Serial.available()==0){}
      i=Serial.parseInt();
      if(i<2 || i>11)
        Serial.println("La LED entrée doit être comprie entre 1 et 10. Entrez une nouvelle valeur : ");
    }
    lock++;
    }
      digitalWrite(i,HIGH);
      delay(60000/(val*2));
      digitalWrite(i,LOW);
      delay(60000/(val*2));
  break;
  
//L'utilisateur entre 8
  case 8 :
//Roue infinie
    digitalWrite(2,HIGH);
    digitalWrite(7,HIGH);
    delay(60000/(val*2*10));
    digitalWrite(2,LOW);
    digitalWrite(7,LOW);
    delay(60000/(val*2*10));
    for(i=3;i<7;i++){
      digitalWrite(i,HIGH);
      digitalWrite(i+5,HIGH);
      delay(60000/(val*2*10));
      digitalWrite(i,LOW);
      digitalWrite(i+5,LOW);
      delay(60000/(val*2*10));
    }
    break;
    
//L'utilisateur entre 9
    case 9 :
//Remplissage / Déremplissage
    for(i=2;i<12;i++){
      digitalWrite(i,HIGH);
      delay(60000/(val*2));
    }
    for(i=2;i<12;i++){
      digitalWrite(i,LOW);
      delay(60000/(val*2));
    }
    break;
   }
}
