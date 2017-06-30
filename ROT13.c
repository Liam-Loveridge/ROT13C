#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// const for the size of the arrays 

const int SIZE = 1000; 
//Encryption function
void Enc(char *dataD)
{
    //Lookup table for the cipher
    char alphaI[52] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z', 'a', 'b', 'c', 'd','e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v','w', 'x', 'y', 'z'};
    char alphaO[52] = {'N', 'O', 'P', 'Q', 'R','S', 'T', 'U','V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};

    char dataE[SIZE] = {'\0'};
    int i, n; 

    for(i = 0; i < strlen(dataD); i++)
    {
        n = 0; 

        //Cipher only works with letters, so checks if it is a letter 
        if( (dataD[i] >= 65 && dataD[i] <= 90) || (dataD[i] >= 97 && dataD[i] <= 122))
        {
            //Performs a Linear Search to look for the index of the decrypted character;
            while(dataD[i] != alphaI[n])
            {
                n++;
            }

            //Substitues in the shifted letter
            dataE[i] = alphaO[n];
        }
        else
        {
            //If the character is not a letter it will just substitued in the character anyways
            dataE[i] = dataD[i]; 
        }
    }

    //Prints output
    printf("%s \n", dataE);

    return; 
}

//Decryption Function
void Dec(char *dataE)
{
    //Lookup table for the cipher
    char alphaI[52] = {'N', 'O', 'P', 'Q', 'R','S', 'T', 'U','V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
    char alphaO[52] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z', 'a', 'b', 'c', 'd','e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v','w', 'x', 'y', 'z'};

    char dataD[SIZE] = {'\0'}; 
    int i, n; 

    for(i = 0; i < strlen(dataE); i++)
    {
        n = 0; 

        //Cipher only works with letters, so checks if it is a letter 
        if( (dataE[i] >= 65 && dataE[i] <= 90) || (dataE[i] >= 97 && dataE[i] <= 122))
        {
            //Performs a Linear Search to look for the index of the decrypted character;
            while(dataE[i] != alphaI[n])
            {
                n++;
            }

            //Substitues in the shifted letter
            dataD[i] = alphaO[n];
        }
        else
        {
            //If the character is not a letter it will just substitued in the character anyways
            dataD[i] = dataE[i]; 
        }
    }

    //Prints output
    printf("%s \n", dataD);

    return; 
}

//main function 

int main()
{
    char inp[SIZE] = {'\0'};

    // Asks usr for input
    printf("Please enter message: "); 
    fgets(inp, SIZE, stdin);    
    inp[(strlen(inp) -1 )] = '\0'; 

    Dec(inp); 
    return 0; 
}