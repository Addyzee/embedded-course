int LED_PIN = 4;
int BUTTON_INPUT = 2;
int buttonState = 0;
int lastButtonState = 0;
int lightState = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_INPUT, INPUT);
}

void loop()
{
  buttonState = digitalRead(BUTTON_INPUT);
  if (buttonState == HIGH && lastButtonState == LOW){
    
    lightState = !lightState;
    digitalWrite(LED_PIN, lightState);
  }
  lastButtonState = buttonState;
 
}