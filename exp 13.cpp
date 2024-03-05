#include <stdio.h>
#include <string.h>

char input[100];
int i;

int E();
int EP();
int T();
int TP();
int F();

int main(void)
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
    printf("\nEnter the string to be checked:");
    
    fgets(input, sizeof(input), stdin);
    
    if (E() && input[i] == '\0')
        printf("\nString is accepted");
    else
        printf("\nString is not accepted");

    return 0;
}

int E()
{
    if (T() && EP())
        return 1;
    else
        return 0;
}

int EP()
{
    if (input[i] == '+')
    {
        i++;
        if (T() && EP())
            return 1;
        else
            return 0;
    }
    else
        return 1;
}

int T()
{
    if (F() && TP())
        return 1;
    else
        return 0;
}

int TP()
{
    if (input[i] == '*')
    {
        i++;
        if (F() && TP())
            return 1;
        else
            return 0;
    }
    else
        return 1;
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E() && input[i] == ')')
        {
            i++;
            return 1;
        }
        else
            return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }
    else
        return 0;
}

