import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Uso incorrecto.")


    # TODO: Read database file into a variable
    people = []
    subsequences = []


    # Obtaining headers


    with open(sys.argv[1]) as file:
        test = csv.reader(file)
        subsequences = next(test)
    # Obtaning every data from db


    with open(sys.argv[1]) as file:
        db = csv.DictReader(file)
        for row in db:
            people.append(row)


    # We delete "name" from headers
    subsequences.pop(0)


    # TODO: Read DNA sequence file into a variable


    with open(sys.argv[2],"r") as file:
        dna = file.read()
    # TODO: Find longest match of each STR in DNA sequence
    longest_list = {}
    for long in subsequences:
        longest = longest_match(dna,long)
        longest_list[long] = longest

        
    # TODO: Check database for matching profiles

    for i in range(len(people)):
        match = 0
        for adn in subsequences:
            if int(people[i][adn]) == int(longest_list[adn]):
                match += 1
        if match == len(subsequences):
            print(f"{people[i]['name']}")
        elif match != len(subsequences) and i == len(people)-1:
            print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
