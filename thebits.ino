const int trigPin = 12;
const int echoPin = 13;
// defines variables
long duration;
int distance;
// connect motor controller pins to Arduino digital pins
// motor one
/*int enA = 10;*/
int in1 = 8;
int in2 = 9;
// motor two
/*int enB = 5;*/
int in3 = 10;
int in4 = 11;

void setup()
{

	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	// set all the motor control pins to outputs
	/*pinMode(enA, OUTPUT);*/
	/*pinMode(enB, OUTPUT);*/
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
}
void demoOne()
{
	// Code block for the ultrasonic sensor

	// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin,  HIGH);

	// Calculating the distance
	distance= duration*0.034/2;

	// End code for ultrasonic sensor

	// Sorta follow mode
	if (distance < 25) {
		// If close stop
		digitalWrite(in1, LOW);
		digitalWrite(in2, LOW);
		digitalWrite(in3, LOW);
		digitalWrite(in4, LOW);
	} else if (distance > 100) {
		// if nothing around turn
		digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
	} else {
		// If in the middle follow
		digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
		digitalWrite(in3, HIGH);
		digitalWrite(in4, LOW);
	}

	delay(100);
}

void loop()
{
	demoOne();
}
