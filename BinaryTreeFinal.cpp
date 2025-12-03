#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <limits> 

using namespace std;

int TreeSize, Height;

int* allocateMemoryOfArray() {
    printf("\n===============================================================\nEnter the desired height of the binary tree : ");
    int maxLevel;
    if (scanf("%d", &maxLevel) != 1 || maxLevel < 2) {
        printf("\n===============================================================\nInvalid input. Please enter a valid number between 2 and 6.\n");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return nullptr;
    }
    
    Height = maxLevel;
    TreeSize = (1 << Height) - 1; 
    int* BTArray = (int*)calloc(TreeSize, sizeof(int));
    
    if (BTArray == nullptr) {
        printf("!!!!!   Memory allocation failed.\n");
        return nullptr;
    }
    return BTArray;
}


bool* OccupiedElementInArray() {
    bool* OccupiedArray = (bool*)calloc(TreeSize, sizeof(bool));
    if (OccupiedArray == nullptr) {
        printf("!!!!!  Memory allocation for occupied array failed.\n");
        return nullptr;
    }
    return OccupiedArray;
}


void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}


void display(int Array[], bool logic[]) {
    int nodeIndex = 0;
    int maxWidth = (1 << (Height - 1)) * 4 - 1;

    for (int level = 0; level < Height; level++) {
        int nodeInLevel = 1 << level;
        int spaceBetweenNodes = maxWidth / nodeInLevel;
        int leadingSpaces = spaceBetweenNodes / 2;

        printSpaces(leadingSpaces);

        for (int i = 0; i < nodeInLevel; i++) {
            if (!logic[nodeIndex]) {
                printf("x"); 
            } else {
                printf("%d", Array[nodeIndex]);
            }
            nodeIndex++;

            if (i < nodeInLevel - 1) {
                printSpaces(spaceBetweenNodes);
            }
        }
        printf("\n");
    }
}
void display2(int BTArray[], bool LogicArray[]){
    int nodeIndex = 0;
    int maxWidth = (1 << (Height - 1)) * 4 - 1;

    for (int level = 0; level < Height; level++) {
        int nodeInLevel = 1 << level;
        int spaceBetweenNodes = maxWidth / nodeInLevel;
        int leadingSpaces = spaceBetweenNodes / 2;

        printSpaces(leadingSpaces);

        for (int i = 0; i < nodeInLevel; i++) {
            if (!LogicArray[nodeIndex]) {
                printf("x"); 
            } else {
                printf("%d", BTArray[nodeIndex]);
            }
            nodeIndex++;

            if (i < nodeInLevel - 1) {
                printSpaces(spaceBetweenNodes);
            }
        }
        printf("\n");
    }
}

void binaryTreeInsert(int BTArray[], bool LogicArray[], int data) {
    for (int i = 0; i < TreeSize; i++) {
        if (!LogicArray[i]) {
            BTArray[i] = data;
            LogicArray[i] = true;
            break;
        }
    }
}
int binaryTreeInsert(int BTArray[], bool LogicArray[]) {
    int data;
    printf("\n===============================================================\nEnter data to insert: ");
    if (scanf("%d", &data) != 1) {
        printf("!!!!! Invalid input! Please enter a valid number.\n");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }
    else if (data > 99 || data < -99){
        printf("\n===============================================================\n");
        printf("Invalid input! Please enter a number less than 100 and enter a number more than -100.\n\n\n");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }
     else {
        binaryTreeInsert(BTArray, LogicArray, data);
    }
    return 0;
}
void binaryTreeDelete(int BTArray[], bool LogicArray[], int data) {
    for (int i = 0; i < TreeSize; i++) {
        if (LogicArray[i] && BTArray[i] == data) {
            BTArray[i] = '\0';
            LogicArray[i] = false;
            break;
        }
    }
}


int binaryTreeDelete(int BTArray[], bool LogicArray[]) {
    int data;
    printf("Enter the number to delete : ");
    if (scanf("%d", &data) != 1) {
        printf("!!!!!   Invalid input! Please enter a valid number.\n");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    } else {
        binaryTreeDelete(BTArray, LogicArray, data);
    }
    return 0;
}

int main() {
    int* BTArray;
    bool* LogicArray;
    
    do {
        BTArray = allocateMemoryOfArray();
    } while (BTArray == nullptr);
    
    LogicArray = OccupiedElementInArray();
    
    printf("Binary Tree Created:\n");
    display(BTArray, LogicArray);
    
    int select = 0;
    while (true) {
        printf("Select function: insert(1), delete(2), exit(3): ");
        
        if (scanf("%d", &select) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        

        switch (select) {
            case 1:
                do {
                } while (binaryTreeInsert(BTArray, LogicArray));
                display(BTArray, LogicArray);
                break;
            case 2:
                do {
                } while (binaryTreeDelete(BTArray, LogicArray));
                display(BTArray, LogicArray);
                break;
            case 3:
                printf("Exiting program.\n");
                free(BTArray);  
                free(LogicArray);
                return 0;
            default:
                printf("Invalid selection! Please choose 1, 2, or 3.\n");
        }
    }
    
    return 0;
}