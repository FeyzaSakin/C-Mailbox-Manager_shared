# Makefile for the project
#

# Make environment
CC=gcc
CFLAGS= -c -g -Wall $(INCLUDES)


# Files
OBJECT_FILES = main.o email_client_support.o

# Productions
all : project_email_client_support

project_email_client_support : $(OBJECT_FILES)
	$(CC)  $(OBJECT_FILES) -o $@ 

main.o : main.c email_client_support.h
	$(CC) $(CFLAGS) $< -o $@

email_client_support.o : email_client_support.c email_client_support.h 
	$(CC) $(CFLAGS) $< -o $@

clean : 
	rm -v project_email_client_support $(OBJECT_FILES)