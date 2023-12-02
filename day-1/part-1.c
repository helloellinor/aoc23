#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
	FILE *input;
	char ch;
	
	int answer = 0;
	bool newline = true;
	
	int calibration_value[2] = {0, 0};
	
	input = fopen("input.txt", "r");
	if (input == NULL) {
		perror("Cannot open provided file");
		return 1;
	}
	
	do {
		ch = fgetc(input);
		// Reject any characters that are not digits
		if ( ch >= '0' && ch <= '9') {
			int digit = ch - '0'; // Convert ASCII character to integer
			
			if (newline) {
				calibration_value[0] = digit;
				newline = false; 
			}
			
			// Continue to update the ones place until a newline is found
			calibration_value[1] = digit; 
		}
		else {
			if (ch == '\n' || ch == EOF) {
				newline = true;
				answer += ( calibration_value[0]*10 + calibration_value[1] );
				printf("%d%d", calibration_value[0], calibration_value[1]);
				printf("\n");
			}
		}
	} while (ch != EOF);
	
	fclose(input);
	
	printf("The answer is: %d", answer);
	
	return 0;
		
}