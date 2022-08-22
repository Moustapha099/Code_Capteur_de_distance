/*
 Sen Mecatronique
 Tous droits réservés
Réutilisation á des fins éducatifs autorisée
*/
// definr le numero des pins Trigger et Echo
int trigPin = 8;
int echoPin = 9;
// definer les varibles
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Mettre trigPin en sortie
  pinMode(echoPin, INPUT); // Mettre echoPin en entrée
  Serial.begin(9600); // initialiser le port serie á 9600 bauds 
}
void loop() {
  
  // mettre la pin trigger á l'etat haut pour une durée de 10 microsecondes
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lire echoPin,retourner le temps de parcours de l'onde ultrasonique en microseconde 
  duration = pulseIn(echoPin, HIGH);
  // Calculer la distance
  distance = duration * 0.034 / 2;
  //imprimer la distance dans le moniteur série
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}
