#include <stdio.h>
#define MAXPLACE 64
#define arrSize 16

int PrintBitsFromInt(int x);
int getPlaceValueFromInt(double x);
int printNumBitsFromPlaceArray(int placeArr[]);

int main(int argc, char const *argv[]) {
  printf("Welcome To Bit Converter.\nConvert any 16-bit signed integer to a BitRepresentation.\nWritten by Bennett Dixon 2018.\nEnter a negative value to exit.\n");
  int intToConvert;

  while (intToConvert >= 0)
   {
      printf("Enter a number to convert: ");
      scanf("%d", &intToConvert); // scan our input into the address of our int in memory
      int response = PrintBitsFromInt(intToConvert);
      if (response == -1)
      {
        printf("Encountered an error while trying to parse number. Number was likely too large.\n");
      }
    }
  return 0;
}

int PrintBitsFromInt(int x)
{
  if (x > 32000)
  {
    return -1;
  }
  int thirtyThousands = 32678;
  int sixteenThousands = 16384;
  int eightThousands = 8192;
  int fourThousands = 4096;
  int twoThousands = 2048;
  int oneThousands = 1024;
  int fiveHundreds = 512;
  int twoHundreds = 256;
  int hundredTwentyEights = 128;
  int sixtyFours = 64;
  int thirtyTwos = 32;
  int sixteens = 16;
  int eights = 8;
  int fours = 4;
  int twos = 2;
  int ones = 1;


  int placesArray[arrSize] = { ones, twos, fours, eights, sixteens, thirtyTwos, sixtyFours, hundredTwentyEights, twoHundreds, fiveHundreds, oneThousands,
  twoThousands, fourThousands, eightThousands, sixteenThousands, thirtyThousands };

  for (size_t i = arrSize; i > 0; i--)
  {
    int intOfPlace = (int) placesArray[i - 1]; // need an int to apply binary opperand %
    // if our max place is divisible perfectly, return that
    if (i == 0 && x % intOfPlace == 0)
    {
      placesArray[i - 1] = 1; // set max place to 1 since there is 1 count of it
      placesArray[0] = 0; //since ones place defaults to one, set to 0 since perfect division
      return printNumBitsFromPlaceArray(placesArray);
    }

    double temporaryPlaceVal = x / intOfPlace;
    x = x % intOfPlace; // set x to the remainder of our divison above

    int response = getPlaceValueFromInt(temporaryPlaceVal); // get 1, 0, or -1 for error
    if (response == -1)
    {
      return -1;
    }

    placesArray[i - 1] = response;  // set to 1 or 0
  }

  return printNumBitsFromPlaceArray(placesArray);
}

// -1 for out of place error, 0 and 1 are normal results
int getPlaceValueFromInt(double place)
{
  if (place > 2)
  {
    return -1;
  }
  else if (place >= 1 && place <= 2)
  {
    place = 1; // found one 64, rest is less than this since its not 2
  }
  else if (place < 1)
  {
    place = 0;
  }
  return place;
}

int printNumBitsFromPlaceArray(int arr[])
{
  printf("BitRepresentation: ");
  for (size_t i = arrSize; i > 0; i--) {
    if (arr[i - 1] > 1) // still set to default like 2, 4, 8, 16, 32, 64, etc
    {
      arr[i - 1] = 0; // set to 0 (actual default)
    }
    printf("%d", arr[i - 1]);
  }
  printf("\n");
  return 0;
}
