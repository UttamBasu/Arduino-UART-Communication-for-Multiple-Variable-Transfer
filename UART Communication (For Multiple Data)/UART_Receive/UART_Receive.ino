#include<SoftwareSerial.h>
SoftwareSerial Arduino_Data(13, 15);   //Rx(13),Tx(15) of Node MCU


//Below is Global Variable data
char c;
String dataIn;
int8_t indexOfA, indexOfB, indexOfC, indexOfD,
       indexOfE, indexOfF, indexOfG, indexOfH,
       indexOfI, indexOfJ, indexOfK, indexOfL, indexOfM;

String data1, data2, data3, data4,
       data5, data6, data7, data8,
       data9, data10, data11, data12, data13;
float A;
void setup()
{
  Serial.begin(9600);               //For Arduino to PC
  Arduino_Data.begin(9600);         //For Serial Communication
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

void loop()
{
  while (Arduino_Data.available() > 0)
  {
    c = Arduino_Data.read();
    if (c == '\n')
    {
      break;
    }
    else
    {
      dataIn += c;
    }
  }
  if (c == '\n')
  {
    Parse_the_Data();

    //Show all data to Serial Monitor
    Serial.println("Hours = " + data1);
    Serial.println("Minutes = " + data2);
    Serial.println("Seconds = " + data3);
    Serial.println("V1  = " + data4);
    Serial.println("V2 = " + data5);
    Serial.println("V3 = " + data6);
    Serial.println("V4 = " + data7);
    Serial.println("Total Volt = " + data8);
    Serial.println("RPM = " + data9);
    Serial.println("Current = " + data10);
    Serial.println("Motor Temp = " + data11);
    Serial.println("Battery Temp = " + data12);
    Serial.println("Controller Temp = " + data13);
    Serial.println("=======================================================");

    //Control the LED_BUILTIN by the one Received variable.
    if (A > 10) {
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      digitalWrite(LED_BUILTIN, HIGH);
    }

    //Reset the variable
    c = 0;
    dataIn = "";
  }
}

///////////////////////////////////////////////////////////////////////////////////////////

void Parse_the_Data()
{
  indexOfA = dataIn.indexOf("A");
  indexOfB = dataIn.indexOf("B");
  indexOfC = dataIn.indexOf("C");
  indexOfD = dataIn.indexOf("D");
  indexOfE = dataIn.indexOf("E");
  indexOfF = dataIn.indexOf("F");
  indexOfG = dataIn.indexOf("G");
  indexOfH = dataIn.indexOf("H");
  indexOfI = dataIn.indexOf("I");
  indexOfJ = dataIn.indexOf("J");
  indexOfK = dataIn.indexOf("K");
  indexOfL = dataIn.indexOf("L");
  indexOfM = dataIn.indexOf("M");


  data1  = dataIn.substring(0, indexOfA);
  data2  = dataIn.substring(indexOfA + 1, indexOfB);
  data3  = dataIn.substring(indexOfB + 1, indexOfC);
  data4  = dataIn.substring(indexOfC + 1, indexOfD);
  data5  = dataIn.substring(indexOfD + 1, indexOfE);
  data6  = dataIn.substring(indexOfE + 1, indexOfF);
  data7  = dataIn.substring(indexOfF + 1, indexOfG);
  data8  = dataIn.substring(indexOfG + 1, indexOfH);
  data9  = dataIn.substring(indexOfH + 1, indexOfI);
  data10 = dataIn.substring(indexOfI + 1, indexOfJ);
  data11 = dataIn.substring(indexOfJ + 1, indexOfK);
  data12 = dataIn.substring(indexOfK + 1, indexOfL);
  data13 = dataIn.substring(indexOfL + 1, indexOfM);

  //Convert the sting to float
  A = data3.toFloat();     //Data3 the float A variable.
}
