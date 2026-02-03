#include <stdio.h>

int main() {
    double result, num;
    char op;

    printf("Enter calculation (e.g. 121+232-5): ");

    //รับเลขตัวแรกและกรองข้อผิดพลาด
    if (scanf("%lf", &result) != 1) {
        printf("Error: Please start with a number.\n");
        return 1;
    }

    //วนลูปรับเครื่องหมายและตัวเลขต่อไปเรื่อยๆ
    while (1) {
        // รับเครื่องหมายการคำนวณ
        scanf("%c", &op);

        //กด Enter ให้จบการทำงาน
        if (op == '\n') {
            break; 
        }
        // รับตัวเลขตัวถัดไป
        scanf("%lf", &num);

        // คำนวณสะสมค่าไปเรื่อยๆ 
        switch (op) {
            case '+': 
                result += num; 
                break;
            case '-': 
                result -= num; 
                break;
            case '*': 
                result *= num; 
                break;
            case '/': 
                if (num == 0) {
                    printf("\nError: Divide by Zero\n");
                    return 1;
                }
                result /= num; 
                break;
            case '%':
                // % ใช้กับทศนิยมไม่ได้ ต้องแปลงเป็น int ก่อน
                 if ((int)num == 0) {
                    printf("\nError: Divide by Zero\n");
                    return 1;
                }
                result = (int)result % (int)num;
                break;
            default:
                // กรองหมายแปลกๆ
                printf("\nError: Unknown operator '%c'\n", op);
                return 1;
        }
    }

    // แสดงผลลัพธ์เป็นทศนิยม 2 ตำแหน่ง
    printf("Result = %.2f\n", result);

    return 0;
}