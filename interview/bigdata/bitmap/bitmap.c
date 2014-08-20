/*
* http://amsekharkernel.blogspot.com/2013/07/what-is-bit-map-and-its-implementation.html
*/

#include<stdio.h>
#include<stdlib.h>

#define EXIT 100

#define BITMAP_LEN 2
#define BYTE_LEN   8

/* Debug OutPut */
void printTheDebugOutput(unsigned char *bit_array)
{
   int i, j;

   /* Array is 2 bit_array[0] and [1] */
   for (i=0 ; i<BITMAP_LEN; i++)
   {
     /* Bits 0..7 */
     for(j=1; j<=BYTE_LEN; j++)
     {
        if(bit_array[i] & (1 << (j-1)))
        {
           printf("In BIT_MAP[%d] the position of Bit SET : %d\n",
                                   i, j); 
        }
     }
   }
}

/*
 *  Main() function
 */
int main()
{

  unsigned int bit_position, setOrUnsetBit, ch;
  unsigned char bit_Map_array_index, shift_index;

  /* Declare Bit Array and intialised to Zero 
   * This BIT_MAP is generally assigned to one domain.
   * Here BIT MAP (Array of Bits) are used for Debugging Mechanism 
   */
  unsigned char bit_map[BITMAP_LEN] = { 0 };
  
  /* In Bit- Maps , there are two options, 
   * either  Set (OR |) or  Unset (AND &) bit. 
   */
 do 
 {
    /* Here the Max number of bits is 16 ranging from 1..16 */
    printf("Enter the Bit position (bit starts from 1 and Ends at 16) \n");
    scanf("%d", &bit_position);  

    /* 
     * Set/Unset the Bit Map indicates which bits you want to enable  
     */
    printf(" Do you want to set/unset the Bit (1 or 0) \n");
    scanf("%d", &setOrUnsetBit);

    /* LOGIC as follows */
    /* Find Out the Index and and as well as Shift Index */ 

    /* It Give output as 0 or 1 ( for Bit Position 1..16) */
    bit_Map_array_index = (bit_position-1) / 8;

    /* Always give output as 0...7 ( for Bit Position 1..16)*/
    shift_index =  (bit_position-1) % 8;

    printf("The bit_position : %d shift Index : %d\n", bit_position, shift_index);

    /* If set is true */
    if( setOrUnsetBit)
     {         
       /* Set the Bit Array */ 
       bit_map[bit_Map_array_index] |= 1<<shift_index;                 
     }
    else
     {  
        /* Clear the Bit Array */  
        bit_map[bit_Map_array_index] &= ~(1<<shift_index);         
     }
    printf(" The Bit MAP Array : %d\n", bit_map[bit_Map_array_index]);
    printTheDebugOutput(bit_map);
    
    printf(" Do You want to Continue then Enter any Number"
           "and for Exit then enter 100\n");
    scanf("%d", &ch);

  }while(ch != 100);
 return 0; 
}
