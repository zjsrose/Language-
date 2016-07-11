#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

char *concat(const char *s1, const char *s2){

	char *result = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if(result == NULL){
	
		printf("Error");
		exit(EXIT_FAILURE);
	}
	strcpy(result,s1);
	strcat(result,s2);

	return result;

}

int read_line(char str[], int n){

	char ch;
	int i = 0;

	while((ch = getchar())!= '\n')
		if(i < n)
			str[i++] = ch;

	str[i] = '\0';
	return i;
}

int main(){
	
	char *reminders[MAX_REMIND];
	char day_str[3], msg_str[MSG_LEN+1];
	int day, i, j, num_remind = 0;

	for(;;){
	
		if(num_remind == MAX_REMIND){
		
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder:");
		scanf("%2d",&day);
		if(day == 0)
			break;

		sprintf(day_str, "%2d", day);
		read_line(msg_str, MSG_LEN);

		for(i = 0; i < num_remind; i++)
			if(strcmp(day_str,reminders[i]) <0 )
				break;
		
		for(j = num_remind; j>i; j--)
			reminders[j] = reminders[j-1];

		reminders[i] = malloc(2 + strlen(msg_str) + 1);
		if(reminders[i] == NULL){
			printf("-- NO space left --\n");
			break;
		}
		
		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	
	}

	printf("\nDay Reminder\n");
	for(i = 0; i < num_remind; i++)
		printf("%s\n",reminders[i]);

	return 0;
}
