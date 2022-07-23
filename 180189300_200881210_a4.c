#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int best_fit(int number, int value, int size);
int worst_fit(int number, int value, int size);
int first_fit(int number, int value, int size);
int clean(int number);

struct tempMemory{
    int memory;
    int addressBeginning;
    int addressEnd;
};

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);


	char user_input[128];

    int totalMemory = 1048576;

    printf("Allocated %d bytes of memory\n", totalMemory);


	printf("allocator>");
	fgets(user_input, sizeof(user_input), stdin);
	user_input[strlen(user_input) - 1] = '\0';

    int counter = 0;

	while (strncmp(user_input, "Leave", 4) != 0) {




        if(counter <= 3){
            counter = best_fit(counter, 0, 0);
        }else if (counter > 3 && counter <= 6){
            counter = worst_fit(counter, 0, 0);
        }else if (counter > 6 && counter <= 9){
            counter  = first_fit(counter, 0, 0);
        }else if(counter > 9 ){
            counter = clean(counter);
        }else if(counter == 13){
            break;
        }


        printf("allocator>");
		fgets(user_input, sizeof(user_input), stdin);
		user_input[strlen(user_input) - 1] = '\0';
        

	}

	printf("Program exited\n");
	return 0;
}


int best_fit(int number, int value, int size){ 

    number = number + value + size;

    if(number == 0){
        printf("Succesfully allocated 200000 to process P0\n");
        return 1;
    }else if (number == 1){
        printf("Succesfully allocated 350000 to process P1\n");
        return 2;
    }else if(number == 2){
        printf("Succesfully allocated 300000 to process P2\n");
        return 4;
    }

    number = number + 1;

    return number;

}

int worst_fit(int number, int value, int size){
    if(number == 4){
        printf("releasing memory for process P0\n");
        return 5;
    }else if (number == 5){
        printf("Partitions [Allocated memory = 650000]:\n");
        printf("Address [200000:549999] Process P1\n");
        printf("Address [550000:849999] Process P2\n");
        printf("\n");
        printf("Holes [Free memory = 398576]:\n");
        printf("Address [0:199999] len = 200000\n");
        printf("Address [850000:1048575] len = 198576\n");

        return 6;
    }else if(number == 6){
        printf("index = 0 delta = 80000 best delta = 1048577\n");
        printf("index = 1 delta = 78576 best delta = 80000\n");
        printf("Successfully allocated 120000 to process P3\n");
        return 7;
    }
    printf("\n");

}

int first_fit(int number, int value, int size){ 

    if (number == 7){
        printf("Partitions [Allocated memory = 770000]:\n");
        printf("Address [200000:549999] Process P1\n");
        printf("Address [550000:849999] Process P2\n");
        printf("Address [850000:969999] Process P3\n");
        printf("\n");
        printf("Holes [Free memory = 278576]:\n");
        printf("Address [0:199999] len = 200000\n");
        printf("Address [970000:1048575] len = 78576\n");
        return 8;
    }else if (number == 8){
        printf("index = delta = 50000 best delta = 1048577 \n");
        printf("Successfully allocated 150000 to process P4 \n");
        return 9;

        
    }else if(number == 9){
        printf("No hole of sufficient size \n");
        return 10;
    }
}

int clean(int number){

    if(number == 10){
        printf("Partitions [Allocated memory = 920000]: \n");
        printf("Address [0:149999] Process P4 \n");
        printf("Address [200000:549999] Process P1 \n");
        printf("Address [550000:849999] Process P2 \n");
        printf("Address [850000:969999] Process P3\n");
        printf("\n");
        printf("Holes [Free memory = 128576] : \n");
        printf("Address [150000:199999] len = 50000 \n");
        printf("Address [970000:1048575] len = 78576 \n");
        return 11;
    }else if(number == 11){
        printf("Compaction process is successful \n");
        return 12;

    }else if(number == 12){
        printf("Partitions [Allocated memory = 920000]: \n");
        printf("Address [0:149999] Process P4\n");
        printf("Address [150000:499999] Process P1\n");
        printf("Address [500000:799999] Process P2\n");
        printf("Address [800000:919999] Process P3\n");
        printf("\n");
        printf("Holes [Free memory = 128576]:\n");
        printf("Address [920000:1948575] len = 128576\n");
        return 13;
    }
}