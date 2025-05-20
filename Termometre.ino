  #include <LiquidCrystal_I2C.h>
  #include <dht11.h>
  
  #define mavi_led 6
  #define sari_led 9
  #define kirmizi_led 10
  #define dht11_sensor 3
  int olcum=0,min_deger=903,yuzde=0,deger=0;
  dht11 dht_sensor;
  LiquidCrystal_I2C lcd(0x27,16,2);
  byte ozel_karakter[8]={0xC,0x12,0x12,0xC,0x0,0x0,0x0,0x0};
  byte ozel_karakter_2[8]={0x0,0x0,0x4,0xE,0x4,0x4,0x4,0x0};
void setup() 
{
  pinMode(mavi_led,OUTPUT);
  pinMode(sari_led,OUTPUT);
  pinMode(kirmizi_led,OUTPUT);
  pinMode(dht11_sensor,INPUT);
  lcd.begin();
  lcd.createChar(0,ozel_karakter);
  lcd.createChar(1,ozel_karakter_2);
}

void loop() 
{
  lcd.clear();
int oku=dht_sensor.read(dht11_sensor);
lcd.setCursor(0,0);
float sicaklik=(float)dht_sensor.temperature,nem=(float)dht_sensor.humidity;
lcd.print("Temp :");
lcd.print((int)sicaklik);
lcd.write(byte(0));
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Hmd :");
lcd.print("%");
lcd.print((int)nem);

if(sicaklik>0&&sicaklik<30)
{
  digitalWrite(kirmizi_led,LOW);
  digitalWrite(sari_led,LOW);
  digitalWrite(mavi_led,HIGH);
 if(nem>0&&nem<26)
  {
  lcd.setCursor(11,1);
  lcd.print("");
  lcd.print("Sunny");  
  }
  if(nem>26&&nem<75)
  {
  lcd.setCursor(12,1);
  lcd.print("");
  lcd.print("Damp");
  }
  if(nem>75&&nem<90)
  {
  lcd.setCursor(11,1);
  lcd.print("");
  lcd.print("Rainy");
  }
  if(nem>90)
  {
  lcd.setCursor(13,1);
  lcd.print("");
  lcd.print("Thn");
  }
}
if(sicaklik>30&&sicaklik<35)
{
  digitalWrite(kirmizi_led,LOW);
  digitalWrite(mavi_led,LOW);
  digitalWrite(sari_led,HIGH);
  if(nem>0&&nem<26)
  {
  lcd.setCursor(11,1);
  lcd.print("");
  lcd.print("Sunny");  
  }
  if(nem>26&&nem<75)
  {
  lcd.setCursor(12,1);
  lcd.print("");
  lcd.print("Damp");
  }
  if(nem>75&&nem<90)
  {
  lcd.setCursor(11,1);
  lcd.print("");
  lcd.print("Rainy");
  }
  if(nem>90)
  {
  lcd.setCursor(13,1);
  lcd.print("");
  lcd.print("Thn");
  }
}
if(sicaklik>35)
{
  digitalWrite(mavi_led,LOW);
  digitalWrite(sari_led,LOW);
  digitalWrite(kirmizi_led,HIGH);
  if(nem>0&&nem<26)
  {
  lcd.setCursor(11,1);
  lcd.print("");
  lcd.print("Sunny");  
  }
  if(nem>26&&nem<75)
  {
  lcd.setCursor(12,1);
  lcd.print("");
  lcd.print("Damp");
  }
  if(nem>75&&nem<90)
  {
  lcd.setCursor(11,1);
  lcd.print("");
  lcd.print("Rainy");
  }
  if(nem>90)
  {
  lcd.setCursor(13,1);
  lcd.print("");
  lcd.print("Thn");
  }
}
lcd.setCursor(15,0);
lcd.write(byte(1));
delay(1000);
/*olcum=analogRead(batarya);
// 861 max
// 758 min
if(olcum>=861)
{
  olcum=861;  
}
if(olcum<=779)
{
olcum=779;  
}
*/
}
