/* Design a bit-field structure that holds the following information:
Font ID: A number in the range 0-255
Font Size: A number in the range 0-127
Alignment: A number in the range 0-2 represented the choices Left, Center, and Right
Bold: Off(0) or on (1)
Italic: Off(0) or on (1)
Underline: Off(0) or on (1)
Use this structure in a program that displays the font parameters and uses a looped menu to let the user change parameters
The program should use the & operator an suitable masks to ensure that the ID and size entries aer converted to the specified range. */
#include<stdio.h>
#include<stdbool.h>

/* align type */
#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define SIZE_MASK 127
#define ID_MASK 255

const char * align[3] = {"left", "center", "right"};

struct font_props
{
    unsigned int id     :8;
    unsigned int size   :7;
    unsigned int        :1;
    unsigned int align  :2;
    bool bold           :1;
    bool italic         :1;
    bool underline      :1;
    unsigned int        :3;
};

void show_font(const struct font_props *);
void set_align(struct font_props *);
void set_size(struct font_props *);
void set_id(struct font_props *);
char get_choice(void);
char get_first(void);


int main(void)
{
    int choice;
    struct font_props font = {1, 12, LEFT, false, false, false};
    show_font(&font);
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'f':
                set_id(&font);
                break;
            case 's':
                set_size(&font);
                break;
            case 'a':
                set_align(&font);
                break;
            case 'b':
                font.bold = !font.bold;
                break;
            case 'i':
                font.italic = !font.italic;
                break;
            case 'u':
                font.underline = !font.underline;
                break;
            default:
                printf("Program error!\n");
                break;
        }
        show_font(&font);
    }
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    int ch;
    printf("f)change font    s)change size    a)change alignment\n");
    printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
    ch = get_first();
    while (ch != 'f' && ch != 's' && ch != 'a' && ch != 'b' && ch != 'i' && ch != 'u' && ch != 'q')
    {
        printf("Please respond with f, s, a, b, i, u, or q.\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n') continue;

    return ch;
}

void show_font(const struct font_props *pd)
{
    printf("  ID SIZE ALIGNMENT   B   I   U\n");
    printf("  %2u", pd->id);
    printf("%5u", pd->size);
    printf("%7s", align[pd->align]);
    printf("%8s", pd->bold == true ? "on": "off");
    printf("%4s", pd->italic == true ? "on": "off");
    printf("%4s", pd->underline == true ? "on": "off");
    printf("\n\n");
}

void set_align(struct font_props *pd)
{
    int ch;
    printf("Select alignment:\n");
    printf("l)left    c)center    r)right\n");
    ch = get_first();
    while (ch != 'l' && ch != 'c' && ch != 'r')
    {
        printf("Please respond with l, c or r.\n");
        ch = get_first();
    }

    switch (ch)
    {
        case 'l':
            pd->align = LEFT;
            break;
        case 'c':
            pd->align = CENTER;
            break;
        case 'r':
            pd->align = RIGHT;
            break;
        default:
            printf("Program error!\n");
            break;
    }
}

void set_size(struct font_props *pd)
{
    unsigned int n;
    int ch;
    printf("Enter font size (0-127): ");
    while (scanf("%u", &n) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 36, 54, 127: ");
    }
    while (getchar() != '\n') continue;

    n &= SIZE_MASK;
    pd->size = n;
}

void set_id(struct font_props *pd)
{
    unsigned int n;
    int ch;
    printf("Enter id (0-255): ");
    while (scanf("%u", &n) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 36, 54, 255: ");
    }
    while (getchar() != '\n') continue;

    n &= ID_MASK;
    pd->id = n;
}