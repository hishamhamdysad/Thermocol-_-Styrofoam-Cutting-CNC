#include <AFMotor.h>

// تعريف الموتور كـ Stepper بعدد الخطوات في الدورة (مثلاً 200 خطوة)
AF_Stepper motor(200, 2); // 200 خطوة في الدورة، متصل على M1 و M2

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper Motor Test");
  
  // تعيين السرعة (عدد الخطوات في الثانية)
  motor.setSpeed(10); 
}

void loop() {
  Serial.println("تحرك للأمام");
  motor.step(10000, FORWARD, SINGLE); // 10000 خطوة للأمام (Single Step)
  delay(100000);

  Serial.println("تحرك للخلف");
  motor.step(10000, BACKWARD, SINGLE); // 10000 خطوة للخلف (Single Step)
  delay(100000);

  Serial.println("دوران كامل للأمام");
  motor.step(200, FORWARD, DOUBLE); // دوران كامل للأمام (Double Step)
  delay(100000);

  Serial.println("دوران كامل للخلف");
  motor.step(200, BACKWARD, DOUBLE); // دوران كامل للخلف (Double Step)
  delay(100000);
}
