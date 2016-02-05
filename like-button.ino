int likes = 0;
int frequentie = 10;
int button = LOW;
int buttonPin = D0;
int ledPin = D7;


void setup() {
    pinMode(buttonPin,INPUT);
    pinMode(ledPin,OUTPUT);
}




void loop() {                                       // Dit programma draait de hele tijd

digitalWrite(ledPin, HIGH);                         // Zet een ledje aan, zo dat we weten dat hij werkt

    
button = digitalRead(buttonPin);                    // Meet of de knop ingedrukt wordt


if (button == HIGH){                                // Als de knop in gedrukt wordt
    likes++;                                        // Tel 1 like op bij de likes
    digitalWrite(ledPin, LOW);                      // Zet het ledje even uit, dan weten dat de knop werkt
    
    if (likes % frequentie == 0){                   // Als het aantal like deelbaar is door de frequentie (10)
        Spark.publish("publish",String(likes));     // Publiceer hoeveel het er zijn (dat wordt getweet)
   }
    
    delay(400);                                     // Wacht even (tegen spammen en zodat je ziet dat LED uit is)
    button = LOW; 
}

delay(50);
}
