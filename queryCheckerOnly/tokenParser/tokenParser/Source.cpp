#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h"


// This program is basic implementation of hashmap and to check whether a given query is valid(whether it follows grammer) or not!!

typedef struct Pair {
	char data[50];
	char key[40];
	struct Pair* next;
	
}Pair;


int size = 6;
Pair** array = (Pair**)malloc(size*sizeof(Pair*));


int getValue(char c){

	return c - '0';

}

int hashCode(char* key) {

	int i = 0;
	int result = 0;
	for (i = 0; key[i] != '\0'; i++){

		result += getValue(key[i]);

	}

	return result % size;
}

char* search(char* key) {

	int hashIndex = hashCode(key);

	Pair* node = array[hashIndex];

	while (node != NULL) {

		if (stringCompare(node->key, key) == 0)
			return node->data;

		else
			node = node->next;
	}

	return NULL;
}


char* getString(char* str,int* index){

	int iter = 0;
	char* temp = (char*)malloc(20 * sizeof(char));

	while (str[*index] == ' '){
		(*index)++;
	}

	while (str[*index] != '\0' && str[*index] != ' '){
	
		temp[iter] = str[*index];
		iter++;
		(*index)++;

	}
	temp[iter] = '\0';

	
	return temp;
}




void insert(char* key, char* data) {

	Pair *item = (Pair*) malloc(sizeof(Pair));
	stringCopy(item->data, data);
	stringCopy(item->key, key);
	item->next = NULL;

	
	int hashIndex = hashCode(key);
	
	Pair* node = array[hashIndex];
	
	if (node == NULL){

		array[hashIndex] = item;
	}
	else{

		while ((node != NULL)){
			
			if ((stringCompare(node->key, item->key) == 0)){

				printf("\nDuplicate key, %s exists in hashmap with value %s",node->key,node->data);
				break;
			}
				
			node = node->next;

		}
		item -> next = node;

		node = item;

	}

}



bool isSpecial(char* str){

	bool flag1 = false;
	bool flag2 = false;

	int len = getLength(str);

	if (str[0] == '{' && str[len - 1] == '}')
		return true;

	return false;

}

void parse(char* str, char* query){

	int i = 0;
	int j = 0;

	
	int len1 = getLength(str);
	int len2 = getLength(query);


	while (i<len1 && j<len2){

		char* compare1 = getString(str, &i);
		char* compare2 = getString(query, &j);


		if (isSpecial(compare1))		
			insert(compare1, compare2);
		

		else{

			if (stringCompare(compare1, compare2) != 0){

				printf("\nError is at word : %s", compare2);
				break;
			}

		}

		free(compare1);
		free(compare2);
	}


	if (i >= len1 && j >= len2)
		printf("\nQuery follows Grammer\n");
		
	
	else{
		printf("\nQuery is Wrong\n");

		
	}

	for (j = 0; j < size; j++){
		array[j] = NULL;
	}

}




int main(void) {

	bool flag = false;
	int choice;
	int index = 0;
	char* key = (char*)malloc(10 * sizeof(char));
	char* data = (char*)malloc(10 * sizeof(char));
	char* str = "select {cn} from {dn} where {en} {fn} {gn} orderby {hn} having {in}";
	char* query = (char*)malloc(50 * sizeof(char));
	

	for (index; index < size; index++){

		array[index] = NULL;
	}

	
	do{

		welcomeMessage();
		printf("\nEnter Choice : ");
		scanf(" %d",&choice);
		flag = checkChoice(choice);


		if (flag){

			switch (choice){

				case 1 :
					printf("\nEnter Key : ");
					scanf(" %[^\n]", key);
					printf("\nEnter Value : ");
					scanf(" %[^\n]", data);
					insert(key, data);
					break;

				case 2:

					printf("\nEnter Key : ");
					scanf(" %[^\n]", key);
					printf("Value of Data at %s key is : %s",key,search(key));
					break;


				case 3:

					printf("\nEnter Query : ");
					scanf(" %[^\n]",query);
					parse(str,query);
					break;

				case 4:
					exit(0);
					break;
			}

		}

	} while (choice != 4);
	

}