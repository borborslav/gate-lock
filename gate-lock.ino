
// UTP cable
// green_w     open_out
// green       open_in
// blue        +12V
// blue_w      +12V
// orange       
// orange_w
// brown       GND
// brown _w    GND

// RF in1
// RF in2
// RF in3
// RF in4
// MOSFET

#define button 2
#define send_signal 4 
#define rf1 5
#define rf2 6
#define rf3 7
#define rf4 8
#define open 9        // MOSFET

const int delay_const = 500; // час відкривання замка
const int debounceDelay = 10; // Затримка між перевірками у мілісекундах
const byte debounceChecks = 3; // кількість разів перевірки натискання кнопки
void open_door()
{
  digitalWrite (open, HIGH);
  delay (delay_const);  
  digitalWrite (open, LOW);
}

bool isButtonPressed() {
  // Перевіряємо стан кнопки debounceChecks разів з затримкою debounceDelay між ними
  for (int i = 0; i < debounceChecks; i++) {
    if (digitalRead(button) != LOW) {
      return false; // Якщо хоча б один раз стан не LOW, кнопка не вважається натиснутою
    }
    delay(debounceDelay); // Затримка між перевірками
  }
  return true; // Кнопка вважається натиснутою, якщо всі перевірки пройшли успішно
}


void setup() {
pinMode (button, INPUT);
pinMode (rf1, INPUT);
pinMode (rf2, INPUT);
pinMode (rf2, INPUT);
pinMode (rf4, INPUT);
pinMode (send_signal, OUTPUT);
pinMode (open, OUTPUT);
digitalWrite (open, LOW);
digitalWrite (button, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead (rf1) == LOW)
  {
    open_door();
  }
if (isButtonPressed()) {
    open_door();
    delay(200); // Затримка, щоб уникнути надмірної кількості повідомлень
 }

 
}
