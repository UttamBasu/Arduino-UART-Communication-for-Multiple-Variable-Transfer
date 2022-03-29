int HH = 00;
int MM = 00;
int SS1 = 00;

float V1 = 12.5252;
float V2 = 13.2548;
float V3 = 14.9853;
float V4 = 15.2425;
float Vt = 60.5982;

int RPM = 350;
float C = 25.25;
float tm = 36.7805;
float tc = 39.4589;
float tb = 42.5854;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  SS1 = SS1 + 1;
  if (SS1 > 59)
  {
    MM++;
    SS1 = 0;
  }
  if (MM > 59)
  {
    HH++;
    MM = 0;
    SS1 = 0;
  }

  Serial.print(HH), Serial.print("A");
  Serial.print(MM), Serial.print("B");
  Serial.print(SS1), Serial.print("C");
  
  Serial.print(V1,4), Serial.print("D");    //For 4 decimal float
  Serial.print(V2,4), Serial.print("E");
  Serial.print(V3,4), Serial.print("F");
  Serial.print(V4,4), Serial.print("G");
  Serial.print(Vt,4), Serial.print("H");
  
  Serial.print(RPM), Serial.print("I");
  Serial.print(C,2), Serial.print("J");     //For 2 decimal float
  Serial.print(tm,4), Serial.print("K");    //For 4 decimal float
  Serial.print(tc,4), Serial.print("L");
  Serial.print(tb,4), Serial.print("M");
  Serial.print("\n");                       //For New Line


  delay(1000);
}
