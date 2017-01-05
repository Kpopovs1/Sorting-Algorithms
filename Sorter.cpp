#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Insertion Sort
void Sorter::insertionSortI() {
   int i, j, index;
   for(i=1; i<numElements; i++){
   		index = array[i];
   		j = i;
   		while((j>0) && (array[j-1] > index)){ 
   			array[j] = array[j-1];
   			j -= 1;
   		}
   		array[j]  = index;
   	}
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
   int i, j, k, min;
   for (i=0; i<numElements-1; i++){
   		k = i;
   		min = array[i];
   		for(j=i+1; j<numElements; j++){
   			if(array[j] < min){ 
   				k = j;
   				min = array[j];
   			}
   		}
   		array[k] = array[i];
   		array[i] = min;
   	}  
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
   int i, j;
   for(i = 0; i < numElements; i++){
   		for(j=0; j<numElements-1; j++){
   			if(array[j] > array[j+1]){
   				int tmp; 
   				tmp = array[j]; 
   				array[j] = array[j+1];
   				array[j+1] = tmp;
   			}
   		}
   	}
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() { 
    if(numElements > 1){
        
		numElements -= 1;
			
       	insertionSortR();

        int elem = array[numElements];  

       	int i = numElements-1;
 		
 		auxFuncInsertion(i, elem);

       	numElements += 1;
    }
}
 
// Recursive Selection Sort
void Sorter::selectionSortR() {  
    if(numElements>1){
       	
    	auxFuncSelection();
    	
		numElements -= 1;
		
       	selectionSortR();

       	numElements += 1;
    }
}
        
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
    if(numElements>1){  
          
       	numElements -= 1;
			
       	bubbleSortR();

       	int i = numElements-1;
 		
 		auxFuncBubble(i);

       	numElements += 1;
    }  
}

//auxiliary function for insertion sort
void Sorter::auxFuncInsertion(int i, int elem){
    
	if((i>=0) && (array[i]>elem)){
	
    	array[i+1] = array[i];
    	i--;
    	auxFuncInsertion(i, elem);
    	
    }else{
    	array[i+1] = elem;
    }
}

//auxiliary function for selection sort
void Sorter::auxFuncSelection(){ 

    int max=0, j=0, i=0;
    for(i=max; i<numElements; i++) {
        if(array[max] < array[i]) {
            max = i;
        }
    }
    
    j = array[numElements-1];
    array[numElements-1] = array[max];
    array[max] = j;

}

//auxiliary function for bubble sort
void Sorter::auxFuncBubble(int j){

	if(j>=0){
	
		if( array[j] > array[j+1] ){
		
			int tmp = array[j]; 
   			array[j] = array[j+1];
   			array[j+1] = tmp;
   			j--;
   			auxFuncBubble(j);
   		}
	}
}