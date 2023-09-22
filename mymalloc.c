#include <stdio.h>
char mainMemory[25000] = {0};
int isInitialized = 0;



void *MyMalloc(size_t bSize){
    //return if requested memory block's size is greater than 25000
    if(bSize > 25000){
        return NULL;
    }

    int blockSize = (int)bSize;

    // initilaize at first fun
    if(!isInitialized){ 
        isInitialized = 1;
        *mainMemory = -1;
        *(int *)(mainMemory + 1) = 0;
    }

    int size = *(int *)(mainMemory + 1);
    char *currentAddress = mainMemory;

    //traverse through the array until a suitable position is found or end of the array
    while(mainMemory + 25000 - currentAddress >= (blockSize + 5)){
        //jump to skip memoryblocks that are being used by user
        currentAddress = currentAddress + size + sizeof(size) + 1;
        char *tempAddress = currentAddress;

        //after jumping, check whether next location is also an allocated memory location, 
        //if not check whether memory block is big enough
        int count = 1;
        while(*currentAddress == 0 && count < blockSize + 5){
            currentAddress++;
            count++;
        }

        //if another allocated memory block is found, jump to the end of that block
        if(*currentAddress != 0){
            
            size = *(int *)(currentAddress + 1);


        //otherwise allocate block and return the pointer
        }else{
            *tempAddress = -1;
            tempAddress++;
            *(int *)tempAddress = blockSize;
            tempAddress += 4;
            return (void *)tempAddress;
        }
    }

    //if the program reached this point, that means no space is avialble for curretn request
    return NULL;

}

void MyFree(void *blockStart){
    //return on null pointers
    if(blockStart == NULL) return;

    //clear the all the 5 padding bytes and data bytes to reset the memory block
    char* block = (char *)(blockStart - 5);
    int size =  *(int *)(block + 1);
    for(int i = 0; i < size + 5; i++){
        *(char *)(block + i) = 0;
    }


}

