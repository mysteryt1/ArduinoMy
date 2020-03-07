#define sw 8
int r;
int num=0;
bool c1,c2,c3;
void setup() {
  Serial.begin(9600);
  pinMode(sw,INPUT_PULLUP);
}
//----Switch ปล่อยเเล้วทำ----
/*
 Serial.println(num);
 if(r==0){
    c1=true;
 }
 if(r==1&&c1==true){
    num+=1;
    c1=false;
 }
 */
//----Switch ปล่อยเเล้วทำ----

//----Switch กดเเล้วทำ------
/*
if(c2){
 if(r==0){
    num+=1;
    c2=false;
  } 
 }
 if(r==1){
    c2=true;
 }
 */
//----Switch กดเเล้วทำ------
 
void loop() {
 r=digitalRead(sw);
 Serial.println(num);
 if(r==0){
    c1=true;
 }
 if(r==1&&c1==true){
    num+=1;
    c1=false;
 }
}
