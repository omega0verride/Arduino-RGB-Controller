#define REDPIN 11
#define GREENPIN 10
#define BLUEPIN 9

#define arr_size 10
int data[arr_size];

int index = 0;
int value = 0;
String s, tmp;

void setup() {
  memset(data, 255, arr_size); //sereial data array initialized with 255
  Serial.begin(115200);
  Serial.setTimeout(10); // LOW LATENCY
  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {

  while (Serial.available() > 0) {
    s=Serial.readStringUntil("\n");
    index=0; //reset index each time
    tmp="";//reset tmp value
    
    //this part is basically a split function (it splits the string by comma and puts it into the array)
    for  (char c : s){ //iterate through each charachter of given string 
      if (c!=',')
        tmp+=c;
      else{
        //Serial.println(tmp);
        data[index]=tmp.toInt();
        index++;
        tmp="";
      }
      
    }
    //Serial.println(tmp);
    data[index]=tmp.toInt(); //last value doesnt end with a come so we add it manually

    
    for (int i=0; i<arr_size; i++){
      Serial.println(data[i]);
    }
  }

  analogWrite(REDPIN, data[0]);
  analogWrite(GREENPIN, data[1]);
  analogWrite(BLUEPIN, data[2]);
    
}
