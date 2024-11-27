#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char event_name[20];
    Date date;
    char location[20];
} Event;

int main()
{
    Event event_FAST;

    printf("Enter the name of the event: ");
    fgets(event_FAST.event_name, sizeof(event_FAST.event_name), stdin);
    event_FAST.event_name[strcspn(event_FAST.event_name, "\n")] = '\0';
    printf("Enter the date of the event (dd-mm-yy): ");
    scanf("%d-%d-%d", &event_FAST.date.day, &event_FAST.date.month, &event_FAST.date.year);
    getchar();
    printf("Enter the location of the event: ");
    fgets(event_FAST.location, sizeof(event_FAST.location), stdin);
    event_FAST.location[strcspn(event_FAST.location, "\n")] = '\0';

    printf("\nPrinting all the details:\n");
    printf("Event name: %s\n", event_FAST.event_name);
    printf("Date of event: %d-%d-%d\n", event_FAST.date.day, event_FAST.date.month, event_FAST.date.year);
    printf("Location of the event: %s\n", event_FAST.location);

    return 0;
}
