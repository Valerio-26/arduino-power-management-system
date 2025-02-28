PKAE_Timer Library by PKAE Electronics 
======================================

This class is a simple timer implementation that allows you to check if a certain amount of time has passed and optionally reset the timer. It can be useful for various timing-related tasks in embedded systems or other applications.

PKAE_Timer Constructor
----------------------
The constructor initializes the timer with an optional initial delay. If no delay is provided, it defaults to 0.
It sets the member variable _delay to the specified delay, initializes nStarted with the current time using the millis() function, and sets nLastStarted and nCount to 0.

Example:-

      PKAE_Timer Flash_LED(500);


The above line defines a timer instance called "Flash_LED" and the delay is set to 500 m/s.The count down starts the moment the instance is created.



IsTimeUp() Function
-------------------
The IsTimeUp function checks if the specified time has elapsed since the timer was last started.
It calculates the effective delay to check against as the maximum of the fixed delay _delay and a dynamic delay nDynamicDelay.
If the elapsed time is greater than the effective delay, it returns true indicating that the time is up.
If lReset is true, it increments the count nCount, updates nLastStarted to the previous start time, and sets nStarted to the current time.


Example:-

      if (Flash_LED.IsTimeUp()) {
   	    // put code here e.g. toggle the LED state On/Off.
      }

This will execute the code withihn the curly braces whyenever the timer (500m/s in our example) is reached. The timer automatically resets itself to start again.

You can pass an optional dynamic delay to check if an alternative duration has lapsed or not.

Example:-
      if (Flash_LED.IsTimeUp(250)) {
   	    // put code here to execute if 250m/s has lapsed. 
      }		

You can also pass an optional boolean expression to determine if the timer is reset or not. Handy if you wanted to temporarily stop the flashing for example.

Example:-

      if (Flash_LED.IsTimeUp(250,false)) {
   	    // put code here to execute if 250m/s has lapsed. The timer will not reset.
      }		


Reset() Function
----------------
The Reset function resets the timer by updating nLastStarted to the previous start time and setting nStarted to the current time using millis().

Example:-

      Flash_LED.Reset();

This will effectivly restart the timer counter for the Flash_LED timer instance.


Member Variable .nCount
--------------------------
Retains a counter of the number of itterations that the timer instance has triggered. 

Example:-

      xCount=Flash_LED.nCount;

xCount will store the number of times this timer has triggered,


Member Variable .nStarted
--------------------------
Retains the millis() reading at the time in millis that the timer was started (either by its initial creation or by its last reset).

Example:-

      xStarted=Flash_LED.nStarted;

xStarted will store when the last timer started for this timer instance. i.e. the millis() reading at the time it last initiated.


Member Variable .nLastStarted
--------------------------
Retains the millis() reading of the previous time timer was started. 

Example:-

      xLastStarted=Flash_LED.nLastStarted;

xLastStarted will store when the previous timer started for this timer instance. i.e. the millis() reading at the time it previously initiated.

