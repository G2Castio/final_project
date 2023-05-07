#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME_SIZE 50
#define PASSWORD_SIZE 50
#define FILENAME "login_data.txt"

void register_user(const char *username, const char *password) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Fail to read the data\n");
        exit(1);
    }
    
    fprintf(file, "%s %s\n", username, password);
    fclose(file);
}

int login(const char *username, const char *password) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Fail to read the data\n");
        exit(1);
    }

    char stored_username[USERNAME_SIZE];
    char stored_password[PASSWORD_SIZE];

    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(username, stored_username) == 0 &&
            strcmp(password, stored_password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}


int main() {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    int cmd=299;
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("|     CMD    | function                             |\n");
    printf("+---------------------------------------------------+\n");
    printf("|      1     | for register a new account           |\n");
    printf("+---------------------------------------------------+\n");
    printf("|      2     | for login                            |\n");
    printf("+---------------------------------------------------+\n");
    printf("|      0     | end the register&login system        |\n");
    printf("+---------------------------------------------------+\n");
    printf("| other cmds | the system will reply \"wrong cmd!!\"  |\n");
    printf("+---------------------------------------------------+\n");
    printf("\n");
    while(cmd != 0 ){
		printf("CMD Mode... <-<< Status:Reading >>-> :");
        scanf("%d",&cmd);
       //scanf("%d",&switchline);
        printf("cmd[%d]\n",cmd);
        if(cmd==1){
	  	  printf("Registration:\nUsername:");
    	  scanf("%s", username);
          printf("Password:");
          scanf("%s", password);
          register_user(username, password);
          printf("Registration complete\n");
		}else if(cmd==2){
    	  printf("Login:\nUsername:");
          scanf("%s", username);
          printf("Password:");
          scanf("%s", password);
          if (login(username, password)) {
          	printf("Sign in suceesfully!\n");
    	  } else {
        	printf("Failed to log in!\nPlease check the Username&Password again.\n");
    	  }
		}else{
	  		printf("wrong cmd!!\n");
		}
	}
	return 0;
}
