#include "reminder.h"

void insert_to_calendar(int day, const char* value){
	if (day < 1 || day > November.month_days) {
		printf("day %d is invalid input\n", day);
		return;
	}

	strcpy(November.reminder_str[day-1], value);
	November.reminders[day-1] = true;
}

int read_reminder(char *str, int n){
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = '\0';
	//printf("here: <%s>\n", str);
	
	if (str[0] == '0') {
		return 0;
	}
	
	int counter = 0;
	char day[3], event[MAX_STR_LEN];
	while (str[counter] != ' ') {
		day[counter] = str[counter];
		counter++;
	}
	day[counter] = '\0';
	//printf("the day is <%s>\n", day);

	counter++;
	int i = 0;
	while (str[counter] != '\0') {
		event[i] = str[counter];
		counter++;
		i++;
	}
	event[i] = '\0';
	//printf("event: <%s>\n", event);
	insert_to_calendar(atoi(day), event);
	return 1;
}

void print_calendar(){
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n ");
	for (int i = 1; i < November.start_day; i++)
	    printf("     ");
	
	int counter;
	counter = November.start_day;
	for (int day = 1; day <= November.month_days; day++){
	    if (November.reminders[day-1] == false)
    	        printf(" %2d  ", day);
	    else
	        printf("(%2d) ", day);

	    if (counter % 7 == 0){
	        printf("\n ");
	    }
	    counter++;
	}
	printf("\n");
	printf("Reminders: \n");

	for (int i = 0; i < 31; i++){
		if (November.reminders[i] == true){
			printf("Day %d: %s\n", (i+1), November.reminder_str[i]); 
		}
	}
	printf("------------------------------\n");





}
