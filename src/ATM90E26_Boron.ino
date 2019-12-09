/*
 * Project ATM90E26_Boron
 * Description: ATM90E26 Test code for Particle Boron
 * Author: Tisham (whatnick) Dhar - tisham@whatnick.com
 * Date: 
 *  10/12/2019 - Initial code from https://docs.particle.io/support/particle-devices-faq/electron-3rdparty-sims/#setting-up-a-3rd-party-sim-card-boron
 */

#include "Particle.h"

#include "dct.h"

// setup() runs once, when the device is first turned on.
void setup()
{
  Cellular.setActiveSim(EXTERNAL_SIM);
  
  // Optus APN as per - https://www.optus.com.au/for-you/support/answer?id=1378
  Cellular.setCredentials("yesinternet");

  // This clears the setup done flag on brand new devices so it won't stay in listening mode
  const uint8_t val = 0x01;
  dct_write_app_data(&val, DCT_SETUP_DONE_OFFSET, 1);

  // This is just so you know the operation is complete
  pinMode(D7, OUTPUT);
  digitalWrite(D7, HIGH);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // The core of your code will likely live here.
}