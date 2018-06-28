/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Quanah
 *
 * Created on March 22, 2017, 5:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */ 

struct listNode{
    char data;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr;

int main(int argc, char** argv) {
    
    ListNodePtr startPtr = NULL;
    insert(&startPtr, 'D');
    printList(startPtr);
    
    printf("\n");
    
    insert(&startPtr, 'Q');
    printList(startPtr);
    
    printf("\n");
    
    delete(&startPtr, 'D');
    printList(startPtr);
    
    printf("\n");
    
    insert(&startPtr,'T');
    insert(&startPtr,'7');
    insert(&startPtr,'P');
    insert(&startPtr,'3');
    //delete(&startPtr,'Q');
    printList(startPtr);

    return (EXIT_SUCCESS);
}
void delete(ListNodePtr *sPtr, char value){  
    
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;
    
    if(value == (*sPtr)->data){
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);    
        //return value;
    }
    else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;
        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;
        }
        if(currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            //return value;
        }
    }
    //return '\0';
}
void insert(ListNodePtr *sPtr, char value){
    
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    newPtr = malloc( sizeof(ListNode));
    if(newPtr != NULL){
        
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *sPtr;
        
        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(previousPtr == NULL){
            
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
            
        }
        else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else{
        printf("%c not inserted. No memory \n", value);
    }
}
void printList(ListNodePtr currentPtr){
    if(isEmpty(currentPtr)){
        puts("List is empty. \n");
    }
    else{
        puts("The List is: ");
        
        while(currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL \n");
    }
}
int isEmpty(ListNodePtr sPtr){
    
    return sPtr == NULL;
    
}

