# C-Mailbox-Manager_shared

## Overview

This project implements a simple email client simulation in C. It allows users to store, view, sort, search, and delete emails within a virtual mailbox. Each email contains a sender, receiver, subject, body, date received, and an auto-assigned ID. The project demonstrates proficiency in C programming, dynamic memory management, string handling, and menu-driven console applications.

---

## Technologies Used

* **Language:** C 
* **Memory Management:** Dynamic allocation
* **Data Structures:** Arrays of structs for emails, custom sorting and searching
* **Build System:** Makefile

---

## Key Features

**1. Email Database Initialization**

* Populates the mailbox with sample emails (up to 2000).
* Each email contains: sender, receiver, subject, body, and date.
* Assigns a unique ID to each email.

**2. Create Email**

* Adds a new email to the mailbox with all necessary fields.
* Increments mailbox size dynamically.

**3. Show Inbox**

* Displays all emails in tabular format with ID, sender, date, and subject.

**4. Show Email by ID**

* Allows user to view the full content of a single email by entering its ID.

**5. Sort Inbox by Sender**

* Sorts emails alphabetically by sender email address.

**6. Sort Inbox by ID**

* Sorts emails in ascending order by their assigned IDs.

**7. Keyword Search**

* Searches for a keyword in sender, subject, or body.
* Displays emails containing the keyword.

**8. Delete Email**

* Deletes an email based on its ID.
* Shifts remaining emails to fill the gap.

**9. Exit Inbox**

* Exits the program with a message.

---

## File Structure

* **main.c** – Contains the main function and launches the inbox menu.
* **email_client_support.h** – Header file defining structs, constants, and function prototypes.
* **email_client_support.c** – Implements all email-related functions.
* **Makefile** – Automates compilation and linking of the project.

---

## Running the Project

**Compile & Run:**

```bash
make
./project_email_client_support
```

**Clean Compilation Files:**

```bash
make clean
```

---

## Output Example

[View The Email Client Output](images/email_client_support%20Output%20Screenshot.pdf)