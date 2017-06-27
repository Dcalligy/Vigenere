#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
        
    // key input from user
    string key = argv[1];
    int shift;
    int keylen;
    
    // get defensive
    if(argc != 2){
        
        printf("Invalid amount of arguments! Please try again.\n");
        return 1;
    }
    else{

    	for(int i = 0; i < strlen(key); i++){

    		if(!isalpha(argv[1][i])){
    			printf("INCORRECT CHARCTERS USED!\n");
    			return 1;
    		}
    	}
    }
    
    // get the length of the key 
    keylen = strlen(key);
    string plaintxt = get_string();// prompt user to input plaintext
    int j = 0;
    
    for(int i = 0; i < strlen(plaintxt); i++){
        // get key for letter
    	int letter = tolower(key[j % keylen]) - 'a';
    	
    	// preserve uppercase
    	if(isupper(plaintxt[i])){
    	    
    	    // get the remainder and shift letter to appropriate case
    		shift = ((plaintxt[i] - 'A' + letter) % 26) + 'A';
    		printf("%c", shift);
    		// increments j when used
    		j++;
    	}
    	// preserve lowercase
    	else if(islower(plaintxt[i])){
    	    
    	    // get remainder and shift letter to appropriate case
    		shift = ((plaintxt[i] - 'a' + letter) % 26) + 'a';
    		printf("%c", shift);
    		// increment j when used
    		j++;
    	}
    	else{
    	    
    	    // return plaintext
    		printf("%c", plaintxt[i]);
    	}
    }
    printf("\n");
    return 0;
}
