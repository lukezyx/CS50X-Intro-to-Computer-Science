from sys import argv, exit
import csv


#check if there are sufficient arguments
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit();

#Open sequence file

with open(argv[2]) as sequence_file:

    sequence = sequence_file.read() #this stores it into a string

#print(sequence)

#Open database file
with open(argv[1]) as database_file:

    database = csv.reader(database_file)

    #The following for loop is to separate out the DNA sequences (first row - AGATC, TATC, etc.)
    for row in database:

        dna_sequence_name = row
        dna_sequence_name.pop(0) #this is to remove the first entry of the row as is 'name'
        #i.e
        #'name', 'AGATC', 'AATG', 'TATC'
        #after pop(0), it removes the [0] (name) and becomes
        #'AGATC', 'AATG', 'TATC'

        break

dict = {}

#this to populate the dictionary where the genes are the keys
#output: dict = {AGATC: 0, AATG:0, etc.}
for name in dna_sequence_name:

    dict[name] = 0

#this is to iterate through the sequence, and if there is a consecutive match in the dna name, it will count
for name in dict:

    perm_count = 0 #counter for maximum number of times a dna name is found consecutively
    temp_count = 1 # temp count starts from 1 because of while loop below

    j = len(name)

    for i in range(len(sequence)):

        #this is to reset the temp_count
        #the for loop will iterate through the whole sequence given a number of dna names (AAGT, GATA, etc.)
        #after running through the sequence and searching for a dna name, it will reset the temp counter
        while temp_count > 1:
            temp_count -= 1
            continue

        if sequence[i : i + j] == name:

            while sequence[i-j:i] == sequence[i: i+j]:

                temp_count += 1
                i += j

            if temp_count > perm_count:

                perm_count = temp_count

    dict[name] = perm_count

#opens the database csv and read the names
with open(argv[1]) as who_file:
    who = csv.DictReader(who_file)

    for x in who:

        counter = 0

        for name in dna_sequence_name:

            #print("name " + x['name'])
            #print("dict name "+ str(dict[name]))

            if int(x[name]) == dict[name]:

                counter += 1

            if counter == len(dna_sequence_name):

                print(x['name'])

                exit(0)

    print("No Match")