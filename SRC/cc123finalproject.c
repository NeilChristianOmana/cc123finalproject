#include <stdio.h>
#include <string.h>

struct Event {
    char title[100];
    int day;
    int month;
    int year;
    int hours;
    int minutes;
};

struct Event events[1000];
    int count = 0;

void addEvent(struct Event *eventsptr) {
    printf("Enter the Event: ");
    scanf(" %[^\n]", eventsptr -> title);
    
    printf("Date (Day Month Year): ");
    scanf("%d %d %d", &eventsptr->day, &eventsptr->month, &eventsptr->year);

    printf("Time (24hrs Format) (Hours Minutes): ");
    scanf("%d %d", &eventsptr ->hours, &eventsptr->minutes);

    for (int i = 0; i < count; i++) {
        if (events[i].day == eventsptr ->day &&
            events[i].month == eventsptr->month &&
            events[i].year == eventsptr ->year &&
            events[i].hours == eventsptr->hours &&
            events[i].minutes == eventsptr->minutes) {
            printf("There is a Conflict detected with: %s\n", events[i].title);
        }
    }
    events[count++] = *eventsptr;
    printf("The New Event is Added. \n");
 }
 void viewEvents() {
    for (int i = 0; i < count; i++) {
        printf("%02d/%02d/%04d - %02d:%02d - %s\n",
               events[i].day, events[i].month, events[i].year,
               events[i].hours, events[i].minutes, events[i].title);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n1. Add Event\n2. View Events\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) { 
            addEvent(&events[count]);
        } else if (choice == 2) {    
            viewEvents();
        } else if (choice == 3) {
            return 0;
        } else {
            printf("Your Choice is Invalid. Please Try again.\n");
        }
        
    }
}