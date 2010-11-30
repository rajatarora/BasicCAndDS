/**
  * CircularQueueArray.h
  * Declares a Circular Queue using an Array, along with related methods.
  * 
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * November 28, 2010
  *
  **/

#define MAX 3 /* Max number of elements in Queue */  
#define ERROR -32767 /* Error condition */

typedef struct /* Defining the Queue */
{
	int Array[MAX]; /* The Array */
	int Front; /* Front and Rear */
	int Rear;
}Queue;

/* Method definitions */
void Init(Queue*); /*Initialize Front and Rear to -1 */
void Insert(Queue*,int); /* Insert into */
int Delete(Queue*); /* Delete from */
void Display(Queue*); /* Display Queue */
