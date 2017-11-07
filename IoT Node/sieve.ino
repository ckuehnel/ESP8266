Skip to content
This repository
Search
Pull requests
Issues
Marketplace
Explore
 @ckuehnel
 Sign out
 Watch 0
  Star 0  Fork 0 ckuehnel/ESP8266
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Insights  Settings
Branch: master Find file Copy pathESP8266/IoT Node/sieve_arduino_ESP8266.ino
cd8a9b1  22 days ago
@ckuehnel ckuehnel Add files via upload
1 contributor
RawBlameHistory     
69 lines (59 sloc)  1.73 KB
//
// Title        : Sieve of Eratosthenes
// Author       : Claus Kuehnel
// Date         : 2017-10-16
// Id		        : sieve_arduino_ESP8266.ino
// Version      : 1.8.5
// based on     : sieve.pde from 2010
//
// DISCLAIMER:
// The author is in no way responsible for any problems or damage caused by
// using this code. Use at your own risk.
//
// LICENSE:
// This code is distributed under the GNU Public License
// which can be found at http://www.gnu.org/licenses/gpl.txt
//

#define TRUE 1
#define FALSE 0

#define SERIAL  Serial

int i,k, prime,count;

const int SIZE = 1000;    
char flags[SIZE+1];

void setup() 
{ 
  delay(5000);
  SERIAL.begin(19200);
  SERIAL.println("Sieve of Eratosthenes - ESP8266");
  
  /*-------------------------------------------------------------------
  The following code is an implementation of the Sieve of Eratosthenes.
  -------------------------------------------------------------------*/
  SERIAL.println("5000 iterations");
  unsigned long time = millis();
  for (unsigned int iter = 1; iter <= 5000; iter++)     /* do program 5000 times */
  {	
    count = 0;			     		 /* initialize prime counter */
    for (i = 0; i <= SIZE; i++)	     /* set all flags true */
      flags[i] = TRUE;
    for (i = 0; i <= SIZE; i++)
    {
      if (flags[i])		             /* found a prime */
      {
	      prime = i + i + 3;	       /* twice index + 3 */
	      for (k = i + prime; k <= SIZE; k += prime)
	        flags[k] = FALSE;	       /* kill all multiples */
	      count++;		               /* primes found */
      }
    }
  }
  time = millis() - time;
  SERIAL.print(count);
  SERIAL.println(" primes.");	    
  SERIAL.print("Runtime = ");
  SERIAL.print(time);
  SERIAL.println(" ms\n");
} 
  
void loop()
{
  // nothing to do
}


© 2017 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
API
Training
Shop
Blog
About
