const int pin_names[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
const int sensor = A0;
int x, y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // test setup
  binary_count(1024);
  //binary_write(187);
  
  // read sensor
  //int sensor_value = analogRead(sensor);
  //Serial.println(sensor_value);
  
  // run sensor
  //binary_write(sensor_value);
}

void binary_count(int val)
{
  for(int x=0; x<=val; x++)
  {
    binary_write(x);     
  } 
}

void binary_write(int val)
{
  int pins[12]; 
  int num = val;
    
  for(int exponent=11; exponent>=0; exponent--)
  {
    if(num>=pow(2,exponent))
    {
      num = num - pow(2,exponent);
      pins[exponent] = 1;
    }
    else
    {
      pins[exponent] = 0;
    }
  }
    
  for(int y=0; y<=sizeof(pin_names); y++)
  {
    if(pins[y]==1)
    {
      digitalWrite(pin_names[y], HIGH); 
    }
    else
    {
      digitalWrite(pin_names[y], LOW); 
    }
  }
  delay(125);       
}
