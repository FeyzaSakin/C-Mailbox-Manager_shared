#include <stdio.h>
#include "email_client_support.h"

int main() {
    struct Mailbox inbox;

    // Initialize mailbox and populate with emails
    initialize(&inbox);

    // Show the inbox menu (or directly call functions as needed)
    display_inbox_menu(&inbox);

    // Free allocated memory 
    return 0;
}