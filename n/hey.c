#include "stack.h"
#include <stdio.h>
#include "calculating.h"
#include <errno.h>

#define EXPR_LENGTH 1000

main()
{
    while (1)
    {
        Stack* nums = createEmptyStack();
        ValType lastval, prevval, result;
        char* temp = NULL, temp_char;
        char num_buf[NUM_LENGTH], expr_buf[EXPR_LENGTH];
        CalcErrors err_flag = NO_ERR;

        system("cls"); // clear the screen
        printf("Enter the expression: ");

        /* Transform the infix notation to the reverse Polish notation and processing the error if necessary */
        if (transformToRPN(expr_buf) != NO_ERR) {
            err_flag = WRONGSYM_ERR;
            goto break_loop;
        }

        temp = expr_buf; // to don't change the pointer expr_buf

        /* Parsing the operands from expression in the reverse Polish notation */
        while (temp_char = getOperand(num_buf, temp, &temp))
        {
            switch (temp_char) {
                /* Processing the operators */
            case SUB: case ADD: case MUL: case POW: case DIV:
                if (nums->size < 2) { // if operators are less than 2 (to avoid a pop() of empty stack)
                    err_flag = LACK_OPERAND;
                    goto break_loop; // break the nested loop
                }

                lastval = pop(nums); // last added operand
                prevval = pop(nums);

                result = useOperator(prevval, lastval, temp_char);

                if (errno || (!lastval && temp_char == DIV)) { // math errors (out of range, zero division etc)
                    err_flag = MATH_ERR;
                    goto break_loop; // break the nested loop
                }

                push(nums, result);
                break;

                /* Adding a value in the stack */
            case VAL:   push(nums, atof(num_buf));  break;
                /* End of input or other errors */
            case EQ:    err_flag = END_CALC;        goto break_loop;
            default:    err_flag = WRONGSYM_ERR;    goto break_loop;
            }
        }

    break_loop: // if input was incorrect, loop will be broken

        printf("\n");

        /* Processing the errors or displaying an answer */
        switch (err_flag) {
        case WRONGSYM_ERR:  printf(MSG_WRONGSYM); break;
        case MATH_ERR:          printf(MSG_MATH); break;
        case END_CALC:      nums->size == 1 ? printf("= %f\n", pop(nums)) : printf(MSG_LACKOP); break;
        case LACK_OPERAND:  printf(MSG_LACKOP); break; // FIX THE TEXT
        }

        printf("\nDo you want to calculate something else? y/n > ");

        getchar(); // skip the '\n' symbol
        temp_char = getchar();

        if (temp_char != 'y' && temp_char != 'Y')
            break;
    }
}
stack.h

#define ELEMENTARY_SIZE_STACK 5 // initial the length of stack
#define RESIZE_ADDING 5 /* how much will be add when the stack size 
                            will be equal to ELEMENTARY_SIZE */
#include <stdlib.h> 

#define ValType double
#define ValType_IOSPECIF "%lf"

typedef struct stack
{
    ValType* data;
    size_t max; // such value when the stack size should be extend
    size_t size;
} Stack;

Stack*      createEmptyStack(void);
void        push(Stack* s, ValType val);
void        deleteStack(Stack* st);
static void resize(Stack* st);
ValType     pop(Stack* st);
ValType     peek(Stack* st);
void        printStack(Stack* st);

#define MSG_MALLOC "ERROR! MALLOC RETURNS NULL!\n"
#define MSG_REALLOC "ERROR! REALLOC RETURN NULL!\n "
calculating.h

#include <float.h>

/* Errors processing */
typedef enum calcerr {
    NO_ERR,
    MATH_ERR,
    WRONGSYM_ERR,
    LACK_OPERAND,
    END_CALC
} CalcErrors;

#define MSG_WRONGSYM "ERROR! You entered the wrong symbol(s).\n"
#define MSG_LACKOP  "ERROR! The input format is not correct.\n"
#define MSG_MATH "ERROR! Math error!\n"

/* Operators, delimiters, other characters */
#define VAL 1
#define SUB '-'
#define ADD '+'
#define MUL '*'
#define DIV '/'
#define EQ '='
#define POW '^'
#define OP_BRACE '('
#define CL_BRACE ')'

#define DELIM_DOT '.'
#define DELIM_COMMA ','
#define IS_DELIM(x) ((x) == DELIM_DOT || (x) == DELIM_COMMA)

#define SPACE ' '

/* Priority of operators */
#define PRIOR_SUB 1                 
#define PRIOR_ADD 1
#define PRIOR_MUL 2
#define PRIOR_DIV 2
#define PRIOR_POW 3
#define PRIOR_OP_BR 0
#define PRIOR_CL_BR 0

#define PRIOR(x) getPriority(x)

/*Calculation and parsing expressions on the RPN (Reverse Polish Notation) */
int     getOperand(char* num, char expression[], char** end);
double  useOperator(double leftval, double rightval, char oper);

/*transform the infix notation to the reverse Polish notation*/
int         isOperator(char op);
static int  getPriority(char op);
CalcErrors  transformToRPN(char result[]); 

#define NUM_LENGTH DBL_DIG // maximum length of number
calculating.c

#include "calculating.h"
#include "stack.h"
#include <stdio.h>
#include <math.h>

/* Function for working with an expression on the RPN */

