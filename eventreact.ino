//LED PIN
int boardLed = D7;

//Flag to trigger wave and pat
bool publishtime = true;


//forward declaration
void lightup(const char *event, const char *data);

void setup()
{
 	 //board led is output
	pinMode(boardLed, OUTPUT);

	// Subscribe to fake event
	Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", lightup);


}

void loop()
{
    if(publishtime == true)
    {
        Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave", PRIVATE);
        publishtime = false;
    }
    else
    {
        if(publishtime==false)
        {
          Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat", PRIVATE);
          publishtime = true;
        }
        
    }

}

//Function that tells the argon how to react to wave and pat 
void lightup(const char *event, const char *data)
{

  //3 quick blinks for wave
	if (strcmp(data, "wave") ==0)
	{
		// if the beam is intact, then turn your board LED off
		digitalWrite(boardLed, HIGH);
		delay(1000);
		digitalWrite(boardLed, LOW);
		delay(200);
		digitalWrite(boardLed, HIGH);
		delay(1000);
		digitalWrite(boardLed, LOW);
		delay(200);
		digitalWrite(boardLed, HIGH);
		delay(1000);
		digitalWrite(boardLed, LOW);
		delay(200);
		digitalWrite(boardLed, HIGH);
		delay(1000);
		digitalWrite(boardLed, LOW);
		delay(6000);//longer off to differentiate between pat and wave
	}
	//2 long blinks for pat
	else if (strcmp(data, "pat") == 0)
	{
		
		digitalWrite(boardLed, HIGH);
		delay(4000);
		digitalWrite(boardLed, LOW);
		delay(500);
		digitalWrite(boardLed, HIGH);
		delay(4000);
		digitalWrite(boardLed, LOW);
		delay(6000);//longer off to differentiate between pat and wave
	}
	else
	{
	 // if any other data arises do nothing
	}
}
