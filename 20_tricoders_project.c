#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ---------------- PERSON 1 ----------------

// Function to count characters
int countCharacters(char text[])
{
    int i = 0;

    while (text[i] != '\0')
    {
        i++;
    }

    return i;
}

// Function to count words
int countWords(char text[])
{
    int i;
    int words = 0;
    int inWord = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)text[i]))
        {
            if (inWord == 0)
            {
                words++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }
    }

    return words;
}

// ---------------- PERSON 2 ----------------

// Function to count vowels
int countVowels(char text[])
{
    int i;
    int vowels = 0;
    char ch;

    for (i = 0; text[i] != '\0'; i++)
    {
        ch = tolower((unsigned char)text[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u')
        {
            vowels++;
        }
    }

    return vowels;
}

// Function to count consonants
int countConsonants(char text[])
{
    int i;
    int consonants = 0;
    char ch;

    for (i = 0; text[i] != '\0'; i++)
    {
        ch = tolower((unsigned char)text[i]);

        if (isalpha((unsigned char)ch))
        {
            if (ch != 'a' && ch != 'e' && ch != 'i' &&
                ch != 'o' && ch != 'u')
            {
                consonants++;
            }
        }
    }

    return consonants;
}

// Function to find the longest word
void findLongestWord(char text[], char longest[])
{
    int i = 0;
    int j;
    int length;
    int maxLength = 0;
    char currentWord[500];

    longest[0] = '\0';

    while (text[i] != '\0')
    {
        // Skip spaces
        while (text[i] != '\0' &&
               isspace((unsigned char)text[i]))
        {
            i++;
        }

        j = 0;

        // Store the current word
        while (text[i] != '\0' &&
               !isspace((unsigned char)text[i]))
        {
            currentWord[j] = text[i];
            j++;
            i++;
        }

        currentWord[j] = '\0';
        length = j;

        // Check if current word is the longest
        if (length > maxLength)
        {
            maxLength = length;
            strcpy(longest, currentWord);
        }
    }
}

// ---------------- PERSON 3 ----------------

// Function to check whether input is empty or only spaces
int isEmpty(char text[])
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)text[i]))
        {
            return 0;
        }
    }

    return 1;
}

// Function to check palindrome
int checkPalindrome(char text[])
{
    int left = 0;
    int right = strlen(text) - 1;

    while (left < right)
    {
        // Ignore spaces
        while (left < right &&
               isspace((unsigned char)text[left]))
        {
            left++;
        }

        while (left < right &&
               isspace((unsigned char)text[right]))
        {
            right--;
        }

        // Ignore uppercase/lowercase
        if (tolower((unsigned char)text[left]) !=
            tolower((unsigned char)text[right]))
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

// ---------------- MAIN PROGRAM ----------------

int main()
{
    char text[500];
    char longest[500];
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          WORD & TEXT ANALYZER\n");
        printf("========================================\n");
        printf("1. Analyze Text\n");
        printf("2. Check Palindrome\n");
        printf("3. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid choice! Please enter a number.\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        // Remove newline left by scanf
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:

            printf("\nEnter a sentence: ");
            fgets(text, sizeof(text), stdin);

            // Remove newline
            text[strcspn(text, "\n")] = '\0';

            if (isEmpty(text))
            {
                printf("\nError: Input cannot be empty!\n");
                break;
            }

            findLongestWord(text, longest);

            printf("\n========================================\n");
            printf("          TEXT STATISTICS REPORT\n");
            printf("========================================\n");

            printf("Characters      : %d\n",
                   countCharacters(text));

            printf("Words           : %d\n",
                   countWords(text));

            printf("Vowels          : %d\n",
                   countVowels(text));

            printf("Consonants      : %d\n",
                   countConsonants(text));

            printf("Longest Word    : %s\n",
                   longest);

            if (checkPalindrome(text))
            {
                printf("Palindrome      : YES\n");
            }
            else
            {
                printf("Palindrome      : NO\n");
            }

            printf("========================================\n");

            break;

        case 2:

            printf("\nEnter a word or sentence: ");
            fgets(text, sizeof(text), stdin);

            text[strcspn(text, "\n")] = '\0';

            if (isEmpty(text))
            {
                printf("\nError: Input cannot be empty!\n");
                break;
            }

            if (checkPalindrome(text))
            {
                printf("\nResult: \"%s\" is a PALINDROME.\n",
                       text);
            }
            else
            {
                printf("\nResult: \"%s\" is NOT a PALINDROME.\n",
                       text);
            }

            break;

        case 3:

            printf("\nThank you for using Word & Text Analyzer!\n");
            break;

        default:

            printf("\nInvalid choice! Please select 1, 2 or 3.\n");
        }

    } while (choice != 3);

    return 0;
}