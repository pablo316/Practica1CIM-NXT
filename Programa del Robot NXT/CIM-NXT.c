#pragma config(Sensor, S1,     lightSensor1,   sensorLightActive)
#pragma config(Sensor, S2,     lightSensor2,   sensorLightActive)
#pragma config(Sensor, S3,     sonarSensor,    sensorSONAR)
#pragma config(Sensor, S4,     lightSensor3,   sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(NXT)


//#define 	sensorCOLORFULL   0x0D


ubyte OutgoingMessage[6] = {0,0,0,0,0,0};



task main()
{

	while(true)
	{



	SensorType[sonarSensor] = sensorSONAR;
	/*if (SensorValue (touchSensor)==1)
					OutgoingMessage[0]=1;
			else
	        OutgoingMessage[0]=0;*/

	OutgoingMessage[1]= SensorValue(sonarSensor);


      nxtDisplayCenteredBigTextLine(2,"Enviando");
      nxtDisplayCenteredBigTextLine(4,"Datos...");

	    /*short nRawValues[4]={1,1,1,1};
			getColorSensorData(colorfullSensor, colorRaw,    &nRawValues[0]);
			OutgoingMessage[2]= nRawValues[0];
			OutgoingMessage[3]= nRawValues[1];
			OutgoingMessage[4]= nRawValues[2];*/

			OutgoingMessage[2]= SensorValue(lightSensor1);
			OutgoingMessage[3]= SensorValue(lightSensor2);
			OutgoingMessage[4]= SensorValue(lightSensor3);

		cCmdMessageWriteToBluetooth(OutgoingMessage,6,mailbox1);
		wait1Msec(100);
	}

}
