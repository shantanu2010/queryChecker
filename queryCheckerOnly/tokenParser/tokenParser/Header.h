
void welcomeMessage(){

	printf("\n1.Insert");
	printf("\n2.search");
	printf("\n3.Query Checker");
	printf("\n4.Exit");

}

bool checkChoice(int num){

	if (num == 1 || num == 2 || num == 3 || num == 4)
		return true;

	return false;

}

int stringCompare(char* str1, char* str2){

	int i = 0;
	bool flag = false;

	for (i = 0; str1[i] != '\0'; i++){

		if (str1[i] == str2[i])
			continue;

		else{
			flag = true;
			break;
		}
	}
	if (flag)
		return -1;
	else
		return 0;

}

void stringCopy(char* destination, char* source){


	int i = 0;

	while (source[i] != '\0'){

		destination[i] = source[i];
		i++;

	}

	destination[i] = '\0';


}

int getLength(char* str){


	int index = 0;

	while (str[index] != '\0'){

		index++;
	}
	return index;
}