int getOperand(char* num, char expression[], char** end)
{
    unsigned counter = 0;
    char* ptr = expression;

    /* NULL pointer checking*/
    if (!ptr) return 0;

    /* Spaces skipping before */
    while (isspace(*ptr))
        ptr++;

    /* The unary minus checking */
    int negative_flag = 0;
    if (*ptr == SUB)
    {
        if (isdigit(*++ptr))   // if the next character is a digit
            negative_flag = 1;
        else
            ptr--;
    }

    /* The return of the any not digit character */
    if (!isdigit(*ptr))
    {
        *end = ++ptr;
        return *(ptr - 1);
    }

    /* Making a float number and the delimiter processing */
    while (isdigit(*ptr) || IS_DELIM(*ptr))
    {
        if (*ptr == DELIM_COMMA)
            *ptr = DELIM_DOT; // for atof()

        if (negative_flag)
        {
            num[counter++] = SUB;
            negative_flag = 0; // in order to add the minus symbol one time in the head of array
        }

        num[counter++] = *ptr;
        ptr++;
    }

    num[counter] = '\0';
    *end = ptr; // pointer to the next character (to continue reading an operand from a new location)
    return VAL;
}

double useOperator(double leftval, double rightval, char oper)
{
    double result;
    switch (oper) {
    case ADD: result = leftval + rightval; break;
    case SUB: result = leftval - rightval; break;
    case MUL: result = leftval * rightval; break;
    case DIV: result = leftval / rightval; break;
    case POW: result = pow(leftval, rightval); break;
    default: exit(1);
    }

    return result;
}

/* Function for working with an expression on the infix notation */

int getPriority(char ch) {
    switch (ch) {
    case SUB: return PRIOR_SUB;
    case ADD: return PRIOR_ADD;
    case MUL: return PRIOR_MUL;
    case DIV: return PRIOR_DIV;
    case POW: return PRIOR_POW;
    case OP_BRACE: return PRIOR_OP_BR; // opening parethesis
    case CL_BRACE: return PRIOR_CL_BR; // closing parethesis
    default: return -1;
    }
}

int isOperator(char x)
{
    return (x == SUB || x == ADD || 
            x == MUL || x == DIV || 
            x == POW);
}

CalcErrors transformToRPN(char result[])
{
    Stack* ops = createEmptyStack();
    char temp_ch;
    unsigned counter = 0;

    while ((temp_ch = getchar())) 
    { 
        /* Spaces skipping before */
        while (isspace(temp_ch))  
            temp_ch = getchar();

        /* Ending the input, fully write the remaining contents of stack*/
        if (temp_ch == EQ) 
        {
            while (ops->size)
            { 
                result[counter++] = (char)pop(ops);
                result[counter++] = SPACE;
            }
            result[counter++] = EQ;
            result[counter] = '\0';
            return NO_ERR;
        }

        /* Cheking the unary minus, and if it's not unary, return character after minus used to check back 
        and process a minus as an operator*/
        if (temp_ch == SUB)
        {
            temp_ch = getchar(); // read next symbol and if the next character is a digit
            if (isdigit(temp_ch)) { 
                if (temp_ch != '0') // to don't allow the '-0'
                    result[counter++] = SUB;
            }
            else {
                ungetc(temp_ch, stdin);
                temp_ch = SUB;
            }
        }

        /* Making a number */
        if (isdigit(temp_ch))
        {
            while (isdigit(temp_ch) || IS_DELIM(temp_ch) )
            { 
                result[counter++] = temp_ch;
                temp_ch = getchar();
            }   
            ungetc(temp_ch, stdin); // return the extra character
            result[counter++] = SPACE;
        }

        /* Else check the operator and push it to the stack */
        else 
        {
            if (isOperator(temp_ch)) 
            {
                if (!ops->size) // if stack is empty (to avoid an error after pop)
                    push(ops, (double)temp_ch);
                else 
                {
                    if (PRIOR(temp_ch) <= PRIOR((char)peek(ops))) // > if priority of new operator is higher than operator 
                    {                                             // in the top of stack, then the old operation will be
                        result[counter++] = (char)pop(ops);       // display and new operator push in the stack < 
                        result[counter++] = SPACE;
                    }

                    push(ops, (double)temp_ch);
                }
            }
            /* Operators inside parathesises processing */
            else if (temp_ch == OP_BRACE)
                push(ops, (double)temp_ch);
            else if (temp_ch == CL_BRACE)  // if it's a closing parethesis, then it write all of operators before the
            {                              // opening parethesis not including it
                char tmp;
                while ((tmp = (char)pop(ops)) != OP_BRACE) // until the opening parathesis
                {
                    result[counter++] = tmp;
                    result[counter++] = SPACE;
                }
            }
            /* Any other symbols */
            else  
                return WRONGSYM_ERR;
        }   
    }
}
stack.c

#include "stack.h"
#include <string.h>
Stack* createEmptyStack(void)
{
    Stack* st = malloc(sizeof(Stack));
    if (st == NULL) {
        printf(MSG_MALLOC);
        exit(EXIT_FAILURE);
    }

    st->data = malloc(sizeof(ValType)*ELEMENTARY_SIZE_STACK);
    if (st->data == NULL) {
        printf(MSG_MALLOC);
        exit(EXIT_FAILURE);
    }

    st->max = ELEMENTARY_SIZE_STACK; 
    st->size = 0;
    return st;
}

void deleteStack(Stack* st)
{
    free(st->data);
    free(st);
    st = NULL;
}

static void resize(Stack* st)
{
    st->max += RESIZE_ADDING;
    st->data = realloc(st->data, st->max*sizeof(ValType));
    if (st->data == NULL) {
        printf(MSG_REALLOC);
        exit(EXIT_FAILURE);
    }
}
