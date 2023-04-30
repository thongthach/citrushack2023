#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>



int reverse =-1;
int in1 = 10;
int in2= 11;
int in3 =5;
int in4 = 9;
int in5=12;
int in6 = 7;
int backward_in1 = 8;

int state =0;
int counter =0;
int button = 8;
int light_led =7;

void setup() {
  pinMode(in1,OUTPUT);
   pinMode(in2,OUTPUT);
   pinMode(in3,OUTPUT);
   pinMode(in4,OUTPUT);
   pinMode(button,INPUT);
    pinMode(in5,OUTPUT);
    pinMode(in6, OUTPUT);
   pinMode(light_led,OUTPUT);
  // put your setup code here, to run once:
 
  Dabble.begin(9600,2,3);
}



void button_control(){
  if(digitalRead(button) ==1){
    digitalWrite(light_led,HIGH);
       
    
   }  
  
  
}
void motor(){
 
     Dabble.processInput(); 
    
      if (GamePad.isUpPressed()){
        
        state=1;
       
       }
       else if(!  (GamePad.isUpPressed())){
        
          state=0;
        
        }

        
       
      
      
       
      
       if(GamePad.isRightPressed() ){
        
            state=2;
        }

        if (GamePad.isLeftPressed() ){
        
          state=3;
         
        }
          /*  state =0;
          
          }
          else if(counter==1){
            
            state=1;  
            if(counter>1){
              counter=0;  
             }
            
          }
           
        counter++;   
        */
        if(GamePad.isDownPressed() ){
        
          state=4;
         
        }
        
        
     
     
      
    
      
  
 }

void loop() {
  if(state==0){
      digitalWrite(in1,LOW);
         digitalWrite(in2,LOW);
         digitalWrite(in3,LOW);
         digitalWrite(in4,LOW);
          digitalWrite(in5,LOW);
         digitalWrite(in6,LOW);
         
      }
      else if(state ==1){
        digitalWrite(in1,HIGH);
         digitalWrite(in2,HIGH);
           digitalWrite(in3,HIGH);
         digitalWrite(in4,HIGH);
         digitalWrite(in5,LOW);
         digitalWrite(in6,LOW);
          
        }
        else if(state ==2){
          
             digitalWrite(in1,LOW);
         digitalWrite(in2 ,LOW);
           digitalWrite(in3,HIGH);
         digitalWrite(in4,HIGH);
         digitalWrite(in5,LOW);
        digitalWrite(in6,LOW);
          
        }
        else if(state==3){
          
           digitalWrite(in1,HIGH);
         digitalWrite(in2,HIGH);
           digitalWrite(in3,LOW);
         digitalWrite(in4,LOW);
         digitalWrite(in5,LOW);
        digitalWrite(in6,LOW);
        }
        else if(state ==4){
          digitalWrite(in5,HIGH);
         digitalWrite(in6,HIGH);
          
         //digitalWrite(in1 ,HIGH);
         //SdigitalWrite(in2,HIGH);
           digitalWrite(in3,LOW);
         digitalWrite(in4,LOW);
          
         }
  
   motor();
   button_control();
  // put your main code here, to run repeatedly:
  }
