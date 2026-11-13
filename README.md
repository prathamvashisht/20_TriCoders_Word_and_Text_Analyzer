# Word and Text Analyzer

## C Programming Mini Hackathon

**Team Name:** TriCoders  
**Batch:** 20

### Team Members

| Name | SAP ID |
|---|---|
| Tushar Pahuja | 590032177 |
| Chahat | 590032461 |
| Pratham | 590032424 |

---

## Problem Statement

Develop a text analysis tool that processes a sentence entered by the user.

The program analyzes the entered text and generates useful statistics. It also checks whether the entered word or sentence is a palindrome while ignoring spaces and letter case where appropriate.

---

## Objectives

- To develop a text analysis program using C.
- To count characters and words in a sentence.
- To count vowels and consonants.
- To identify the longest word.
- To check whether a word or sentence is a palindrome.
- To correctly handle empty input and multiple spaces.
- To apply fundamental C programming concepts to a practical problem.

---

## Features

- Character counting
- Word counting
- Vowel counting
- Consonant counting
- Longest word identification
- Palindrome checking
- Case-insensitive palindrome checking
- Multiple-space handling
- Empty input validation
- Menu-driven interface

---

## Program Menu

```text
========================================
          WORD & TEXT ANALYZER
========================================
1. Analyze Text
2. Check Palindrome
3. Exit
========================================
```

### Option 1: Analyze Text
Accepts a sentence and displays a complete text statistics report.

### Option 2: Check Palindrome
Checks whether the entered word or sentence is a palindrome while ignoring spaces and letter case.

### Option 3: Exit
Terminates the program.

---

## Algorithm

1. Start the program.
2. Display the main menu.
3. Accept the user's choice.
4. If the user selects Analyze Text, accept a sentence.
5. Check whether the input is empty or contains only spaces.
6. Count the characters in the sentence.
7. Count the words.
8. Count vowels and consonants.
9. Find the longest word.
10. Check whether the text is a palindrome.
11. Display the complete text statistics report.
12. Return to the menu.
13. Exit when the user selects the Exit option.
14. Stop.

---

## Pseudocode

```text
START

Display Menu
Input choice

IF choice = 1
    Input text

    IF text is empty
        Display error
    ELSE
        Count characters
        Count words
        Count vowels
        Count consonants
        Find longest word
        Check palindrome
        Display statistics
    END IF

ELSE IF choice = 2
    Input text

    IF text is empty
        Display error
    ELSE
        Check palindrome
        Display palindrome result
    END IF

ELSE IF choice = 3
    Exit program

ELSE
    Display invalid choice

END IF

STOP
```

---

## C Programming Concepts Used

- Variables and data types
- Character arrays and strings
- Functions
- `
