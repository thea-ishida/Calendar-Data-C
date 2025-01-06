/**
 * November Calendar Program
 *
 * This program allows users to manage and view reminders for the month of November.
 * Users can enter a day and a reminder description, and the program will store and
 * display each reminder on the respective day within a formatted calendar view.
 * By: Thea Ishida (tishida), student number: 251297414
 *
 * Note:
 * This program uses global variables to represent the month of November, and it assumes 
 * the maximum number of reminders is set for a month with 30 days.
 *
 * @return int Exit status of the program (0 for successful execution).
 */

#include "reminder.h"

struct Month November;


/**
 * The main function initializes the calendar for November, repeatedly accepts user reminders,
 * and prints the calendar with reminders until the user chooses to quit.
 *
 * @return An integer representing the program's exit status (0 for successful execution).
 *
 * This function performs the following steps:
 * 1. Allocates memory for a string `msg` to temporarily store user input for reminders.
 * 2. Sets the month-specific values in the global `November` structure:
 *    - `November.month_days` to 30, representing the total days in November.
 *    - `November.start_day` to 6, indicating that November starts on a Friday (if 1 = Sunday).
 * 3. Initializes the reminders array in `November`:
 *    - Each entry in `November.reminder_str` is set to an empty string.
 *    - Each entry in `November.reminders` is set to `false`, indicating no reminders are initially set.
 * 4. Enters a loop to accept reminders from the user:
 *    - Prompts the user to enter a day and reminder. If the user enters '0', the loop exits.
 *    - Calls `read_reminder` to parse the day and reminder text. If `read_reminder` returns 0, 
 *      the user entered '0', and the loop breaks to end the program.
 *    - Calls `print_calendar` to display the calendar, showing days with reminders highlighted.
 * 5. The program ends when the user enters '0' as the day, signaling to quit.
*/

int main(){
	char * msg;
	msg = (char *)malloc(MAX_STR_LEN * sizeof(char));

	November.month_days = 30;
	November.start_day = 6;
	for (int i = 0; i < 31; i++){
		November.reminder_str[i][0] = '\0';
		November.reminders[i] = false;
	}
	
	
	while(1) {
		printf("Enter day and reminder (0 to quit): ");
		if (read_reminder(msg, MAX_STR_LEN) == 0) {
			break;
		}
		print_calendar();	
 
	}


	

	return 0;
}