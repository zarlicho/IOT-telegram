/*
 Name:		    echoBot.ino
 Created:	    12/21/2017
 Author:	    Stefano Ledda <shurillu@tiscalinet.it>
 Description: a simple example that check for incoming messages
              and reply the sender with the received message
*/
#include "CTBot.h"
CTBot myBot;

String ssid  = "mySSID"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "myPassword"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "myToken"   ; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN
const int led = 5; //pin untuk led
void setup() {
	// initialize the Serial
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");
  pinMode(led, OUTPUT);
	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);
	
	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");
}

void loop() {
	// a variable to store telegram message data
	TBMessage msg;

	// if there is an incoming message...
	if (CTBotMessageText == myBot.getNewMessage(msg))
		// ...forward it to the sender
    if (msg == "led on"){
       digitalWrite(led, HIGH); //HIGH untuk menyalakan led dan LOW untuk mematikan led, kalo kebalik tinggal diubah aja
    }else if(msg == "led off"){ // bisa ganti dengan pesan yang diinginkan misalnya "matikan led" atau apapun itu
       digitalWrite(led, LOW); //HIGH untuk menyalakan led dan LOW untuk mematikan led, kalo kebalik tinggal diubah aja
    }
		myBot.sendMessage(msg.sender.id, msg.text);
	 
	// wait 500 milliseconds
	delay(500);
}
